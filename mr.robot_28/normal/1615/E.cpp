#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
#define sz(a) (int)a.size()
const int N = 2e5 + 100;
const int mod = 1e9 + 7;
vector <int> g[N];

int Tree[4 * N];
int tin[N];
int tout[N];
int upd[4 * N];
int p[N];
int mass[N];
int used[N];

void push(int v) {
	upd[v * 2] += upd[v];
	upd[v * 2 + 1] += upd[v];
	Tree[v * 2] += upd[v];
	Tree[v * 2 + 1] += upd[v];
	upd[v] = 0;
}

void update(int v, int l, int r, int al, int ar, int val) {
	if (l >= al && r <= ar) {
		upd[v] += val;
		Tree[v] += val;
		return;
	}
	if (l <= ar && r >= al) {
		push(v);
		update(v * 2, l, (r + l) / 2, al,ar, val);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
		Tree[v] = max(Tree[v * 2], Tree[v * 2 + 1]);
	}
}

int get(int v, int l, int r) {
	if (l == r) {
		return l;
	}
	push(v);
	if (Tree[v * 2] > Tree[v * 2 + 1]) {
		return get(v * 2, l, (r + l) / 2);
	}
	return get(v * 2 + 1, (r + l) / 2 + 1 ,r);
}

int timer = 0;
void dfs(int v) {
	mass[timer] = v;
	tin[v] = timer++;
	for (auto to : g[v]) {
		if (p[v] == to) {
			continue;
		}
		p[to] = v;
		dfs(to);
	}
	tout[v] = timer - 1;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	p[0] = -1;
	dfs(0);
	for (int i = 0; i < n; i++) {
		update(1, 0, n - 1, tin[i], tout[i], 1);
		//cout << tin[i] << " " << tout[i] << "\n";
	}
	int ans = -1e10;
	int maxy = n;
	for (int i = 0; i <= k; i++) {
			int val = min(1LL * (n - i) * i, 1LL * (n - i - maxy) * (i - maxy));
			if (n / 2 <= maxy) {
				val = min(val, 1LL * (n - i - n / 2) * (i - n / 2));
			}
			if (n / 2 + 1 <= maxy) {
				val = min(val, 1LL * (n - i - n / 2 - 1) * (n - n / 2 - 1));
			}
	//		cout << maxy << " ";
			ans = max(ans, val);
	//	cout << ans << "\n";
		int t = get(1, 0, n - 1);
	//	cout << Tree[1] << "\n";
	//	cout << t << "\n";
		int cur = mass[t];
	//	cout << cur << "\n";
		maxy -= Tree[1];
		while (cur != -1 && !used[cur]) {
	//		cout << "A " << cur << "\n";
			used[cur] = 1;
			update(1, 0, n - 1, tin[cur], tout[cur], -1);
			cur = p[cur]; 
		}
	}
	cout << ans;
	return 0;
}