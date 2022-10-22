#include <bits/stdc++.h> 
#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))
#define VI vector<int> 
#define sz(a) int((a).size())
using namespace std;
const int N = 100 + 10, P = 1e9 + 7, M = 1e5 + 10, K = 16;
struct Edge { int to, w, id; };
int n, k, vis[N], used[N], sze[N], fac[M];
int b[N], e[N], w[N], eid[N], etot = 0, vid[N], vtot = 0, tot = 0, A = 0, B = 0;
int L[N], ltot = 0, R[N], rtot = 0;
VI dp[N][2];
VI DP[N][1 << K];
vector<Edge> g[N * 2];
int id[M];
VI operator + (VI a, VI b) {
	VI c(max(sz(a), sz(b)));
	for(int i = 0; i < sz(c); i++) {
		if(i < sz(a)) c[i] = a[i];
		if(i < sz(b)) c[i] = (c[i] + b[i]) % P;
	}
	return c;
}

VI operator * (VI a, VI b) {
	if(a.empty() || b.empty()) return VI{};
	VI c(sz(a) + sz(b) - 1);
	for(int i = 0; i < sz(a); i++) {
		if(!a[i]) continue;
		for(int j = 0; j < sz(b); j++) {
			(c[i + j] += 1ll * a[i] * b[j] % P) %= P;
		}
	}
	return c;
}


void dfs(int u, int fa) {
	vis[u] = 1;
	vid[++vtot] = u;
	for(Edge &e : g[u]) {
		int v = e.to, w = e.w, id = e.id;
		if(v == fa || used[id]) continue;
		if(vis[v]) {
			eid[++etot] = id;
			used[id] = 1;
			continue;
		}
		dfs(v, u);
	}
	return;
}

void DFS(int u, int fa) {
	dp[u][0].clear(), dp[u][1].clear();
	if(vis[u]) dp[u][1] = VI{1};
	else dp[u][0] = dp[u][1] = VI{1};
	for(Edge &e : g[u]) {
		int v = e.to, w = e.w, id = e.id;
		if(v == fa || used[id]) continue;
		DFS(v, u);
		dp[u][1] = dp[u][1] * dp[v][1];
		dp[u][1] = dp[u][1] + dp[u][0] * dp[v][0] * VI{0, w};
		dp[u][0] = dp[u][0] * dp[v][1];
	}
//	cout << "V :" << u << endl;
//	for(int x : dp[u][0]) cout << x <<" ";
//	cout << endl;
//	for(int x : dp[u][1]) cout << x <<" ";
//	cout << endl;
	return;
}

VI subtask1(int i) {
	VI sum;
	for(int j = 0; j < (1 << etot); j++) {
		for(int k = 1; k <= vtot; k++) vis[vid[k]] = 0;
		VI prod{1};
		for(int k = 1; k <= etot; k++) {
			if(j >> (k - 1) & 1) {
				vis[b[eid[k]]]++;
				vis[e[eid[k]]]++;
				prod = prod * VI{0, w[eid[k]]};
			}
		}
		int flag = 0;
		for(int k = 1; k <= vtot; k++) {
			if(vis[vid[k]] > 1) {
				flag = 1;
				break;
			}
		}
		if(flag) continue;
		DFS(i, 0);
		prod = prod * dp[i][1];
		sum = sum + prod;
	}
	for(int k = 1; k <= vtot; k++) vis[vid[k]] = 1;
	return sum;
}

VI subtask2(int i) {
	VI sum;
	ltot = rtot = 0;
	for(int i = 1; i <= vtot; i++) {
		if(vid[i] <= A) L[++ltot] = vid[i];
		else R[++rtot] = vid[i];
	}
	if(ltot < rtot) swap(ltot, rtot), swap(L, R);
	for(int i = 1; i <= rtot; i++) id[R[i]] = i - 1;
	for(int i = 0; i < (1 << rtot); i++) DP[0][i].clear();
	DP[0][0] = VI{1};
	for(int i = 1; i <= ltot; i++) {
		for(int mask = 0; mask < (1 << rtot); mask++) DP[i][mask] = DP[i - 1][mask];
		for(int mask = 0; mask < (1 << rtot); mask++) {
			for(Edge &e : g[L[i]]) {
				int v = e.to, w = e.w;
				if(mask >> id[v] & 1) continue;
				DP[i][mask ^ (1 << id[v])] = DP[i][mask ^ (1 << id[v])] + DP[i - 1][mask] * VI{0, w};
			}
		}
	}
	VI ans;
	for(int i = 0; i < (1 << rtot); i++) ans = ans + DP[ltot][i];
	return ans;
}
int main() {
	cin >> n >> k;
	for(int i = 1; i <= k; i++) {
		cin >> b[i] >> e[i] >> w[i];
		w[i]--;
		if(w[i] < 0) w[i] += P;
	}
	tot = 0;
	for(int i = 1; i <= k; i++) {
		if(!id[b[i]]) id[b[i]] = ++tot, A++;
		b[i] = id[b[i]];
	}
	FILL(id, n + 1, 0);
	for(int i = 1; i <= k; i++) {
		if(!id[e[i]]) id[e[i]] = ++tot, B++;
		e[i] = id[e[i]];
	}
	FILL(id, n + 1, 0);
	for(int i = 1; i <= k; i++) {
		g[b[i]].push_back(Edge{e[i], w[i], i});
		g[e[i]].push_back(Edge{b[i], w[i], i});
	}
	VI ans{1};
	for(int i = 1; i <= tot; i++) {
		if(!vis[i]) {
			vtot = etot = 0;
			dfs(i, 0);
			if(etot <= 18) {
				ans = ans * subtask1(i);	
			} else {
				ans = ans * subtask2(i);
			}
		}
	}
	fac[0] = 1;
	for(int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % P; 
	}
	int res = 0;
	for(int i = 0; i < sz(ans) && i <= n; i++) {
		(res += 1ll * ans[i] * fac[n - i] % P) %= P;
	}
	cout << res << endl;
	return 0;
}
/*
2 4
1 1 5
1 2 4
2 1 3
2 2 2
*/