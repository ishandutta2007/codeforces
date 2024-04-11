#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

bool F[MAXN];
int dg[MAXN], ng[MAXN];
vi ady[MAXN];
int n, m, k;
int q[MAXN], b, e;
bool mk[MAXN];

bool solve(double value){
	b = 0, e = 0;
	for (int i = 1; i <= n; ++i){
		dg[i] = ng[i];
		if (F[i]){
			q[e++] = i;
			mk[i] = true;
		}
		else
			mk[i] = false;
	}

	while (b < e){
		int u = q[b++];
		for (auto nxt : ady[u]){
			if (mk[nxt]) continue;
			dg[nxt]--;
			if (1.0 * dg[nxt] < ng[nxt] * value){
				q[e++] = nxt;
				mk[nxt] = true;
			}
		}
	}

	return e < n;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < k; ++i){
		int v; cin >> v;
		F[v] = true;
	}

	for (int i = 0; i < m; ++i){
		int u, v; cin >> u >> v;
		ady[u].push_back(v);
		ady[v].push_back(u);
		ng[u]++; ng[v]++;
	}

	double lo = 0, hi = 1.01;

	for (int i = 0; i < 100; ++i){
		double mid = (lo + hi) / 2;
		if (solve(mid)) lo = mid;
		else hi = mid;
	}

	solve(lo);

	int tot = 0;
	for (int i = 1; i <= n; ++i)
		if (!mk[i]) ++tot;

	cout << tot << endl;
	for (int i = 1; i <= n; ++i)
		if (!mk[i]) cout << i << " ";
	cout << endl;

	return 0;
}