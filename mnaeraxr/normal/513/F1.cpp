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

struct Edge
{
	int64 from, to, cap, flow, index;

	Edge(int64 from, int64 to, int64 cap, int64 flow, int64 index) :
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic
{
	int64 N;
	vector< vector<Edge> > G;
	vector<Edge*> dad;
	vector<int64> Q;

	Dinic(int64 N) : N(N), G(N), dad(N), Q(N) {}

	void AddEdge(int64 from, int64 to, int64 cap)
	{
		if (dbg) cout << from << " " << to << " " << cap << endl;
		G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
		if(from == to) G[from].back().index++;
		G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
	}

	long long BlockingFlow(int64 s, int64 t)
	{
		fill(dad.begin(),dad.end(),(Edge*) NULL);
		dad[s] = &G[0][0] - 1;

		int64 head = 0, tail = 0;
		Q[tail++] = s;

		while(head < tail)
		{
			int64 x = Q[head++];

			for(int64 i = 0; i < (int64) G[x].size(); ++i)
			{
				Edge &e = G[x][i];

				if(!dad[e.to] && e.cap - e.flow > 0)
				{
					dad[e.to] = &G[x][i];
					Q[tail++] = e.to;
				}
			}
		}

		if(!dad[t]) return 0;

		long long totflow = 0;

		for(int64 i = 0; i < (int64) G[t].size(); ++i)
		{
			Edge *start = &G[G[t][i].to][G[t][i].index];
			int64 amt = oo;

			for(Edge *e = start; amt && e != dad[s]; e = dad[e->from])
			{
				if(!e) { amt = 0; break; }
				amt = min(amt,e->cap - e->flow);
			}

			if(amt == 0) continue;

			for(Edge *e = start; amt && e != dad[s]; e = dad[e->from])
			{
				e->flow += amt;
				G[e->to][e->index].flow -= amt;
			}

			totflow += amt;
		}

		return totflow;
	}

	long long GetMaxFlow(int64 s, int64 t)
	{
		long long totflow = 0;

		while(long long flow = BlockingFlow(s,t))
			totflow += flow;

		return totflow;
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

		Dinic flow(2 + 2 * SZ(vm) + 2 * n * m);

		for (int64 i = 0; i < SZ(vm); ++i){
			flow.AddEdge(0, i + 2, 1);
			flow.AddEdge(i + 2 + SZ(vm), 1, 1);
		}

		for (int64 i = 0; i < n; ++i){
			for (int64 j = 0; j < m; ++j){
				flow.AddEdge(ID[0][i][j], ID[1][i][j], 1);
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
						flow.AddEdge(i + 2, ID[0][j][k], 1);

					if (myvalid(Dist[cur2.x][cur2.y][j][k]) && Dist[cur2.x][cur2.y][j][k] * cur2.v <= mid)
						flow.AddEdge(ID[1][j][k], 2 + SZ(vm) + i, 1);
				}
			}
		}

		int64 value = flow.GetMaxFlow(0, 1);

		if (value == SZ(vm)) hi = mid;
		else lo = mid + 1;
	}

	if (hi == top)
		cout << -1 << endl;
	else
		cout << hi << endl;

	return 0;
}