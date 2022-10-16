/*input
11
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

vector<int> order;
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << ((n * (n + 1)) / 2) % 2 << endl;
		int x = 0;
		for (int i = 1; i <= n; i += 2) {
			order.push_back(i + x);
			x ^= 1;
		}
		cout << order.size() << sp << order << endl;
		return 0;
	}
	int x = 0, y = 0;
	for (int i = n; i >= 1; i--) {
		if (x < y) {
			order.push_back(i);
			x += i;
		}
		else y += i;
	}
	cout << abs(x - y) << endl;
	cout << order.size() << sp << order << endl;
}