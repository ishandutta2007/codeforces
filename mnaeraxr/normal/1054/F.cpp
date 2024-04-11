#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;

struct line{
    int x0, y0, x1, y1;
};

bool intersect(line h, line v){
    return v.x0 < h.x0 && h.x0 < v.x1 &&
           h.y0 < v.y0 && v.y0 < h.y1;
}

template<typename flow_type>
struct dinic
{
	struct edge
	{
		size_t src, dst, rev;
		flow_type flow, cap;
	};

	int n;
	vector<vector<edge>> adj;

	dinic(int n) : n(n), adj(n), level(n), q(n), it(n) {}

	void add_edge(size_t src, size_t dst, flow_type cap, flow_type rcap = 0)
	{
		// cout << src << " " << dst << endl;
		adj[src].push_back({src, dst, adj[dst].size(), 0, cap});
		if (src == dst) adj[src].back().rev++;
		adj[dst].push_back({dst, src, adj[src].size() - 1, 0, rcap});
	}

	vector<int> level, q, it;

	bool bfs(int source, int sink)
	{
		fill(level.begin(), level.end(), -1);
		for (int qf = level[q[0] = sink] = 0, qb = 1; qf < qb; ++qf)
		{
			sink = q[qf];
			for (edge &e : adj[sink])
			{
				edge &r = adj[e.dst][e.rev];
				if (r.flow < r.cap && level[e.dst] == -1)
					level[q[qb++] = e.dst] = 1 + level[sink];
			}
		}
		return level[source] != -1;
	}

	flow_type augment(int source, int sink, flow_type flow)
	{
		if (source == sink) return flow;
		for (; it[source] != adj[source].size(); ++it[source])
		{
			edge &e = adj[source][it[source]];
			if (e.flow < e.cap && level[e.dst] + 1 == level[source])
			{
				flow_type delta = augment(e.dst, sink,
								  min(flow, e.cap - e.flow));
				if (delta > 0)
				{
					e.flow += delta;
					adj[e.dst][e.rev].flow -= delta;
					return delta;
				}
			}
		}
		return 0;
	}

	flow_type max_flow(int source, int sink)
	{
		for (int u = 0; u < n; ++u)
			for (edge &e : adj[u]) e.flow = 0;
		flow_type flow = 0;
		flow_type oo = numeric_limits<flow_type>::max();

		while (bfs(source, sink))
		{
			fill(it.begin(), it.end(), 0);
			for (flow_type f; (f = augment(source, sink, oo)) > 0;)
				flow += f;

		} // level[u] = -1 => source side of min cut
		return flow;
	}
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    map<int, vector<int>> X, Y;

    for (int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        X[x].push_back(y);
        Y[y].push_back(x);
    }

    vector<line> H, V;

    for (auto &xx : X){
        int x = xx.first;
        sort(xx.second.begin(), xx.second.end());
        for (int i = 1; i < (int)xx.second.size(); ++i){
            int y0 = xx.second[i - 1], y1 = xx.second[i];
            H.push_back({x, y0, x, y1});
        }
    }

    for (auto &yy : Y){
        int y = yy.first;
        sort(yy.second.begin(), yy.second.end());
        for (int i = 1; i < (int)yy.second.size(); ++i){
            int x0 = yy.second[i - 1], x1 = yy.second[i];
            V.push_back({x0, y, x1, y});
        }
    }

    int N = H.size() + V.size() + 2;

	// cout << "hor" << endl;
	// for (auto hh : H)
	// 	cout << hh.x0 << " " << hh.y0 << " " << hh.x1 << " " << hh.y1 << endl;
	// cout << "ver" << endl;
	// for (auto hh : V)
	// 	cout << hh.x0 << " " << hh.y0 << " " << hh.x1 << " " << hh.y1 << endl;

    dinic<int> g(N);
    int hsize = H.size();

    for (int i = 0; i < (int)H.size(); ++i){
        g.add_edge(0, i + 2, 1);

        for (int j = 0; j < (int)V.size(); ++j){
            if (intersect(H[i], V[j])){
                g.add_edge(i + 2, j + hsize + 2, 1);
            }
        }
    }

	for (int j = 0; j < (int)V.size(); ++j)
		g.add_edge(j + hsize + 2, 1, 1);

    int ans = g.max_flow(0, 1);

    vector<bool> okH(H.size()), okV(V.size());

    int hor = n, ver = n;

    for (int i = 2; i < N; ++i){
        if (i < 2 + hsize){
            if (g.level[i] == -1){
                okH[i - 2] = true;
                hor--;
            }
        }
        else{
            if (g.level[i] != -1){
                okV[i - 2 - hsize] = true;
                ver--;
            }
        }
    }

    cout << ver << endl;
	for (int i = 0, j; i < V.size(); i = j){
		vector<int> xlist;
		xlist.push_back(V[i].x0);

		for (j = i; j < (int)V.size() && V[j].y0 == V[i].y0; ++j){
			if (!okV[j]){
				xlist.push_back(V[j].x0);
				xlist.push_back(V[j].x1);
			}
		}

		xlist.push_back(V[j - 1].x1);
		int y = V[i].y0;

		for (int k = 0; k < (int)xlist.size(); k += 2){
			cout << xlist[k] << " " << y << " " << xlist[k + 1] << " " << y << endl;
		}
	}

	for (auto t : Y){
		if (t.second.size() == 1)
			cout << t.second[0] << " " << t.first << " " << t.second[0] << " " << t.first << endl;
	}

    cout << hor << endl;
	for (int i = 0, j; i < H.size(); i = j){
		vector<int> ylist;
		ylist.push_back(H[i].y0);

		for (j = i; j < (int)H.size() && H[j].x0 == H[i].x0; ++j){
			if (!okH[j]){
				ylist.push_back(H[j].y0);
				ylist.push_back(H[j].y1);
			}
		}
		ylist.push_back(H[j - 1].y1);
		int x = H[i].x0;

		for (int k = 0; k < (int)ylist.size(); k += 2){
			cout << x << " " << ylist[k] << " " << x << " " << ylist[k + 1] << endl;
		}
	}

	for (auto t : X){
		if (t.second.size() == 1)
			cout << t.first << " " << t.second[0] << " " << t.first << " " << t.second[0] << endl;
	}
}