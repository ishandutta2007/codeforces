#include <bits/stdc++.h>
using namespace std;

#define N 110000

int n, m;
vector <int> ve[N];
int dep[N], fa[N][21];
bool used[N], special[N];
int dist[87][N], n1[N];
int far[87 * 2][N];
int len, ID[N];

int Time, L[N], R[N];

void dfs(int k) {
	L[k] = ++Time;
	dep[k] = dep[fa[k][0]] + 1;
	for (int i = 1; i <= 20; i++)
		fa[k][i] = fa[fa[k][i - 1]][i - 1];
	used[k] = true;
	for (auto x: ve[k])
		if (!used[x]) {
			fa[x][0] = k;
			dfs(x);
		}
	R[k] = Time;
}

int lca(int x, int y) {
	if (dep[x] < dep[y])
		swap(x, y);
	for (int i = 20; i >= 0; i--)
		if (dep[fa[x][i]] >= dep[y])
			x = fa[x][i];
	if (x == y)
		return x;
	for (int i = 20; i >= 0; i--)
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

void bfs(int s, int* dist) {
	for (int i = 1; i <= n; i++)
		dist[i] = 1e9;
	dist[s] = 0;
	int q = 1, h = 1;
	n1[q = h = 1] = s;
	while (q <= h) {
		for (auto x: ve[n1[q]]) {
			if (dist[x] > n) {
				h++;
				n1[h] = x;
				dist[x] = dist[n1[q]] + 1;
			}
		}
		q++;
	}
}

int st[N], ss[N], dd[N], size, st1[N];
bool in[N];
vector <int> V[N];
int go[N];

long long up_dist[N], up_t[N], down_dist[N], down_t[N];
long long ans = 0;

bool cmp(int x, int y) {
	return L[x] < L[y];
}


void dfs_d(int k) {
	for (auto x: V[k]) {
		dfs_d(x);
		dd[k] = min(dd[k], dd[x] + dep[x] - dep[k]);
	}
}

void dfs_u(int k) {
	for (auto x: V[k]) {
		dd[x] = min(dd[x], dd[k] + dep[x] - dep[k]);
		dfs_u(x);
	}
}

void ins(int k) {
	size++;
	int now = size - 1;
	while (now >= 1 && L[st[now]] > L[k]) {
		st[now + 1] = st[now];
		now--;
	}
	st[now + 1] = k;
}

void doit(int k) {
	size = 0;

	for (int i = 1; i <= st1[0]; i++) {
		st[++size] = st1[i];
		in[st1[i]] = true;
	}
	if (!in[k]) {
		ins(k);
		in[k] = true;
	}

	for (int i = 1; i <= size; i++) {
		if (st[i] == k) {
			if (i > 1) {
				int tmp = lca(k, st[i - 1]);
				if (!in[tmp]) {
					ins(tmp);
					in[tmp] = true;
				}
			}
			break;
		}
	}

	for (int i = 1; i <= size; i++) {
		if (st[i] == k) {
			if (i < size) {
				int tmp = lca(k, st[i + 1]);
				if (!in[tmp]) {
					ins(tmp);
					in[tmp] = true;
				}
			}
			break;
		}
	}

	ss[ss[0] = 1] = 1;
	for (int i = 2; i <= size; i++) {
		while (L[st[i]] > R[ss[ss[0]]])
			ss[0]--;
		V[ss[ss[0]]].push_back(st[i]);
		ss[++ss[0]] = st[i];
	}

	for (int i = 1; i <= size; i++)
		dd[st[i]] = 1e9;

	for (int i = 1; i <= len; i++)
		dd[ID[i]] = dist[i][k];
	dd[k] = 0;

	dfs_d(1);
	dfs_u(1);

	for (int i = 1; i <= size; i++) {
		down_dist[st[i]] += dd[st[i]];
		down_t[st[i]]++;
		for (auto j: V[st[i]]) {
			int x = j;
			if (!special[j]) {
				for (int k = 16; k >= 0; k--)
					if (dd[j] + dep[j] - dep[fa[x][k]] < dd[st[i]] + dep[fa[x][k]] - dep[st[i]])
						x = fa[x][k];
			}else {
				int DEP = (dd[j] - dd[st[i]] + dep[j] + dep[st[i]] + 1) / 2;
				if (DEP == dep[st[i]])
					DEP++;
				x = far[go[j]][DEP];
				// printf("?? %d %d %d\n", DEP, dep[j], dep[st[i]]);
			}
			down_dist[x] -= dd[st[i]] + dep[x] - dep[st[i]];
			down_t[x]--;
			up_dist[j] += dd[j];
			up_t[j]++;
			up_dist[x] -= dd[j] + dep[j] - dep[x];
			up_t[x]--;
		}
	}

	for (int i = 1; i <= size; i++)
		V[st[i]].clear(), in[st[i]] = false;
}

long long sum[N], sum_dep[N];

void DFS(int k, long long dist, long long s) {
	dist += down_dist[k];
	s += down_t[k];
	ans += dist;
	sum[k] = 1;
	sum_dep[k] = dep[k];

	for (auto x: ve[k])
		if (fa[x][0] == k) {
			DFS(x, dist + s, s);
			sum[k] += sum[x];
			sum_dep[k] += sum_dep[x];
		}
}

void DFS2(int k) {
	for (auto x: ve[k])
		if (fa[x][0] == k) {
			DFS2(x);
			ans += (up_dist[x] + up_t[x]) * sum[k] - (up_dist[x] + up_t[x]) * sum[x];
			ans += up_t[x] * (sum_dep[k] - sum_dep[x]) - up_t[x] * (sum[k] - sum[x]) * dep[k];
			up_dist[k] += up_dist[x] + up_t[x];
			up_t[k] += up_t[x];
		}
	// printf("%d %lld %lld\n", k, up_dist[k], up_t[k]);
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		ve[x].push_back(y);
		ve[y].push_back(x);
	}

	dfs(1);

	for (int i = 1; i <= n; i++)
		for (auto j: ve[i])
			if (i != fa[j][0] && j != fa[i][0])
				special[i] = special[j] = 1;
	for (int i = 1; i <= n; i++) {
		if (special[i]) {
			++len;
			ID[len] = i;
			bfs(i, dist[len]);
		}
	}

	size = 0;

	for (int i = 1; i <= len; i++) {
		st[++size] = ID[i];
		in[ID[i]] = true;
	}


	if (!in[1]) {
		st[++size] = 1;
		in[1] = true;
	}

	sort(st + 1, st + size + 1, cmp);
	for (int i = size - 1; i >= 1; i--) {
		int tmp = lca(st[i], st[i + 1]);
		if (!in[tmp])
			st[++size] = tmp, in[tmp] = true;
	}
	sort(st + 1, st + size + 1, cmp);

	st1[0] = size;
	for (int i = 1; i <= size; i++)
		st1[i] = st[i];


	for (int i = 1; i <= size; i++) {
		special[st1[i]] = true;
		go[st1[i]] = i;
		int now = st1[i];
		while (now) {
			far[i][dep[now]] = now;
			now = fa[now][0];
		}
	}

	for (int i = 1; i <= n; i++)
		doit(i);

	// for (int i = 1; i <= n; i++) {
	// 	printf("%lld %lld %lld %lld\n", down_dist[i], down_t[i], up_dist[i], up_t[i]);
	// }
	DFS(1, 0, 0);
	// cout << ans << endl;
	DFS2(1);

	cout << ans / 2 << endl;
}