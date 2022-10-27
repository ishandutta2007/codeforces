#include <bits/stdc++.h>
 
#define fi first
#define se second
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define pb push_back
#define MP make_pair
#define all(v) v.begin(),v.end()
#define clr(a) memset(a,0,sizeof(a))
#define FIN freopen("in.txt","r",stdin)
using namespace std;
 
typedef long double db;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
typedef vector<int> VI;
 
#define debug1(x) cout<<"["<<#x<<" "<<(x)<<"]\n"
#define debug2(x, y) cout<<"["<<#x<<" "<<(x)<<" "<<#y<<" "<<(y)<<"]\n"
#define debug3(x, y, z) cout<<"["<<#x<<" "<<(x)<<" "<<#y<<" "<<(y)<<" "<<#z<<" "<<z<<"]\n"
 
const db eps = 1e-9;
const db pi = acos(-1.0);
const int MX = 100000 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
//head
 
int n, m;
bool G[55][55];
map<string, int>mp;
VI vec;
int cnt, ans, group[55], num[55], p[55];
 
bool dfs(int u, int dep) {
	for (int i = u + 1; i <= cnt; i++) {
		if (num[i] + dep <= ans) return false;
		if (G[u][i]) {
			bool flag = true;
			for (int j = 0; j < dep; j++) {
				if (!G[i][p[j]]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				p[dep] = i;
				if (dfs(i, dep + 1)) return true;
			}
		}
	}
	if (dep > ans) {
		for (int i = 0; i < dep; i++) group[i] = p[i];
		ans = dep;
		return true;
	}
	return false;
}
 
void solve() {
	ans = -1;
	for (int i = cnt; i >= 1; i--) {
		p[0] = i;
		dfs(i, 1);
		num[i] = ans;
	}
}
 
int main() {
#ifndef ONLINE_JUDGE
	FIN;
#endif
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int op;
	string str;
	memset(G, true, sizeof(G));
	for (int i = 1; i <= n; i++) {
		cin >> op;
		if (op == 1) {
			for (auto u : vec) {
				for (auto v : vec) {
					if (u == v) continue;
					G[u][v] = false;
				}
			}
			vec.clear();
		} else {
			cin >> str;
			if (!mp.count(str)) mp[str] = ++cnt;
			vec.pb(mp[str]);
		}
	}
	for (auto u : vec) {
		for (auto v : vec) {
			if (u == v) continue;
			G[u][v] = false;
		}
	}
	solve();
	ans = max(ans, 0);
	cout << ans << "\n";
	return 0;
}