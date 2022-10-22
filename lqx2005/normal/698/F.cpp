#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define sz(a) int((a).size())
#define pi pair<int, int>
#define i64 long long
#define u64 unsigned long long
#define u128 __int128
using namespace std;
const int N = 1e6 + 10, P = 1e9 + 7;
int n, a[N];
int vis[N], p[N], minp[N], tot = 0;
int order[N], id[N], cnt[N], ocnt[N], in[N], out[N], all[N];
vector<int> fac[N], g[N * 2];
void sieve(int n) {
	vis[1] = 0;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) p[++tot] = i, minp[i] = i;
		for(int j = 1; j <= tot && i * p[j] <= n; j++) {
			vis[i * p[j]] = 1;
			minp[i * p[j]] = p[j];
			if(i % p[j] == 0) break;
		}
	}
	return;
}

vector<int> factor(int n) {
	vector<int> p, q;
	for(; n > 1; p.push_back(minp[n]), n /= minp[n]);
	for(int x : p) if(q.empty() || q.back() != x) q.push_back(x);
	return q;
}

void quit() {
	cout << 0 << endl;
	exit(0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    sieve(n);
    for(int i = 1; i <= n; i++) {
    	order[i] = i;
    	fac[i] = factor(i);
	}
	sort(order + 1, order + n + 1, [&](int x, int y) {
		return fac[x] < fac[y];
	});
	int now = 0;
	g[++now].push_back(order[1]);
	id[order[1]] = now;
	for(int i = 2; i <= n; i++) {
		if(fac[order[i - 1]] != fac[order[i]]) now++;
		g[now].push_back(order[i]);
		id[order[i]] = now;
	}
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
	}
	for(int i = 1; i <= tot; i++) {
		ocnt[n / p[i]]++;
		if(p[i] * 2 > n) all[p[i]] = 1;
	}
	ocnt[1]++;
	all[1] = 1;
    for(int i = 1; i <= n; i++) {
    	if(a[i]) {
    		if(all[a[i]]) {
    			if(!all[i]) quit();
    			ocnt[1]--;
    			continue;
			}
    		if(sz(fac[a[i]]) != sz(fac[i])) quit();
			for(int j = 0; j < sz(fac[a[i]]); j++) {
				int x = fac[a[i]][j], y = fac[i][j];
				if(n / x != n / y) quit();
				if(in[x] && in[x] != y) quit();
				if(out[y] && out[y] != x) quit();
				in[x] = y;
				out[y] = x;
			}
		}
	}
	for(int i = 1; i <= tot && p[i] * 2 <= n; i++) {
		if(out[p[i]]) {
			ocnt[n / p[i]]--;
		}
	}
	for(int i = 1; i <= n; i++) if(a[i]) cnt[id[a[i]]]++;
	int ans = 1;
	for(int i = 1; i <= now; i++) {
		for(int j = 1; j <= sz(g[i]) - cnt[i]; j++) {
			ans = 1ll * ans * j % P;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= ocnt[i]; j++) {
			ans = 1ll * ans * j % P; 
		}
	}
	cout << ans << endl;
    return 0;
}