#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define N 200100
#define MOD 1000000007 //998244353
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	int t;
	int a, b, c, d;
	int ans;

	cin >> t;
	rep(tt, t) {
		cin >> a >> b >> c >> d;
		if ((a != c) && (b != d))ans = abs(a - c) + abs(b - d) + 2;
		else ans = abs(a - c) + abs(b - d);
		cout << ans << endl;
	}
	return 0;
}