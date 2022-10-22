#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define i64 long long
#define x first
#define y second
#define PI pair<int, int>
using namespace std;
const int N = 1e5 + 10, M = 1e7 + 10;
int mu[M], vis[M], p[M], pre[M], tot = 0;
vector<int> id[M];
int n, k, cnt[M], a[N], b[N], tota = 0, totb = 0;
int fact[N], totf = 0, fac[N], pk[N];
vector<int> d[M], to[M];
void sieve(int n) {
	mu[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) p[++tot] = i, mu[i] = -1, pre[i] = 1;
		for(int j = 1; j <= tot && i * p[j] <= n; j++) {
			vis[i * p[j]] = 1;
			pre[i * p[j]] = i;
			if(i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			}
			mu[i * p[j]] = - mu[i];
		}
	}
	return;
}

void dfs(int now, int num) {
	if(now ==  tot + 1) {
		fact[++totf] = num;
		return;
	}
	for(int i = 0; i <= pk[now]; i++) {
		dfs(now + 1, num);
		num *= fac[now];
	}
	return;
}

void add(int x, int t) {
	for(int fac : d[x]) {
		vis[fac] += t;
	}
	return;
}

i64 ask(int x) {
	i64 ans = 0;
	for(int fac : d[x]) {
		ans += mu[fac] * vis[fac];
	}
	return ans;
}

void factor(int n) {
	tot = 0;
	for(; n > 1; fac[++tot] = n / pre[n], n = pre[n]);
	int ttot = 0;
	for(int i = 1; i <= tot; i++) {
		if(fac[ttot] != fac[i]) fac[++ttot] = fac[i], pk[ttot] = 1;
		else pk[ttot]++;
	}
	tot = ttot;
	totf = 0;
	dfs(1, 1);
	return;
}

void divide(int l, int r, vector<int> g) {
	if(l == r) {
		for(int x : g) {
			to[a[l]].insert(to[a[l]].end(), id[x].begin(), id[x].end());
		}
		return;
	}
	int mid = (l + r) / 2;
	for(int i = l; i <= mid; i++) add(a[i], 1);
	vector<int> L, R;
	for(int i = 0; i < sz(g); i++) {
		if(ask(g[i])) L.push_back(g[i]);
		else R.push_back(g[i]);
	}
	for(int i = l; i <= mid; i++) add(a[i], -1);
	divide(l, mid, L), divide(mid + 1, r, R);
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	sieve(M - 10);
	cin >> n >> k;
	for(int i = 1, x; i <= n; i++) {
		cin >> x;
		cnt[x]++;
		id[x].push_back(i);
	}
	memset(vis, 0, sizeof(vis));
	vector<int> b;
	for(int i = 1; i <= M - 10; i++) {
		if(cnt[i] == 0) continue;
		factor(i);
		d[i].resize(totf);
		copy(fact + 1, fact + totf + 1, d[i].begin());
		if(ask(i) == 0) {
			a[++tota] = i;
			add(i, 1);
		} else {
			b.push_back(i);
		}
	}
	for(int i = 1; i <= tota; i++) add(a[i], -1);
	int sa = 0;
	for(int i = 1; i <= tota; i++) sa += cnt[a[i]];
	if(sa >= k) {
		tot = 0;
		for(int i = 1; i <= tota; i++) {
			for(int x : id[a[i]]) {
				cout << x <<" ";
				tot++;
				if(tot == k) break;
			}
			if(tot == k) break;
		}
		cout << endl;
		return 0; 
	}
	divide(1, tota, b);
	sort(a + 1, a + tota + 1, [&](int x, int y) {
		return sz(to[x]) < sz(to[y]); 
	});
	tot = 0;
	vector<int> ans;
	for(int i = 1; i <= tota; i++) {
		if(to[a[i]].empty()) continue;
		if(tot + sz(to[a[tota]]) + 1 >= k) {
			if(k - tot == 1) {
				ans.pop_back();
				tot--;
			}
			ans.push_back(id[a[tota]].back());
			ans.insert(ans.end(), to[a[tota]].begin(), to[a[tota]].begin() + k - tot - 1);
			tot = k;
		}
		if(tot + sz(to[a[i]]) + 1 < k) {
			ans.push_back(id[a[i]].back());
			ans.insert(ans.end(), to[a[i]].begin(), to[a[i]].end());
			tot += sz(to[a[i]]) + 1;
		}
		if(tot == k) break;
	}
	for(int x : ans) cout << x <<" ";
	cout << endl;
	return 0;
}