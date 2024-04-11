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
const int MAXN = (int)1e5 + 10;

struct Graph{
	vector<vi> ady;
	vi C, F, color;
	int tot, M;
	int tot_edge;
	int64 same_color;

	Graph(int TOT){
		tot = TOT, M = 1;
		tot_edge = 0;
		same_color = 0;

		C = vi(TOT + 1);
		F = vi(TOT + 1);
		color = vi(TOT + 1);
		ady = vector<vi>(TOT + 1);

		for (int i = 1; i <= tot; ++i)
			C[i] = 1, F[i] = i;
	}

	int root(int a){
		return a == F[a] ? a : F[a] = root(F[a]);
	}

	bool join(int a, int b){
		a = root(a), b = root(b);
		if (a == b) return false;
		if (C[a] > C[b]) swap(a, b);
		C[b] += C[a];
		F[a] = b;
		return true;
	}

	void addEdge(int u, int v){
		ady[u].push_back(v);
		ady[v].push_back(u);
		join(u, v);
		M = max(M, C[root(u)]);
		tot_edge++;
	}

	bool paint(int s, int c, vi &T){
		color[s] = c;
		T[c]++;
		for (auto nxt : ady[s]){
			if (!color[nxt]){
				if (!paint(nxt, 3 - c, T))
					return false;
			}
			else{
				if (color[nxt] == c) return false;
			}
		}
		return true;
	}

	bool isBipartite(){
		for (int i = 1; i <= tot; ++i){
			if (!color[i]){
				vector<int> T(3);
				if (!paint(i, 1, T))
					return false;
				same_color += 1LL * T[1] * (T[1] - 1) / 2 + 1LL * T[2] * (T[2] - 1) / 2;
			}
		}
		return true;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	Graph G(n);
	set<pii> S;

	for (int i = 0; i < m; ++i){
		int u, v; cin >> u >> v;
		if (u == v) continue;
		pii cur = MP(min(u, v), max(u, v));
		if (S.count(cur)) continue;
		S.insert(cur);
		G.addEdge(u, v);
	}

	if (!G.isBipartite()){
		cout << 0 << " " << 1 << endl;
	}
	else{
		if (G.M == 1){
			int64 ans = 1LL * n * (n - 1) * (n - 2) / 6;
			cout << 3 << " " << ans << endl;
		}
		else if (G.M == 2){
			int64 ans = 1LL * G.tot_edge * (n - 2);
			cout << 2 << " " << ans << endl;
		}
		else{
			int64 ans = G.same_color;
			cout << 1 << " " << ans << endl;
		}
	}

	return 0;
}