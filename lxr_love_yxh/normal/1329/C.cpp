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
int T;
int n,m,a[1<<21];
void func(int x){
	int l=x*2,r=x*2+1;
	if(a[l]==0&&a[r]==0){
		a[x]=0;return;
	}
	if(a[l]<a[r]){
		a[x]=a[r];func(r);
	}else{
		a[x]=a[l];func(l);
	}
}
bool check(int x,int dep=1){
	int l=x*2,r=x*2+1;
	if(a[l]==0&&a[r]==0){
		if(dep<=m)return false;
		else return true;
	}
	if(a[l]<a[r]){
		return check(r,dep+1);
	}else{
		return check(l,dep+1);
	}
}
vector<int>opr;
void del(int x){
	opr.push_back(x);func(x);
}
void solve(int ind,int dep){
	if(dep>m)return;
	while(check(ind,dep)){
		del(ind);
	}
	solve(ind*2,dep+1);
	solve(ind*2+1,dep+1);
}
signed main(){
	T=getint();
	while(T--){
		n=getint();m=getint();
		for(int i=1;i<(1<<n);i++)a[i]=getint();
		for(int i=(1<<n);i<(1<<n+1);i++)a[i]=0;
		solve(1,1);
		int ans=0;
		for(int i=1;i<(1<<m);i++){
			ans+=a[i];
		}
		putln(ans);
		for(auto t:opr)putint(t);put('\n');
		opr.clear();
	}
	clear();
	return 0;
}