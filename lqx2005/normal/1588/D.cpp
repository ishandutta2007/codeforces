#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define par pair<int, int>
#define pb push_back
#define eb emplace_back
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const int N = 10, M = 120, T = M << N;
int n;
char s[N][M];
map<vector<int>, int> vis;
int nxt[N][M][52], tot = 0;
int deg[T], pre[T], cha[T], dp[T];
vector<par> g[T];
int id(char x){return x <= 'Z' ? x - 'A' : x - 'a' + 26; }
char rev(int x) {return x < 26 ? x + 'A' : x - 26 + 'a'; }

void solve() {
	vis.clear();
	for(int i = 1; i <= tot; i++) g[i].clear();
	tot = 0;
	memset(deg, 0, sizeof(deg));
	memset(nxt, -1, sizeof(nxt));
	memset(pre, 0, sizeof(pre));
	memset(dp, 0, sizeof(dp));
	memset(cha, 0, sizeof(cha));
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> (s[i] + 1);
		int m = strlen(s[i] + 1);
		for(int j = m; j >= 1; j--) {
			memcpy(nxt[i][j], nxt[i][j + 1], sizeof(nxt[i][j + 1]));
			nxt[i][j][id(s[i][j])] = j;
		}
	}
	queue<vector<int> > q;
	vector<int> str(n);
	q.push(str);
	vis[str] = ++tot;
	while(!q.empty()) {
		vector<int> u = q.front();
		q.pop();
		for(int i = 0; i < 52; i++) {
			vector<int> tmp = u;
			int flag = 0;
			for(int j = 0; j < n; j++) {
				tmp[j] = nxt[j][tmp[j] + 1][i];
				if(tmp[j] == -1) {
					flag = 1;
					break;
				}
			}
			if(flag) continue;
			if(!vis[tmp]) vis[tmp] = ++tot, q.push(tmp);
			g[vis[u]].push_back({vis[tmp], i}), deg[vis[tmp]]++;
		}
	}
	queue<int> Q;
	for(int i = 1; i <= tot; i++) if(deg[i] == 0) Q.push(i);
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for(par &e : g[u]) {
			int v, w;
			tie(v, w) = e;
			if(dp[v] < dp[u] + 1) {
				dp[v] = dp[u] + 1;
				pre[v] = u, cha[v] = w;
			}
			deg[v]--;
			if(deg[v] == 0) Q.push(v);
		}
	}
	int t = -1;
	for(int i = 1; i <= tot; i++) if(t == -1 || dp[i] > dp[t]) t = i;
	string ans;
	for(int u = t; pre[u]; u = pre[u]) ans = ans + rev(cha[u]);
	reverse(ans.begin(), ans.end());
	cout << sz(ans) << endl;
	cout << ans << endl;
	return;
}

int main() {
	int T;
	for(cin >> T; T--; solve());
	return 0;
}