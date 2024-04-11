/*input
3 7
0 4
2 5
6 7
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

vector<vector<int> > a(105);
int n, m;
bool visited[105];
void bfs() {
	visited[0] = true; queue<int> q; q.push(0);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto it : a[u]) {
			for (int i = u; i <= it; i++) {
				if (!visited[i]) {
					visited[i] = true;
					q.push(i);
				}
			}
		}
	}
	if (visited[m]) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int l, r; cin >> l >> r;
		if (a[l].empty())
			a[l].push_back(r);
		else if (a[l].back() < r) {
			a[l].pop_back();
			a[l].push_back(r);
		}
	}
	bfs();
}