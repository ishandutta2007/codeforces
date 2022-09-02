#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll le = 0, ri = 0;

void assign(ll v, char side, char tar) {
	cout << v << ' ' << side << endl;
	
	if (side == 'L') le += v;
	else ri += v;

	if (tar == 'L') assert(le > ri);
	else assert(ri > le);
}

void solve(int a, int b, const vector<ll>& as, const string& tar) {
	int k = b-a+1;
	if (k & 1) {
		solve(a, b-1, as, tar);
		assign(as[b], tar[k-1], tar[k-1]);
	} else if (k > 0) {
		char pre = (k == 2 ? 'L' : tar[k-3]);
		char cur = tar[k-2];
		char nxt = tar[k-1];
		char oth = cur ^ ('L' ^ 'R');
		if (cur != pre && nxt != pre) {
			solve(a+1, b-1, as, tar);
			assign(as[b], cur, cur);
			assign(as[a], oth, nxt);
		} else if (cur == pre && nxt != pre) {
			solve(a+1, b-1, as, tar);
			assign(as[a], cur, cur);
			assign(as[b], nxt, nxt);
		} else if (cur != pre && nxt == pre) {
			solve(a, b - 2, as, tar);
			assign(as[b-1], cur, cur);
			assign(as[b], nxt, nxt);
		} else if (cur == pre && nxt == pre) {
			solve(a, b - 2, as, tar);
			assign(as[b], cur, cur);
			assign(as[b-1], oth, nxt);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;
	sort(as.begin(), as.end());

	string tar;
	cin >> tar;
	solve(0, n-1, as, tar);
}