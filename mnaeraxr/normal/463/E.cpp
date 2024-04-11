#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MAXA = 2000100;
const int MAXN = 100010;

int n, q;
vi ady[MAXN];
int p[MAXA];
pii s[MAXA];
pii ans[MAXN];
int v[MAXN], f[MAXN];
int counter_n;

void sieve(){
	p[1] = 1;
	for (int64 i = 2; i < MAXA; ++i){
		if (p[i]) continue;
		p[i] = i;
		for (int64 j = i * i; j < MAXA; j += i)
			p[j] = i;
	}
}

void dfs(int idx, int level){
	int cur = v[idx];
	vector<pii> rk;
	while (cur > 1){
		int pr = p[cur];

		if (s[pr].first) ans[idx] = max(ans[idx], s[pr]);
		
		rk.push_back(s[pr]);
		s[pr] = {level, idx};

		while (cur % pr == 0)
			cur /= pr;
	}
	for (auto e : ady[idx]){
		if (!f[e]){
			f[e] = idx;
			dfs(e, level + 1);
		}
	}
	cur = v[idx];
	int pnt = 0;
	while (cur > 1){
		int pr = p[cur];
		s[pr] = rk[pnt++];
		while (cur % pr == 0) cur /= pr;
	}
}

void build(){
	for (int i = 1; i <= n; ++i)
		ans[i] = (pii){0, -1}, f[i] = 0;
	memset(s, 0, sizeof s);

	f[1] = -1;
	dfs(1, 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	sieve();

	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	for (int i = 1; i < n; ++i){
		int tu, tv;
		cin >> tu >> tv;
		ady[tu].push_back(tv);
		ady[tv].push_back(tu);
	}

	build();

	while (q--){
		int m; cin >> m;
		if (m == 1){
			int rv; cin >> rv;
			cout << ans[rv].second << endl;
		}
		else{
			int idx, rv;
			cin >> idx >> rv;
			v[idx] = rv;
			build();
		}
	}

	return 0;
}