#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007 //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	int n;
	vector<pair<ll, int> >a;
	vector<pair<ll, int> >b;
	ll x, y, z;
	int ans;
	cin >> n;
	rep(i, n) {
		cin >> x;
		a.pb({ x,1 });
	}
	sort(all(a));
	int cur, sz;
	while (true) {
		sz = a.size();
		if (sz <= 1)break;
		cur = 0;
		while (true) {
			if (cur == sz)break;
			if ((cur + 1) == sz) {
				b.pb({ (a[cur].first) / 2, a[cur].second });
				break;
			}
			if ((a[cur].first / 2) == (a[cur + 1].first / 2)) {
				b.pb({ (a[cur].first) / 2, max(a[cur].second,a[cur + 1].second) + 1 });
				cur += 2;
			}
			else {
				b.pb({ (a[cur].first) / 2, a[cur].second });
				cur++;
			}
		}
		a = b;
		b.clear();		
	}
	ans = n - (a[0].second);
	cout << ans << endl;

	return 0;
}