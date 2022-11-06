#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=5e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const int mn=1e5+4;
int a[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int y=a[0];
	int root=(round(sqrt(y)))+2;
	set<int> s;
	for (int d=1;d<=root;d++) {
		int q=y/d;
		if (q>root) {
			s.insert(q);
			s.insert(q-1);
			s.insert(q+1);
		}
	}
	vector<int> v;
	for (int x=0;x<=root;x++) v.PB(x);
	for (auto &w:s) v.PB(w);
	ll final=INF;
	for (auto it=v.rbegin();it!=v.rend();++it) {
		int _x=*it;
		ll x=_x;
		ll ans=0;
		for (int i=0;i<n;i++) {
			ll buckets=(a[i]+x)/(x+1);
			ll lack=buckets*(x+1)-a[i];
			if (lack>buckets) {
				ans=INF; break;
			}
			ans+=buckets;
		}
		chkmin(final,ans);
		/*if (ans!=INF) {
			printf("%lld\n",ans);
			return 0;
		}*/
	}
	printf("%lld\n",final);
}