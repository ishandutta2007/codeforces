#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;
const int64 mod = 1000000007;
const int maxbit = 60;

vector<int64> base;
vector<pii> freq, counted;
int64 pow2[maxbit + 1];

void prec(){
	pow2[0] = 1;
	for (int i = 1; i <= maxbit; ++i)
		pow2[i] = pow2[i - 1] * 2 % mod;
}

void init(){
	base = vector<int64>(maxbit);
	freq = vector<pii>(maxbit);
}

void push(int64 v){
	while (v){
		int64 l = __lg(v);
		if (base[l]) v ^= base[l];
		else{
			base[l] = v;
			break;
		}
	}
}

vector<pii> count(){
	vector<pii> tot(maxbit);
	vector<pii> ans(maxbit);

	for (int i = 0; i < maxbit; ++i){
		if (!base[i]) continue;

		for (int j = 0; j < maxbit; ++j)
			if (base[i] >> j & 1) tot[j].first++;
			else tot[j].second++;
	}

	for (int i = 0; i < maxbit; ++i){
		int64 a = tot[i].first, b = tot[i].second;
		ans[i].first = a ? pow2[a + b - 1] : 0;
		ans[i].second = (pow2[a + b] - ans[i].first + mod) % mod;
	}

	return ans;
}

vector<pii> adj[maxn];
vector<int> tree[maxn];
int64 X[maxn];
bool vis[maxn];

int64 answer = 0;

void dfs(int s){

	vis[s] = true;
	for (auto e : adj[s]){
		int64 u = e.first, x = e.second;
		if (vis[u]){
			push(X[s] ^ X[u] ^ x);
		}
		else{
			tree[s].push_back(u);
			X[u] = X[s] ^ x;
			dfs(u);
		}
	}
}

void calc(int s){
	int64 current = 0;

	for (int i = 0; i < maxbit; ++i){
		int64 tmp = 0;
		if (X[s] >> i & 1){
			tmp = (tmp + freq[i].second * counted[i].second % mod) % mod;
			tmp = (tmp + freq[i].first * counted[i].first % mod) % mod;
			freq[i].first++;
		}
		else{
			tmp = (tmp + freq[i].first * counted[i].second % mod) % mod;
			tmp = (tmp + freq[i].second * counted[i].first % mod) % mod;
			freq[i].second++;
		}
		current = (current + pow2[i] * tmp % mod) % mod;
	}

	answer = (answer + current) % mod;

	for (auto u : tree[s])
		calc(u);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	prec();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i){
		int u, v; int64 x; cin >> u >> v >> x;
		adj[u].push_back({v, x});
		adj[v].push_back({u, x});
	}

	for (int i = 1; i <= n; ++i){
		if (vis[i]) continue;

		init();
		dfs(i);
		counted = count();

		calc(i);
	}

	cout << answer << endl;

	return 0;
}