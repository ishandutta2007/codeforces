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
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

struct WT {
	vector<int> wt[1<<20];int n;
	void init(int k, int s, int e){
		if(s+1==e)return;
		wt[k].clear();wt[k].pb(0);
		int m=(s+e)/2;
		init(2*k,s,m);init(2*k+1,m,e);
	}
	void add(int k, int s, int e, int v){
		if(s+1==e)return;
		int m=(s+e)/2;
		if(v<m)wt[k].pb(wt[k].back()),add(2*k,s,m,v);
		else wt[k].pb(wt[k].back()+1),add(2*k+1,m,e,v);
	}
	int query0(int k, int s, int e, int a, int b, int c, int d){
		if(s>=b||e<=a)return 0;
		if(s>=a&&e<=b)return d-c;
		int m=(s+e)/2;
		return query0(2*k,s,m,a,b,c-wt[k][c],d-wt[k][d])+
			   query0(2*k+1,m,e,a,b,wt[k][c],wt[k][d]);
	}
	void init(int _n){n=_n;init(1,0,n);} // (values in range [0,n))
	void add(int v){add(1,0,n,v);}
	int query(int c, int d, int a, int b){ // values in [a,b) in range [c,d)
		return query0(1,0,n,a,b,c,d);
	}
};

int n,q;
WT w;

int main(){
	while(scanf("%d%d",&n,&q)!=EOF){
		w.init(n);
		fore(i,0,n){
			int x;
			scanf("%d",&x);x--;
			w.add(x);
		}
		while(q--){
			int l,d,r,u;
			scanf("%d%d%d%d",&l,&d,&r,&u);l--;d--;
			ll x1,x2,x3,x4,x5,x6,x7,x8,x9;
			x1=w.query(0,l,0,d);
			x2=w.query(l,r,0,d);
			x3=w.query(r,n,0,d);
			x4=w.query(0,l,d,u);
			x5=w.query(l,r,d,u);
			x6=w.query(r,n,d,u);
			x7=w.query(0,l,u,n);
			x8=w.query(l,r,u,n);
			x9=w.query(r,n,u,n);
			assert(x1+x2+x3+x4+x5+x6+x7+x8+x9==n);
			//printf("%d %d %d %d %lld\n",l,r,d,u,x5);
			ll rr=0;
			rr+=x5*(n-x5);
			rr+=x5*(x5-1)/2;
			rr+=x1*(x6+x8+x9);
			rr+=x2*(x4+x6+x7+x8+x9);
			rr+=x3*(x4+x7+x8);
			rr+=x4*(x6+x8+x9);
			rr+=x6*(x7+x8);
			printf("%lld\n",rr);
		}
		puts("");
	}
	return 0;
}