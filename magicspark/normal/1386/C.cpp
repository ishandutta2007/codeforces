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
#define rank magicspark
int n,m,q;
int par[400005],rank[400005],u[200005],v[200005],ans[200005];
stack<pair<int*,int> >stk;
int find(int x){
	return x==par[x]?x:find(par[x]);
}
bool same(int x,int y){
	return find(x)==find(y);
}
bool merge(int x,int y){
	x=find(x);y=find(y);
	if(rank[x]>rank[y])swap(x,y);
	stk.push(make_pair(&rank[y],rank[y]));
	rank[y]=max(rank[y],rank[x]+1);
	stk.push(make_pair(&par[x],par[x]));
	par[x]=y;
	return !same(x,x^1);
}
void rollback(){
	*stk.top().first=stk.top().second;stk.pop();
	*stk.top().first=stk.top().second;stk.pop();
}
void Rollback(){
	rollback();rollback();
}
bool Merge(int x,int y){
	bool vl=merge(x*2,y*2+1);
	bool vr=merge(x*2+1,y*2);
	return vl&&vr;
}
void solve(int l,int r,int a,int b){
	if(l>r)return;
//	cerr<<l<<" "<<r<<" "<<a<<" "<<b<<" "<<stk.size()<<endl;
	int mid=(l+r)/2;
	for(int i=l;i<=mid;i++){
		if(!Merge(u[i],v[i])){
			ans[mid]=m+1;
			for(int j=i;j>=l;j--)Rollback();
			for(int j=mid+1;j<=r;j++)ans[j]=m+1;
			solve(l,mid-1,a,b);
			return;
		}
	}
	int pos=b;
	while(pos>=a&&Merge(u[pos],v[pos])){
		pos--;
	}
	ans[mid]=pos;
	for(int i=pos;i<=b;i++)Rollback();
	solve(mid+1,r,pos,b);
	for(int i=l;i<=mid;i++)Rollback();
	for(int i=b;i>=pos+1;i--)if(!Merge(u[i],v[i])){
		for(int j=b;j>=i;j--)Rollback();
		for(int j=l;j<mid;j++)ans[j]=m+1;
		return;
	}
	solve(l,mid-1,a,pos);
	for(int i=b;i>=pos+1;i--)Rollback();
//	cerr<<l<<" "<<r<<" "<<a<<" "<<b<<" "<<stk.size()<<endl;
}
int main(){
	memset(ans,-1,sizeof ans);
	n=getint();m=getint();q=getint();
	for(int i=1;i<=m;i++){
		u[i]=getint();v[i]=getint(); 
	}
	for(int i=1;i<=n*2+1;i++)par[i]=i,rank[i]=1;
	solve(1,m,0,m);
	ans[0]=m;
	while(ans[0]>=1&&Merge(u[ans[0]],v[ans[0]]))ans[0]--;
//	for(int i=0;i<=m;i++)cerr<<ans[i]<<endl;
	while(q--){
		int l=getint(),r=getint();
//		cerr<<"here"<<endl;
		if(ans[l-1]>r)puts("YES");
		else puts("NO");
	}
	return 0;
}