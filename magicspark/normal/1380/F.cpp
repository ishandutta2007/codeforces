/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
namespace fastio{
    char in[100000];
    int itr=0,llen=0;
    char get(){
        if(itr==llen)llen=fread(in,1,100000,stdin),itr=0;
        if(llen==0)return EOF;
        return in[itr++];
    }
    char out[100000];
    int itr2=0;
    void put(char c){
        out[itr2++]=c;
        if(itr2==100000){
            fwrite(out,1,100000,stdout);
            itr2=0;
        }
    }
    int clear(){
        fwrite(out,1,itr2,stdout);
        itr2=0;
        return 0;
    }
    int getint(){
        int ret=0;char ch=get();
        if(ch=='-')return -getint();
        while (ch<'0'||ch>'9'){
            ch=get();if(ch=='-')return -getint();
        }
        while ('0'<=ch&&ch<='9'){
            ret=ret*10-48+ch;
            ch=get();
        }
        return ret;
    }
    string getstr(){
        string ret="";
        char ch=get();
        while(ch==' '||ch=='\n')ch=get();
        while(ch!=' '&&ch!='\n')ret.push_back(ch),ch=get();
        return ret;
    }
    void putstr(string s){
        for(int i=0;i<s.size();i++)put(s[i]);
    }
    void putint(int x){
        if(x<0){
            put('-');
            putint(-x);
            return;
        }
        if(x==0){
            put('0');put(' ');
            return;
        }
        char c[40];int pos=0;
        while(x){
            c[pos++]='0'+x%10;
            x/=10;
        }
        for(int i=pos-1;i>=0;i--)put(c[i]);
        put(' ');
    }
    void putln(int x){
        if(x<0){
            put('-');
            putln(-x);
            return;
        }
        if(x==0){
            put('0');put('\n');
            return;
        }
        char c[40];int pos=0;
        while(x){
            c[pos++]='0'+x%10;
            x/=10;
        }
        for(int i=pos-1;i>=0;i--)put(c[i]);
        put('\n');
    }
}
using namespace fastio;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=998244353;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
struct mat{
	int a[2][2];
	mat(){a[0][0]=1;a[0][1]=0;a[1][0]=0;a[1][1]=1;}
};
mat operator*(mat a,mat b){
	mat ret;
	memset(ret.a,0,sizeof ret.a);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				ret.a[i][j]+=a.a[i][k]*b.a[k][j];
				ret.a[i][j]%=mod;
			}
		}
	}
	return ret;
}
#define SIZE 524288
mat f[SIZE<<1];
void set_v(int x,mat y){
	x+=SIZE;f[x]=y;
	while(x!=1){
		x>>=1;f[x]=f[x<<1]*f[x<<1|1];
	}
}
int n,m;
int func(int x){
	return x+1;
}
int func(int x,int y){
	if(x==0)return 0;
	return max(0ll,19-x*10-y);
}
signed main(){
	n=getint();m=getint();
	string s=" "+getstr();
	for(int i=1;i<=n;i++){
		mat mt;
		mt.a[1][0]=1;mt.a[1][1]=0;
		mt.a[0][0]=func(s[i]-'0');
		if(i<n)mt.a[0][1]=func(s[i]-'0',s[i+1]-'0');
		else mt.a[0][1]=0;
//		cerr<<i<<endl;
//		cerr<<(mt*mat()).a[0][0]<<" "<<(mt*mat()).a[0][1]<<endl;
//		cerr<<(mt*mat()).a[1][0]<<" "<<(mt*mat()).a[1][1]<<endl;
//		cerr<<"-----"<<endl;
		set_v(i,mt);
	}
	while(m--){
		int x=getint(),c=getint();
		mat cur=f[x+SIZE];
		cur.a[0][0]=func(c);
		if(x<n)cur.a[0][1]=func(c,s[x+1]-'0');
		set_v(x,cur);
		if(x!=1){
			cur=f[x+SIZE-1];
			cur.a[0][1]=func(s[x-1]-'0',c);
			set_v(x-1,cur);
		}
		s[x]='0'+c;
		putln(f[1].a[0][0]);
	}
	clear();
	return 0;
}