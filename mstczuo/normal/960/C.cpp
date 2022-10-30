# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define all(a) a.begin(),a.end()
#define For(i, l, r) for(int i = l; i <= r; ++i)
#define rep(i, n) For(i, 0, n-1)
#define pb push_back

void rd(int &x) { scanf("%d", &x); }

int main() {
	int d, X; rd(X); rd(d);
	ll cur = 1;
	vector<ll> ans;
	while(X > 0) {
		int cnt = 0;
		while(X >= ((1 << cnt) - 1)) ++cnt;
		--cnt;
		X -= (1 << cnt) - 1;
		rep(i, cnt) ans.pb(cur);
		cur += d + 1;
	}
	cout << ans.size() << endl;
	for(auto x: ans) cout << x << ' ';
	cout << endl;
}