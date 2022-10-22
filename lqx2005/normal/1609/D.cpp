#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define sz(a) int((a).size())
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 1e3 + 10;
int n, d, fa[N], siz[N];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]); }
int merge(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return 0;
	return fa[x] = y, siz[y] += siz[x], siz[x] = 0, 1;
}
void solve() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
	int cnt = 0;
	for(int i = 1; i <= d; i++) {
		int x, y;
		cin >> x >> y;
		cnt += !merge(x, y);
		vector<int> con;
		for(int j = 1; j <= n; j++) if(find(j) == j) con.push_back(siz[j]);
		sort(con.begin(), con.end(), greater<int>());
		int res = 0;
		for(int j = 0; j < cnt + 1; j++) res += con[j];
		cout << res - 1 << endl;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	solve();
	// for(cin >> t; t--; solve());
	return 0;
}