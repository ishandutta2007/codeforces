/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
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
int n,q,arr[500005];
struct SGT{
	struct node {
		ll fg,s;
	}nd[1<<20];
	void upd(int p) {
		nd[p].s=min(nd[p+p].s,nd[p+p+1].s);
	}
	void setf(int p,ll v) {
		nd[p].fg+=v;
		nd[p].s+=v;
	}
	void build(int p,int l,int r) {
		nd[p].fg=0;
		if (l==r) {
			nd[p].s=arr[l];
		} else {
			int md=(l+r)>>1;
			build(p+p,l,md);
			build(p+p+1,md+1,r);
			upd(p);
		}
	}
	void push(int p) {
		if (nd[p].fg) {
			setf(p+p,nd[p].fg);
			setf(p+p+1,nd[p].fg);
			nd[p].fg=0;
		}
	}
	int _query(int p,int l,int r,int tl,int tr) {
		if (tl==l&&tr==r) return nd[p].s;
		else {
			push(p);
			int md=(l+r)>>1;
			if (tr<=md) return _query(p+p,l,md,tl,tr);
			else if (tl>md) return _query(p+p+1,md+1,r,tl,tr);
			else return min(_query(p+p,l,md,tl,md),_query(p+p+1,md+1,r,md+1,tr));
		}
	}
	void modify(int p,int l,int r,int tl,int tr,ll v) {
		if (tl>tr) return;
		if (tl==l&&tr==r) return setf(p,v);
		else {
			push(p);
			int md=(l+r)>>1;
			if (tr<=md) modify(p+p,l,md,tl,tr,v);
			else if (tl>md) modify(p+p+1,md+1,r,tl,tr,v);
			else modify(p+p,l,md,tl,md,v),modify(p+p+1,md+1,r,md+1,tr,v);
			upd(p);
		}
	}
	void add(int l,int r,int v){
		modify(1,1,n,l,r,v);
	}
	int query(int l,int r){
		return _query(1,1,n,l,r);
	}
}T;
vector<pair<int,int> >g[500005];
int L[500005],R[500005],dist[500005],dfs_clock;
void init(int x,int par){
	L[x]=++dfs_clock;
	assert(L[x]==x);
	for(auto p:g[x]){
		dist[p.first]=dist[x]+p.second;init(p.first,x);
	}
	R[x]=dfs_clock;
}
struct query{
	int l,r,id;
};
vector<query>ask[500005];
int ans[500005];
void dfs(int x,int par){
	for(auto Q:ask[x]){
		ans[Q.id]=T.query(Q.l,Q.r);
	}
	for(auto p:g[x]){
		T.add(L[p.first],R[p.first],-p.second*2ll);
		T.add(1,n,p.second);
		dfs(p.first,x);
		T.add(L[p.first],R[p.first],p.second*2ll);
		T.add(1,n,-p.second);
	}
}
signed main(){
	n=getint();q=getint();
	for(int i=2;i<=n;i++){
		int x=getint(),y=getint();
		g[x].push_back(make_pair(i,y));
	}
	for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
	init(1,-1);
	for(int i=1;i<=q;i++){
		int u=getint(),l=getint(),r=getint();
		ask[u].push_back((query){l,r,i});
	}
	for(int i=1;i<=n;i++)arr[i]=(g[i].size()==0?dist[i]:(ll)1e15);
	T.build(1,1,n);
	dfs(1,-1);
	for(int i=1;i<=q;i++)putln(ans[i]);
	clear();
	return 0;
}