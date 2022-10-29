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
#define INF (1LL<<41)
using namespace std;
typedef long long ll;

int n,m,k;
vector<pair<ll,int> > a[1<<21];
vector<pair<ll,int> > b[1<<21];
multiset<ll> c0[100005];
multiset<ll> c1[100005];
ll rr,r;

int main(){
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		fore(i,0,1<<20)a[i].clear(),b[i].clear();
		fore(i,0,m){
			int d,f,t;ll c;
			scanf("%d%d%d%lld",&d,&f,&t,&c);f--;t--;d--;
			if(f<0)b[d].pb(mp(c,t));
			else a[d].pb(mp(c,f));
		}
		fore(i,0,n)c0[i].clear(),c1[i].clear(),c0[i].insert(INF),c1[i].insert(INF);
		r=rr=INF*2*n;
		fore(i,k,1000004)for(auto p:b[i]){
			rr-=*c1[p.snd].begin();
			c1[p.snd].insert(p.fst);
			rr+=*c1[p.snd].begin();
		}
		fore(i,0,1000004){
			//if(i<20)printf(" %lld\n",rr);
			r=min(r,rr);
			for(auto p:a[i]){
				assert(!c0[p.snd].empty());
				rr-=*c0[p.snd].begin();
				c0[p.snd].insert(p.fst);
				rr+=*c0[p.snd].begin();
			}
			for(auto p:b[i+k]){
				assert(!c1[p.snd].empty());
				assert(c1[p.snd].count(p.fst));
				rr-=*c1[p.snd].begin();
				c1[p.snd].erase(c1[p.snd].find(p.fst));
				rr+=*c1[p.snd].begin();
			}
		}
		if(r>=INF)puts("-1");
		else printf("%lld\n",r);
		puts("");
	}
	return 0;
}