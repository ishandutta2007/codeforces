#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
const ll mn=2e5+4;
typedef pair<ll,ll> pll;
vector<pll> v[mn];
ll vans[mn],vk[mn];
vector<ll> divs[44];
ll mod[44][44];
int main() 
{
	for (ll k=1;k<=40;k++) {
		for (ll d=1;d<=40;d++) {
			if (k%d==0) divs[k].PB(d);
		}
	}
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; scanf("%lld %lld",&n,&m);
	for (ll i=0;i<n;i++) {
		ll kk;scanf("%lld",&kk);
		vk[i]=kk;
		for (ll j=0;j<kk;j++) {
			ll x; scanf("%lld",&x);
			v[x].PB(MP(i,j));
		}
	}
	for (ll t=1;t<=m;t++) {
		ll ans=0;
		vector<vector<pll> > c;
		{
			//if(t==4)for (auto &w:v[t]) printf("%lld %lld: ",w.first,w.second);
			//printf("\n");
			ll vsz=v[t].size();
			if (vsz==0) continue;
			vector<pll> tmp;
			tmp.PB(v[t][0]);
			for (ll i=1;i<vsz;i++) {
				if (v[t][i].first==v[t][i-1].first+1) tmp.PB(v[t][i]);
				else {c.PB(tmp);tmp.clear();tmp.PB(v[t][i]);}
			}
			if(tmp.size())c.PB(tmp);
		}
		for (auto &u:c) {
			ll usz=u.size();
			for (ll d=0;d<=40;d++) for (ll e=0;e<=40;e++) mod[d][e]=0;
			ll l=0,r=0;
			//if (t==4) for (auto &w:u) printf("%lld %lld (%lld), ",w.first,w.second,vk[w.first]);
			//printf("\n");
			while(l<usz&&r<usz) {
				ll idx=u[r].first; ll k=vk[idx];
				ll pos=u[r].second;
				for (auto &d:divs[k]) {
					//printf("Ins: %lld %lld\n",d,pos%d);
					mod[d][pos%d]++;
				}
				r++;
				while(1) {
					bool bad=false;
					for (auto &d:divs[k]) {
						for (ll e=0;e<d;e++) {
							if (e==pos%d) continue;
							if (mod[d][e]!=0) {
								bad=true;
								break;
							}
						}
					}
					if (!bad) break;
					ll lidx=u[l].first; ll lk=vk[lidx];
					ll lpos=u[l].second;
					for (auto &d:divs[lk]) {
						mod[d][lpos%d]--;
						//printf("Rm: %lld %lld\n",d,lpos%d);
					}
					l++;
				}
				//if (t==4) printf("%lld %lld\n",l,r);
				chkmax(ans,r-l);
			}
		}
		vans[t]=ans;
	}
	for (ll t=1;t<=m;t++) printf("%lld\n",vans[t]);
}