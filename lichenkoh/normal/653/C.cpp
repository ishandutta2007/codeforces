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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
int a[150008];
int main() {
	ios_base::sync_with_stdio(false);
	int n; scanf("%d",&n);
	for (ll i=1;i<=n;i++) scanf("%d",&a[i]);
	vector<ll> v;
	for (ll i=1;i<n;i++) {
		if ((i%2)==1 && !(a[i]<a[i+1])) v.PB(i);
		if ((i%2)==0 && !(a[i]>a[i+1])) v.PB(i);
	}
	if (v.size()>10) {
		cout<<0<<endl;
		return 0;
	}
	set<pair<ll,ll> > s;
	for (ll x=v[0];x<=v[0]+1;x++) {
		for (ll y=1;y<=n;y++) {
			if (x==y) continue;
			//printf("xy:%d %d\n",x,y);
			swap(a[x],a[y]);
			//for (ll i=1;i<=n;i++) //printf("%d ",a[i]);
			vector<ll> check=v;
			check.PB(y);
			bool ok=true;
			for (auto &w: check) {
				ll tlo=max(1LL,w-2);
				ll thi=min((ll)n,w+3);
				for (ll i=tlo;i<thi;i++) {
					if ((i%2)==1 && !(a[i]<a[i+1])) {
						ok=false;break;
					}
					if ((i%2)==0 && !(a[i]>a[i+1])) {
						ok=false;break;
					}
				}
			}
			if (ok) {
				ll tx=x,ty=y;
				if (tx>ty) swap(tx,ty);
				s.insert(MP(tx,ty));
			}
			//if(ok)//printf("OK\n");
			//else //printf("FAIL\n");
			swap(a[x],a[y]);
		}
	}
	ll ans=s.size();
	cout<<ans<<endl;
}