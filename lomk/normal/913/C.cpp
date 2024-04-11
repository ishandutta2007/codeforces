/*input
4 3
10 100 1000 10000
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

int n;
vector<int> a;

int cal(int p, int left) {
	if (left == 0) return 0;
	int ret = 0;
	int t = left / (1LL << p);
	ret = t * a[p];
	left -= t * (1LL << p);
	return min(ret + a[p], ret + cal(p - 1, left));
}

int L;
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> L;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		a.push_back(x);
	}
	int base = a[0];
	for (int i = 1; i < a.size(); i++) {
		base *= 2;
		a[i] = min(a[i], base);
		base = min(a[i], base);
	}
	cout << cal(a.size() - 1, L) << endl;
}