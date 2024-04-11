/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
int n,m,a,b;
int par[205];
struct edge{
	int x,y,g,s;
};
vector<edge>E;
vector<pair<int,pair<int,int> > >T;
int find(int x){
	return x==par[x]?x:par[x]=find(par[x]);
}
bool unite(int x,int y){
	x=find(x);y=find(y);
	if(x==y)return 0;
	par[find(x)]=find(y);
	return 1;
}
int add(int x,int y,int cost){
	for(int i=1;i<=n;i++)par[i]=i;
	auto newT=T;newT.clear();
	int ret=0;
	for(auto e:T){
		if(e.first>=cost){
			if(unite(x,y))newT.push_back(make_pair(cost,make_pair(x,y)));
		}
		if(unite(e.second.first,e.second.second)){
			newT.push_back(e);
		}
	}
	if(unite(x,y))newT.push_back(make_pair(cost,make_pair(x,y)));
	for(auto e:newT)ret=max(ret,e.first);
	T=newT;return newT.size()==n-1?ret:-1; 
}
bool cmp(edge e1,edge e2){
	return e1.g<e2.g;
}
signed main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	n=getint();m=getint();a=getint();b=getint();
	for(int i=1;i<=m;i++){
		int x=getint(),y=getint(),g=getint(),s=getint();
		E.push_back((edge){x,y,g,s});
	}
	sort(E.begin(),E.end(),cmp);
	int ans=9e18;
	for(auto e:E){
		int val=add(e.x,e.y,e.s);
		if(val>=0)ans=min(ans,val*b+e.g*a);
	}
	cout<<(ans<=5e18?ans:-1ll)<<endl;
	return 0;
}