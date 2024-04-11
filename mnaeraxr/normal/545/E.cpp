#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)3e5 + 10;

vector<pii> ady[MAXN];
int64 W[MAXN];
int64 dist[MAXN];
bool mk[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; ++i){
		int u, v;
		cin >> u >> v >> W[i];
		ady[u].push_back(MP(v, i));
		ady[v].push_back(MP(u, i));
	}

	int s; cin >> s;
	vector<int> edges;

	memset(dist, oo, sizeof dist);
	priority_queue<pair<pair<int64,int64>,pii>> PQ;
	PQ.push(MP(MP(0,0), MP(s,-1)));
	dist[s] = 0;

	int64 sum = 0;

	while (!PQ.empty()){
		auto cur = PQ.top(); PQ.pop();
		int64 d = -cur.first.first;
		int nd = cur.second.first;
		int ed = cur.second.second;

//		DB(nd);
//		cout << d << " " << -cur.first.second << endl;

		if (dist[nd] < d || mk[nd]) continue;

		mk[nd] = true;

		if (ed != -1){
			edges.push_back(ed);
			sum += W[ed];
		}

		for (auto nx : ady[nd]){
			if (dist[nx.first] >= d + W[nx.second]){
				dist[nx.first] = d + W[nx.second];
				PQ.push(MP(MP(-dist[nx.first], -W[nx.second]), nx));
			}
		}
	}

	cout << sum << endl;
	for (auto ed : edges)
		cout << ed << " ";
	cout << endl;


	return 0;
}