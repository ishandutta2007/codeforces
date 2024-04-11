#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e6 + 10;

int L[MAXN];

struct edge{
	int from, to, idx;
};

vector<edge> E[MAXN];
int R[MAXN], T[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int mx = 0;
	for (int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		E[w].push_back({u, v, i});
		mx = max(mx, w);
	}

	int ans = 0;

	for (int i = mx; i; --i){
		for (auto e : E[i]){
			T[e.from] = max(T[e.from], R[e.to] + 1);
			ans = max(T[e.from], ans);
		}
		for (auto e : E[i])
			R[e.from] = max(T[e.from], R[e.from]);
	}

	cout << ans << endl;

	return 0;
}