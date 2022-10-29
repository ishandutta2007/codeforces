#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

pair<int,int> op(pair<int,int> a, pair<int,int> b){
	if(a.fst>b.fst)return a;
	else if(a.fst<b.fst)return b;
	return mp(a.fst,a.snd+b.snd);
}

struct STree {
	vector<pair<int,int> > st;vector<int> lazy;int n;
	STree(int n): st(4*n+5), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e){
		st[k]=mp(0,e-s);
		if(s+1==e)return;
		int m=(s+e)/2;
		init(2*k,s,m);init(2*k+1,m,e);
	}
	void push(int k, int s, int e){
		if(!lazy[k])return;
		st[k].fst+=lazy[k];
		if(s+1<e){
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0;
	}
	void upd(int k, int s, int e, int a, int b, int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v;
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=op(st[2*k],st[2*k+1]);
	}
	pair<int,int> query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return mp(0,1);
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return op(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(){init(1,0,n);}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	pair<int,int> query(int a, int b){return query(1,0,n,a,b);}
};

vector<int> g[1<<18];int n,q;
int f[18][1<<18],d[1<<18];
int s[1<<18],e[1<<18],T;
set<pair<int,int> > w;

void dfs(int x){
	s[x]=T++;
	for(int y:g[x])if(y!=f[0][x]){
		d[y]=d[x]+1;
		f[0][y]=x;
		dfs(y);
	}
	e[x]=T;
}

int main(){
	scanf("%d%d",&n,&q);
	fore(_,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	f[0][0]=-1;
	dfs(0);
	fore(k,1,18)fore(i,0,n){
		if(f[k-1][i]<0)f[k][i]=-1;
		else f[k][i]=f[k-1][f[k-1][i]];
	}
	STree st(n);st.init();
	while(q--){
		int x,y,v;
		scanf("%d%d",&x,&y);x--;y--;
		if(x>y)swap(x,y);
		if(w.count(mp(x,y)))w.erase(mp(x,y)),v=-1;
		else w.insert(mp(x,y)),v=1;
		if(d[x]<d[y])swap(x,y);
		int z=x;
		for(int k=17;k>=0;--k)if(d[z]-(1<<k)>=d[y])z=f[k][z];
		if(z!=y){
			st.upd(s[x],e[x],v);
			st.upd(s[y],e[y],v);
		}
		else {
			z=x;
			for(int k=17;k>=0;--k)if(d[z]-(1<<k)>d[y])z=f[k][z];
			st.upd(0,n,v);
			st.upd(s[z],e[z],-v);
			st.upd(s[x],e[x],v);
		}
		auto p=st.query(0,n);int r=0;
		if(p.fst==SZ(w))r=p.snd;
		printf("%d\n",r);
	}
	return 0;
}