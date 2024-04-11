#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
void read(pp& x){ scanf("%d%d",&x.first, &x.second); }
void read(pll& x){ scanf("%lld%lld",&x.first, &x.second); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

int main()
{
	cppio();
int tc; cin >> tc;
rep(ti, tc){
	int n; cin >> n;
	int ans = 0;
	rep(i, 7){
		vector<int> ga, gb;
		rrep(j, n){
			if(1&(j>>i)) ga.pb(j);
			else gb.pb(j);
		}
		if(ga.empty() || gb.empty()) continue;
		cout << ga.size() << ' ' << gb.size() << ' ';
		for(int x:ga) cout << x << ' ';
		for(int y:gb) cout << y << ' ';
		cout << endl;
		int res; cin >> res;
		if(res == -1) return 0;
		ans = max(ans, res);
	}
	cout << "-1 " << ans << endl;
}
	return 0;
}