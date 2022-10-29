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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
#define S 250
using namespace std;
typedef long long ll;

#define MAXN 100005

ll ft[MAXN+1];
void upd(int i0, int v){
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}
ll get(int i0){
	ll r=0;
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}
ll get(int i0, int i1){return get(i1)-get(i0);}

int x[100005];
int n,m;
set<int> w[100005];
int z[100005];
int t[100005],aa[100005],bb[100005];
ll r[100005];
vector<pair<int,int> > q[100005];
vector<pair<int,int> > u;

int doit(int v, int a, int b){
	auto it=w[v].lower_bound(a);
	if(it==w[v].end()||*it>=b)return 0;
	int r=*it;
	it=w[v].lower_bound(b);--it;
	return *it-r;
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)scanf("%d",x+i),x[i]--,w[x[i]].insert(i);
	fore(i,0,m){
		scanf("%d%d%d",t+i,aa+i,bb+i);aa[i]--;
		if(t[i]==1)bb[i]--;
	}
	for(int k=0;k<m;k+=S){
		for(auto p:u){
			w[x[p.fst]].erase(p.fst);
			x[p.fst]=p.snd;
			w[x[p.fst]].insert(p.fst);
		}
		u.clear();
		fore(i,0,n)q[i].clear();
		mset(z,-1);
		fore(i,k,min(k+S,m))if(t[i]==2)q[aa[i]].pb(mp(bb[i],i));
		mset(ft,0);
		for(int i=n-1;i>=0;--i){
			if(z[x[i]]>=0)upd(z[x[i]],z[x[i]]-i);
			z[x[i]]=i;
			for(auto p:q[i])r[p.snd]=get(i,p.fst);
		}
		fore(i,k,min(k+S,m)){
			if(t[i]==1)u.pb(mp(aa[i],bb[i]));
			else {
				int a=aa[i],b=bb[i];
				vector<pair<int,int> > rb;
				set<int> asd;
				for(auto p:u){
					int k=p.fst,v=p.snd;
					if(k<a||k>=b)continue;
					if(!asd.count(x[k])){
						r[i]-=doit(x[k],a,b);
						asd.insert(x[k]);
					}
					if(!asd.count(v)){
						r[i]-=doit(v,a,b);
						asd.insert(v);
					}
				}
				for(auto p:u){
					int k=p.fst,v=p.snd;
					rb.pb(mp(k,x[k]));
					w[x[k]].erase(k);
					x[k]=v;
					w[x[k]].insert(k);
				}
				for(int v:asd)r[i]+=doit(v,a,b);
				reverse(rb.begin(),rb.end());
				for(auto p:rb){
					int k=p.fst,v=p.snd;
					w[x[k]].erase(k);
					x[k]=v;
					w[x[k]].insert(k);
				}
			}
		}
	}
	fore(i,0,m)if(t[i]==2)printf("%lld\n",r[i]);
	return 0;
}