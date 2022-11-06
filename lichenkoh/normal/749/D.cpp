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
const ll mn=2e5+2;
ll a[mn],b[mn];
vector<ll> qv[mn];
ll L[mn],R[mn];
vector<ll> check[mn];
bool seen[mn];
ll orig[mn];
set<ll> h[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	for (ll i=0;i<n;i++) scanf("%lld%lld",a+i,b+i);
	ll qlim; scanf("%lld",&qlim);
	for (ll i=0;i<qlim;i++) {
		ll k; scanf("%lld",&k);
		for (ll j=0;j<k;j++) {
			ll x; scanf("%lld",&x);
			qv[i].PB(x);
		}
	}
	for (ll q=0;q<qlim;q++) {
		L[q]=0;R[q]=n+1;
	}
	for (ll steps=0;steps<20;steps++) {
		memset(seen,0,sizeof seen);
		for (ll i=0;i<=n;i++) {
			check[i].clear();
		}
		for (ll q=0;q<qlim;q++) {
			if (L[q]!=R[q]) {
				ll mid=(L[q]+R[q])/2;
				check[mid].PB(q);
			}
		}
		ll ea=0;
		for (ll i=n;i>=0;i--) {
			for (auto &q:check[i]) {
				ll qrmea=0;
				for (auto &x:qv[q]) {
					if (!seen[x]) qrmea++;
				}
				ll qr=qv[q].size();
				if (qrmea+ea==qr) {
					R[q]=i;
				}
				else {
					L[q]=i+1;
				}
			}
			if (i-1>=0) {
				if (!seen[a[i-1]]) {
					seen[a[i-1]]=true;
					ea++;
				}
			}
		}
	}
	for (ll q=0;q<qlim;q++) L[q]--;
	for (ll q=0;q<qlim;q++) orig[q]=L[q];
	for (ll q=0;q<qlim;q++) {
		ll idx=L[q];
		if (idx!=-1) {
			ll k=a[idx];
			qv[q].PB(k);
		}
	}


	for (ll q=0;q<qlim;q++) {
		L[q]=0;R[q]=n+1;
	}
	for (ll steps=0;steps<20;steps++) {
		memset(seen,0,sizeof seen);
		for (ll i=0;i<=n;i++) {
			check[i].clear();
		}
		for (ll q=0;q<qlim;q++) {
			if (L[q]!=R[q]) {
				ll mid=(L[q]+R[q])/2;
				check[mid].PB(q);
			}
		}
		ll ea=0;
		for (ll i=n;i>=0;i--) {
			for (auto &q:check[i]) {
				ll qrmea=0;
				for (auto &x:qv[q]) {
					if (!seen[x]) qrmea++;
				}
				ll qr=qv[q].size();
				if (qrmea+ea==qr) {
					R[q]=i;
				}
				else {
					L[q]=i+1;
				}
			}
			if (i-1>=0) {
				if (!seen[a[i-1]]) {
					seen[a[i-1]]=true;
					ea++;
				}
			}
		}
	}
	for (ll q=0;q<qlim;q++) L[q]--;


	for (ll x=0;x<n;x++) {
		h[a[x]].insert(x);
	}
	for (ll q=0;q<qlim;q++) {
		if (orig[q]==-1) {
			printf("0 0\n");
		}
		else {
			ll oidx=orig[q];
			ll nidx=L[q];
			ll k=a[oidx];
			ll cost=b[*(h[k].lower_bound(nidx))];
			printf("%lld %lld\n",k,cost);
		}
	}
}