/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
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
    template<class T>void putint(T x){
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
    template<class T>void putln(T x){
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
	struct Flusher_ {~Flusher_(){clear();}}io_flusher_;
}
using namespace fastio;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
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
int T,n,m;
int p[1005][1005],ip[1005][1005],id[1005],ans[1005][1005];
bool inv;
int l[1005],r[1005],u[1005],d[1005],val[1005],arr[1005];
struct Int{
	int x,y,z,c;
	Int(){x=y=z=c=0;}
	Int operator=(Int v){
		x=v.x;y=v.y;
		z=v.z;c=v.c;
	}
}f[100005][3];
int eval(Int a,int x,int y,int z){
	return a.x*x+a.y*y+a.z*z+a.c;
}
int main(){
	T=getint();
	while(T--){
		n=getint();m=getint();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				p[i][j]=getint();
			}
		}
		string s=getstr();
		f[0][0].x=1;f[0][1].y=1;f[0][2].z=1;
		for(int i=0;i<s.size();i++){
			if(s[i]=='I'){
				f[i+1][0]=f[i][0];
				f[i+1][1]=f[i][2];
				f[i+1][2]=f[i][1];
				continue;
			}
			if(s[i]=='C'){
				f[i+1][0]=f[i][2];
				f[i+1][1]=f[i][1];
				f[i+1][2]=f[i][0];
				continue;
			}
			for(int j=0;j<3;j++)f[i+1][j]=f[i][j];
			if(s[i]=='R'){
				f[i+1][1].c++;
			}
			if(s[i]=='L'){
				f[i+1][1].c--;
			}
			if(s[i]=='U'){
				f[i+1][0].c--;
			}
			if(s[i]=='D'){
				f[i+1][0].c++;
			}
		}
		int len=s.size();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int x=i,y=j,z=p[i][j];
				int xx=eval(f[len][0],x,y,z);
				int yy=eval(f[len][1],x,y,z);
				int zz=eval(f[len][2],x,y,z);
				xx%=n;yy%=n;zz%=n;
				xx+=n;yy+=n;zz+=n;
				xx%=n;yy%=n;zz%=n;
				if(xx==0)xx=n;
				if(yy==0)yy=n;
				if(zz==0)zz=n;
				ans[xx][yy]=zz;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				putint(ans[i][j]);
			}
			put('\n');
		}
		put('\n');
	}
	clear();
	return 0;
}