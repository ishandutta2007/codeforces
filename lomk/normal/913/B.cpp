/*input
8
1
1
1
1
3
3
3
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N 1005
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

vector<vector<int> > a(N);
int n;

void dfs(int u) {
	for (auto it : a[u]) {
		dfs(it);
	}
	if (u == 1 || a[u].size() != 0) {
		int cnt = 0;
		for (auto it : a[u]) {
			cnt += (a[it].size() == 0);
		}
		if (cnt<3){
			cout << "No" << endl;
			exit(0);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int u; cin >> u;
		a[u].push_back(i);
	}
	dfs(1);
	cout << "Yes" << endl;
}