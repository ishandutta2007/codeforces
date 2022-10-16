#include <bits/stdc++.h>

using namespace std;

const int maxn = 3000;

int value[ maxn ], total;
vector<int> adj[ maxn ];

int child0(int u){
    return adj[u][ (int)adj[u].size() - 2 ];
}

int child1(int u){
    return adj[u][ (int)adj[u].size() - 1 ];
}

bool mk[maxn];
int q[maxn], p[maxn], sz[maxn], mc[maxn];

int centroid(int c){
    int b = 0, e = 0;
    q[e++] = c, p[c] = -1, sz[c] = 1, mc[c] = 0;

    while (b < e){
        int u = q[b++];
        for (auto v : adj[u]) if (v != p[u] && !mk[v])
                p[v] = u, sz[v] = 1, mc[v] = 0, q[e++] = v;
    }

    for (int i = e - 1; ~i; --i){
        int u = q[i];
        int bc = max(e - sz[u], mc[u]);
        if (2 * bc <= e) return u;
        sz[p[u]] += sz[u], mc[p[u]] = max(mc[p[u]], sz[u]);
    }

    assert(false);
    return -1;
}

int find_node(int s, int p){
    if (value[s] != 0)
        return value[s];

    for (auto u : adj[s]) if (u != p)
        return find_node(u, s);

    assert( false );
    return -1;
}

int how_many(int s){
	vector<int> q = {s};
	set<int> vis; vis.insert( s );
	int p = 0;

	while (p < (int)q.size() && q.size() < 3){
		int u = q[p++];

		for (auto v : adj[u]){
			if (mk[v] || vis.count(v) ) continue;
			q.push_back( v );
			vis.insert( v );
		}
	}

	return q.size();
}

void create(int s, int c, int u){
	int a = total++;
	int b = total++;
	adj[c][0] = a;
	for (auto &v : adj[s])
		if (v == c) 
			v = a;
	adj[a] = {s, c, b};
	adj[b] = {a};
	value[b] = u;
}

void add(int u){
//    cout << "Add: " << u << endl;

    int s = 0;
    memset(mk, 0, sizeof mk);

    while (adj[s].size() > 1){
	int c = centroid(s);

	if (how_many(s) == 2){
		if (adj[s].size() == 1)
			s = adj[s][0];
		c = s;
	}
	
	//cout << "start: " << s << endl;
	//cout << "centroid: " << c << endl;

        int c0 = child0( c );
        int c1 = child1( c );

        int u0 = find_node( c0, c );
        int u1 = find_node( c1, c );

        cout << u << " " << u0 << " " << u1 << endl;
        string side; cin >> side;

        if (side == "X"){
            // u0
            mk[ c ] = true;
            s = c0;

	    if (mk[s]){
		    create(c, s, u);
		    return;
	    }
        }
        else if (side == "Y"){
            // p
            if (adj[c].size() == 2){
                int v = total++;
                adj[v].push_back(c);
                adj[c].push_back(v);
                swap( adj[c][0], adj[c][2] );

                int w = total++;
                adj[w].push_back(v);
                adj[v].push_back(w);
                value[w] = u;
                return;
            }
            mk[ c ] = true;
            s = adj[c][0];

	    if (mk[s]){
		    create(s, c, u);
		    return;
	    }
        }
        else{ // side == "Z"
            // u1
            mk[ c ] = true;
            s = c1;
	
	    if (mk[s]){
	    	create(c, s, u);
		return;
	    }
        }
    }

    int a = total++;
    int b = total++;

    value[a] = value[s];
    value[s] = 0;
    value[b] = u;

    adj[s].push_back(a);
    adj[s].push_back(b);
    adj[a].push_back(s);
    adj[b].push_back(s);
}

int parent[ maxn ];

void dfs(int s, int p){
    parent[s] = p;
    for (auto u : adj[s]){
        if (u == p) continue;
        dfs(u, s);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    total = 1;
    value[0] = 1;

    int n; cin >> n;

    for (int i = 2; i <= n; ++i){
        add(i);
/*
        for (int j = 0; j < total; ++j){
            cout << j << " :: " << value[j] << " :: ";
            for (auto u : adj[j]) cout << u << " ";
            cout << endl;
        }
*/
    }

    assert( total == 2 * n - 1 );

    int root = 0;
    while (adj[root].size() != 2)
        root++;

    dfs(root, -2);

    cout << -1 << endl;
    for (int i = 0; i < total; ++i)
        cout << parent[i] + 1 << " ";
    cout << endl;

    return 0;
}