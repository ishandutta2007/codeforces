#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int64 MOD = (int64)1e9 + 7;

struct Graph{
	int n, tcc;
	vector<vi> ady;
	vi color, cc;

	Graph(int nodes){
		n = nodes, tcc = 0;
		ady = vector<vi>(n + 1);
		color = vi(n + 1), cc = vi(n + 1);
	}

	void addEdge(int u, int v){
		ady[u].push_back(v);
		ady[v].push_back(u);
	}

	bool dfs(int s, int col, Graph &other){
		color[s] = col;
		for (auto v : ady[s])
		{
			if (!color[v]){
				if (other.cc[s] == other.cc[v])
				{
					if (!dfs(v, col, other))
						return false;
				}
				else{
					if (!dfs(v, 3 - col, other))
						return false;
				}
			}
			else{
				if (other.cc[s] != other.cc[v] && color[s] == color[v])
					return false;
				if (other.cc[s] == other.cc[v] && color[s] != color[v])
					return false;
			}
		}
		for (auto v : other.ady[s]){
			if (!color[v]){
				if (other.cc[s] == other.cc[v])
				{
					if (!dfs(v, col, other))
						return false;
				}
				else{
					if (!dfs(v, 3 - col, other))
						return false;
				}
			}
			else{
				if (other.cc[s] != other.cc[v] && color[s] == color[v])
					return false;
				if (other.cc[s] == other.cc[v] && color[s] != color[v])
					return false;
			}
		}
		return true;
	}

	bool isBipartite(Graph &other){
		for (int i = 1; i <= n; ++i){
			if (!color[i]){
				if (!dfs(i, 1, other)){
					return false;
				}
			}
		}
		return true;
	}

	void makecc(int v, int c){
		cc[v] = c;
		for (auto t : ady[v]){
			if (!cc[t]) makecc(t, c);
		}
	}

	void buildCC(){
		for (int i = 1; i <= n; ++i){
			if (!cc[i]) makecc(i, ++tcc);
		}
	}
};

int64 modexp(int64 v, int64 p){
	if (!p) return 1;
	int64 ans = modexp(v * v % MOD, p / 2);
	if (p & 1) ans = ans * v % MOD;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	Graph red(n), blue(n), both(n);
	for (int i = 0; i < m; ++i){
		int a, b, c;
		cin >> a >> b >> c;

		if (c) blue.addEdge(a, b);
		else red.addEdge(a, b);
		both.addEdge(a, b);
	}

	blue.buildCC();

	if (!red.isBipartite(blue)){
		cout << 0 << endl;
		exit(0);
	}

	for (int i = 1; i <= n; ++i){
		for (auto t : red.ady[i]){
			if (blue.cc[i] == blue.cc[t]){
				cout << 0 << endl;
				exit(0);
			}
		}
	}

	both.buildCC();

	cout << modexp(2, both.tcc - 1) << endl;

	return 0;
}