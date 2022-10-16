/*input
2 100
2 42
2 58
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N
#define bit(x,y) ((x>>y)&1LL)
#define na(x) (#x) << ":" << x
ostream& operator << (ostream &os, vector<int>&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << sp;
	return os;
}
ostream& operator << (ostream &os, pair<int, int> x) {
	cout << x.fi << sp << x.se << sp;
	return os;
}
ostream& operator << (ostream &os, vector<pair<int, int> >&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << endl;
	return os;
}
struct data {
	int fi, se, id;
	data(int _fi, int _se, int _id): fi(_fi), se(_se), id(_id) {};
};

int n, T;
vector<data > a;

bool cmp(data x, data y) {
	return x.se < y.se;
}

vector<int> b;
bool check(int lim, bool trace = 0) {
	int cnt = 0; int rem = T;
	for (int i = 0; i < a.size(); i++) {
		if (a[i].fi < lim) continue;
		rem -= a[i].se;
		if (rem < 0) break;
		if (trace) {
			b.push_back(a[i].id);
		}
		cnt++;
		if (cnt == lim) break;
	}
	return (cnt >= lim);
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> T;
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		a.push_back(data(x, y, i));
	}
	sort(a.begin(), a.end(), cmp);
	int l = 0, r = n;
	while (l != r) {
		int mid = (l + r + 1) / 2;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	check(l, 1);
	cout << b.size() << endl;
	cout << b << endl;
}