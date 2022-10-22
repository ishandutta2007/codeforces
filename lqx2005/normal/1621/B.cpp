#include <bits/stdc++.h>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
using namespace std;
typedef pair<int, int> pii;
map<pii, int> LR;
map<int, int> L, R;

void solve() {
	LR.clear(), L.clear(), R.clear();
	int n;
	cin >> n;
	int nl = 2e9, nr = -2e9;
	for(int i = 1; i <= n; i++) {
		int l, r, c;
		cin >> l >> r >> c;
		nl = min(nl, l), nr = max(nr, r);
		pii s = make_pair(l, r);
		if(LR.count(s)) LR[s] = min(LR[s], c);
		else LR[s] = c;
		if(L.count(l)) L[l] = min(L[l], c);
		else L[l] = c;
		if(R.count(r)) R[r] = min(R[r], c);
		else R[r] = c;
		int ans = INT_MAX;
		if(L.count(nl) && R.count(nr)) ans = min(L[nl] + R[nr], ans);
		s = make_pair(nl, nr);
		if(LR.count(s)) ans = min(ans, LR[s]);
		cout << ans << endl;
	}
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	for(cin >> t; t--; solve());
    return 0;
}