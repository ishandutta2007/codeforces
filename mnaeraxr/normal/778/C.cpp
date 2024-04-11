#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 300000 + 10;

int go[maxn][26];
vector<pair<int,char>> adj[maxn];

pii ch[maxn];
int tot_ch;

int merge(int u, int v){
	int answer = 0;

	for (int i = 0; i < 26; ++i){
		if (go[u][i]){
			if (go[v][i])
				answer += 1 + merge(go[u][i], go[v][i]);
			else{
				go[v][i] = go[u][i];
				ch[ tot_ch++ ] = {v, i};
			}
		}
	}

	return answer;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n; cin >> n;

	for (int i = 0; i + 1 < n; ++i){
		int u, v; 
		char c;
		cin >> u >> v >> c;
		u--; v--;

		go[u][c - 'a'] = v;
		adj[u].push_back({v, c - 'a'});
	}

	vector<int> dist(n, oo);
	vector<int> par(n, -1);

	dist[0] = 0;

	vector<int> topsort(n);
	vector<int> size(n);
	int B = 0, E = 1;

	while (B < E){
		int u = topsort[ B++ ];

		for (auto e : adj[u]){
			dist[e.first] = dist[u] + 1;
			par[e.first] = u;

			topsort[ E++ ] = e.first;
		}
	}

	for (int i = n - 1; i; --i)
		size[ par[topsort[i]] ] += size[ topsort[i] ];

	int to_remove = 0, p = -1;

	for (int i = 1, j; i < n; i = j){
		int cur_remove = 0;

		for (j = i; j < n && dist[ topsort[i] ] == dist[ topsort[j] ]; ++j)
			cur_remove++;

		for (int a = i, b; a < j; a = b){
			int biggest = -1;

			for (b = a; b < j && par[ topsort[a] ] == par[ topsort[b] ]; ++b)
				if (biggest == -1 || size[ topsort[b] ] > size[ topsort[biggest] ])
					biggest = b;

			tot_ch = 0;

			for (b = a; b < j && par[ topsort[a] ] == par[ topsort[b] ]; ++b){
				if (b == biggest) continue;

				int cur_merge = merge(topsort[b], topsort[biggest]);
				// cout << "cur merge: " << topsort[b] << " " << topsort[biggest] << " " << cur_merge << endl;
				cur_remove += cur_merge;
			}

			for (int k = 0; k < tot_ch; ++k)
				go[ ch[k].first ][ ch[k].second ] = 0;
		}

		if (cur_remove > to_remove){
			to_remove = cur_remove;
			p = dist[ topsort[i] ];
		}
	}

	cout << n - to_remove << endl;
	cout << p << endl;

	return 0;
}