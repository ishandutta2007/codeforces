/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
int n,q,p[500005],col[500005],dep[500005],l[500005],r[500005],pos[500005],tot;
vector<pair<int,int> >g[500005];
vector<pair<int,int> >E;
const int maxn=1e6; 
const int B=256;
struct LCA{
	int n,q;
int a[maxn],dfn[maxn],tot;
	int st[15][maxn / B + 1];
	int pre[maxn + B], p[maxn + B];
	inline int min(int x,int y){ return dfn[x] < dfn[y] ? x : y; }
	inline void down(int & x,int y){ if(dfn[x] > dfn[y]) x = y; }
	inline int qry(int l,int r){
		const int lg = std::__lg(r - l);
		return l >= r ? 0 : min(st[lg][l],st[lg][r - (1 << lg)]);
	}
	inline int rmq(int l,int r){
		if(l / B == r / B) {
			int ret = p[l];
			for(int i = l + 1;i <= r;++i) 
				down(ret,p[i]);
			return ret;
		}
		else return min(qry(l / B + 1,r / B),min(a[l],pre[r]));
	}
	inline void build(int n){
		++ n;
		memcpy(p,a,n << 2);
		for(int i = 0;i < n;i += B) {
			pre[i] = a[i];
			for(int j = i + 1;j < i + B;++j) pre[j] = min(pre[j - 1],a[j]);
			for(int j = i + B - 2;j >= i;--j) down(a[j], a[j + 1]);
			st[0][i / B] = a[i];
		}
		for(int i = 1;i < 15;++i)
			for(int j = 0;j + (1 << i) - 1 <= n / B + 1;++j)
				st[i][j] = min(st[i - 1][j],st[i - 1][j + (1 << i - 1)]);
	}
int head[maxn], next[maxn];
inline void link(int fa, int x) {
	next[x] = head[fa], head[fa] = x;
}
inline void dfs(int x,int f){
	a[tot] = f; dfn[x] = ++tot;
	for(int i = head[x];i;i = next[i])
		dfs(i, x);
}
inline int get_lca(int x,int y){
	if(dfn[x] > dfn[y]) std::swap(x,y);
	return x == y ? x : rmq(dfn[x], dfn[y] - 1);
}
int ans[maxn];

void init(int n,vector<pair<int,int> >&E){
	for(auto p:E)link(p.first,p.second);
	dfs(1,0); *dfn = 2e9; build(n - 1);
}
}lca;
#define SIZE 524288
int calc(int x,int y){
	return dep[x]+dep[y]-2*dep[lca.get_lca(x,y)];
}
struct state{
	int x=0,y=0,d=0;
	state(int a=0,int b=0,int c=0){
		x=a;y=b;d=c;
	}
};
inline void func(int &x,int &y,state&s){
	if(!x||!y)return;
	int tmp=calc(x,y);
	if(tmp>s.d){s.x=x;s.y=y;s.d=tmp;}
}
void merge(state&ret,state &a,state &b){
	if(a.x==0&&a.y==0){ret=b;return;}
	if(b.x==0&&b.y==0){ret=a;return;}
	ret=a.d<b.d?b:a;
	func(a.x,b.x,ret);
	func(a.x,b.y,ret);
	func(b.x,a.y,ret);
	func(a.y,b.y,ret);
}
void dfs(int x,int par){
	p[x]=par;l[x]=++tot;
	pos[tot]=x;
	for(auto p:g[x])if(p.first!=par){
		col[p.first]=col[x]^p.second;
		dep[p.first]=dep[x]+1;
		dfs(p.first,x);
	}
	r[x]=tot;
}
state f[2][SIZE<<1];
bool tag[SIZE<<1];
void init(){
	for(int i=1;i<=n;i++){
		f[col[pos[i]]][i+SIZE].x=pos[i];
		f[col[pos[i]]][i+SIZE].y=0;
		f[col[pos[i]]][i+SIZE].d=0;
	}
	for(int i=SIZE-1;i>=1;i--){
		merge(f[0][i],f[0][i<<1],f[0][i<<1|1]);
		merge(f[1][i],f[1][i<<1],f[1][i<<1|1]);
	}
}
void Rev(int k){
	tag[k]^=1;
	swap(f[0][k],f[1][k]);
}
void pushdown(int k){
	if(tag[k]){
		Rev(k<<1);
		Rev(k<<1|1);
		tag[k]=0;
	}
}
void range(int ql,int qr,int l,int r,int k){
	if(qr<l||r<ql)return;
	if(ql<=l&&r<=qr){
		Rev(k);
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	range(ql,qr,l,mid,k<<1);
	range(ql,qr,mid+1,r,k<<1|1);
	merge(f[0][k],f[0][k<<1],f[0][k<<1|1]);
	merge(f[1][k],f[1][k<<1],f[1][k<<1|1]);
//	cerr<<l<<" "<<r<<" "<<f[0][k].d<<" "<<f[1][k].d<<endl; 
}
int main(){
	n=getint();
	for(int i=1;i<n;i++){
		int x=getint(),y=getint(),t=getint();
		E.push_back(make_pair(x,y));
		g[x].push_back(make_pair(y,t));
		g[y].push_back(make_pair(x,t));
	}
	dfs(1,0);
	auto EE=E;EE.clear();
	for(int i=2;i<=n;i++)EE.push_back(make_pair(p[i],i));
	lca.init(n,EE);
	init(); 
	q=getint();
	while(q--){
		int id=getint()-1;
		int x=E[id].first,y=E[id].second;
		if(p[x]==y)swap(x,y);
		range(l[y],r[y],0,SIZE-1,1);
		putln(max(f[0][1].d,f[1][1].d));
	}
	clear();
	return 0;
}