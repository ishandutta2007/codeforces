#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int64)((x).size())
#define MP make_pair

#define OBSTACLE '#'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int64> vi;

const int64 oo = 1LL << 60;
const double EPS = 1e-9;
const int64 MAXN = (int64)1e5 + 10;

bool dbg = false;

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
				flow_type delta = augment(e.dst, sink, min(flow, e.cap - e.flow));
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
		while (bfs(source, sink))
		{
			fill(it.begin(), it.end(), 0);
			for (flow_type f; (f = augment(source, sink, numeric_limits<flow_type>::max())) > 0;)
				flow += f;

		} // level[u] = -1 => source side of min cut
		return flow;
	}
};

struct scayger{
	int64 x, y, v;
};

int64 n, m, males, females;
char Map[30][30];
int64 ID[2][30][30];
int64 Dist[30][30][30][30];
int64 dx[4] = {0, 0, -1, 1};
int64 dy[4] = {1, -1, 0, 0};

bool valid(int64 x, int64 y){
	return 0 <= x && x < n && 0 <= y && y < m && Map[x][y] != OBSTACLE;
}

void bfs(int64 x, int64 y){
	for (int64 i = 0; i < n; ++i)
		for (int64 j = 0; j < m; ++j)
			Dist[x][y][i][j] = oo;

	Dist[x][y][x][y] = 0;
	queue<pii> Q;
	Q.push(MP(x,y));
	while (!Q.empty()){
		pii cur = Q.front(); Q.pop();
		int64 dst = Dist[x][y][cur.first][cur.second];
		for (int i = 0; i < 4; ++i){
			int64 nx = cur.first + dx[i], ny = cur.second + dy[i];
			if (valid(nx, ny) && Dist[x][y][nx][ny] > dst + 1){
				Dist[x][y][nx][ny] = dst + 1;
				Q.push(MP(nx,ny));
			}
		}
	}
}

bool myvalid(int64 v){
	return v != oo;
}

int main()
{
#ifdef HOME
	freopen("input.in", "r", stdin);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> males >> females;
	for (int64 i = 0; i < n; ++i){
		cin >> Map[i];
	}

	if (abs(males - females) != 1){
		cout << -1 << endl;
		return 0;
	}

	int64 vmax = 0;
	vector<scayger> vm, vf;

	scayger SB;
	cin >> SB.x >> SB.y >> SB.v;
	SB.x--; SB.y--;
	vmax = SB.v;

	if (males < females) vm.push_back( SB );
	else vf.push_back( SB );

	for (int64 i = 0; i < males; ++i){
		scayger cur;
		cin >> cur.x >> cur.y >> cur.v;
		cur.x--; cur.y--;
		vm.push_back( cur );
		vmax = max(vmax, cur.v);
	}

	for (int64 i = 0; i < females; ++i){
		scayger cur;
		cin >> cur.x >> cur.y >> cur.v;
		cur.x--; cur.y--;
		vf.push_back( cur );
		vmax = max(vmax, cur.v);
	}

	for (int64 i = 0; i < n; ++i){
		for (int64 j = 0; j < m; ++j){
			if (Map[i][j] != OBSTACLE)
				bfs(i,j);
		}
	}

	int64 lo = 0, hi = m * n * vmax + 1;
	int64 top = hi;

	for (int64 i = 0, cnt = 2 + 2 * SZ(vm); i < n; ++i)
		for (int64 j = 0; j < m; ++j)
			for (int64 k = 0; k < 2; ++k)
				ID[k][i][j] = cnt++;

	while (lo < hi){
		int64 mid = (lo + hi) >> 1;
		dbg = false;

		dinic<int64> flow(2 + 2 * SZ(vm) + 2 * n * m);

		for (int64 i = 0; i < SZ(vm); ++i){
			flow.add_edge(0, i + 2, 1);
			flow.add_edge(i + 2 + SZ(vm), 1, 1);
		}

		for (int64 i = 0; i < n; ++i){
			for (int64 j = 0; j < m; ++j){
				flow.add_edge(ID[0][i][j], ID[1][i][j], 1);
			}
		}

		for (int64 i = 0; i < SZ(vm); ++i){
			scayger cur1 = vm[i];
			scayger cur2 = vf[i];
			for (int64 j = 0; j < n; ++j){
				for (int64 k = 0; k < m; ++k){
					if (Map[j][k] == OBSTACLE) continue;
					if (dbg && !i) cout << "ID " << j << " " << k << " " << 2 + 2 * SZ(vm) + j * m + k << endl;

					if (myvalid(Dist[cur1.x][cur1.y][j][k]) && Dist[cur1.x][cur1.y][j][k] * cur1.v <= mid)
						flow.add_edge(i + 2, ID[0][j][k], 1);

					if (myvalid(Dist[cur2.x][cur2.y][j][k]) && Dist[cur2.x][cur2.y][j][k] * cur2.v <= mid)
						flow.add_edge(ID[1][j][k], 2 + SZ(vm) + i, 1);
				}
			}
		}

		int64 value = flow.max_flow(0, 1);

		if (value == SZ(vm)) hi = mid;
		else lo = mid + 1;
	}

	if (hi == top)
		cout << -1 << endl;
	else
		cout << hi << endl;

	return 0;
}