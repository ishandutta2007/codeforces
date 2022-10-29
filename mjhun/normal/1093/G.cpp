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

void merge(vector<pair<int,int> >& a, vector<pair<int,int> >& b, vector<pair<int,int> >& c){
	fore(i,0,SZ(a))a[i]=max(b[i],c[i]);
}

struct STree {
	vector<vector<pair<int,int> > > st;int n,m;
	STree(int n, int m): st(4*n+5,vector<pair<int,int> >(1<<m,mp(-(1<<30),-1))), n(n), m(m) {}
	void init(int k, int s, int e, vector<int> *a){
		if(s+1==e){
			fore(i,0,1<<m){
				int r=0;
				fore(j,0,m){
					if(i&(1<<j))r+=a[s][j];
					else r-=a[s][j];
				}
				st[k][i]=mp(r,s);
			}
			return;
		}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		merge(st[k],st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, vector<int>& v){
		if(s+1==e){
			fore(i,0,1<<m){
				int r=0;
				fore(j,0,m){
					if(i&(1<<j))r+=v[j];
					else r-=v[j];
				}
				st[k][i]=mp(r,s);
			}
			return;
		}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		merge(st[k],st[2*k],st[2*k+1]);
	}
	void query(int k, int s, int e, int a, int b, vector<pair<int,int> >& r){
		//assert(k<SZ(st));
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){merge(r,r,st[k]);return;}
		int m=(s+e)/2;
		query(2*k,s,m,a,b,r);
		query(2*k+1,m,e,a,b,r);
	}
	void init(vector<int> *a){init(1,0,n,a);}
	void upd(int p, vector<int>& v){upd(1,0,n,p,v);}
	vector<int> query(int a, int b){
		vector<pair<int,int> > r(1<<m,mp(-(1<<30),-1));
		query(1,0,n,a,b,r);
		vector<int> rr;
		for(auto p:r)rr.pb(p.snd);
		return rr;
	}
};

int n,k,q;
vector<int> a[200005];

int manhattan(vector<int>& a, vector<int>& b){
	int r=0;
	fore(i,0,k)r+=abs(a[i]-b[i]);
	return r;
}

int main(){
	scanf("%d%d",&n,&k);
	STree st(n,k);
	fore(i,0,n){
		a[i]=vector<int>(k);
		fore(j,0,k)scanf("%d",&a[i][j]);
	}
	st.init(a);
	scanf("%d",&q);
	while(q--){
		int t;
		scanf("%d",&t);
		if(t==1){
			int i;
			scanf("%d",&i);i--;
			fore(j,0,k)scanf("%d",&a[i][j]);
			st.upd(i,a[i]);
		}
		else {
			int s,e;
			scanf("%d%d",&s,&e);s--;
			auto v=st.query(s,e);
			int r=0;
			fore(i,0,SZ(v)){
				r=max(r,manhattan(a[v[i]],a[v[i^((1<<k)-1)]]));
			}
			printf("%d\n",r);
		}
	}
	return 0;
}