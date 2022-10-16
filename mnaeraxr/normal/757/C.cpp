#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000000 + 10;
const int64 mod = 1000000007;

int seen[maxn];
int cnt[maxn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, m; cin >> n >> m;
	vector<vector<pii>> V(m);

	for (int i = 0; i < n; ++i){
		int tot; cin >> tot;

		vector<int> cur;

		for (int j = 0; j < tot; ++j){
			int v; cin >> v;
			v--;

			if (seen[v] != i + 1){
				seen[v] = i + 1;
				cnt[v] = 0;
				cur.push_back(v);
			}

			cnt[v]++;
		}

		for (auto v : cur)
			V[v].push_back({i, cnt[v]});
	}

	sort(V.begin(), V.end());

	vector<int64> F(m + 1);
	F[0] = 1;
	for (int i = 1; i <= m; ++i)
		F[i] = F[i - 1] * i % mod;


	int64 answer = 1;

	int cnt = 1;

	for (int i = 1; i < m; ++i){
		if (V[i] != V[i - 1]){
			answer = answer * F[cnt] % mod;
			cnt = 0;
		}
		cnt++;
	}

	answer = answer * F[cnt] % mod;

	cout << answer << endl;

	return 0;
}