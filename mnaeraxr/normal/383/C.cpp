#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;

int bit[maxn];

void update(int idx, int v){
	idx++;

	while (idx < maxn){
		bit[idx] += v;
		idx += idx & -idx;
	}
}

int query(int idx){
	idx++;

	int answer = 0;

	while (idx){
		answer += bit[idx];
		idx -= idx & -idx;
	}

	return answer;
}



typedef vector<vector<int>> graph;

struct heavy_light{
    int n, heavy[maxn], root[maxn], depth[maxn];
    int pos[maxn], ipos[maxn], parent[maxn];

    int dfs(int s, int f, graph &G){
        parent[s] = f, heavy[s] = -1;
        int size = 1, maxSubtree = 0;

        for (auto u : G[s]) if (u != f){
            depth[u] = depth[s] + 1;
            int subtree = dfs(u, s, G);

            if (subtree > maxSubtree)
                heavy[s] = u, maxSubtree = subtree;

            size += subtree;
        }

        return size;
    }

    void go(graph &G, int ROOT=0){
        n = (int)G.size();

        depth[ROOT] = 0;
        dfs(ROOT, -1, G);

        for (int i = 0, currentPos = 0; i < n; ++i)
            if (parent[i] == -1 || heavy[parent[i]] != i)
                for (int u = i; u != -1; u = heavy[u], currentPos++)
                    root[u] = i, pos[u] = currentPos, ipos[currentPos] = u;
    }

    int Q(int u){
    	int answer = 0;

    	for (; u != -1; u = parent[ root[u] ])
    		answer += query( pos[u] ) - query( pos[ root[u] ] - 1);

    	return answer;
    }
} HL;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	graph adj(n);

	for (int i = 0; i + 1 < n; ++i){
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	HL.go(adj);

	while (m--){
		int t; cin >> t;

		if (t == 1){
			int u, w;
			cin >> u >> w;
			u--;

			update(HL.pos[u], HL.depth[u] & 1 ? -w : w);
		}
		else{
			int u; cin >> u;
			u--;

			int answer = HL.Q(u);

			if (HL.depth[u] & 1)
				answer *= -1;

			answer += v[u];

			cout << answer << endl;
		}
	}

	return 0;
}