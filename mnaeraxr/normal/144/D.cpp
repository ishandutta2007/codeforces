#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DrB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int U[MAXN], V[MAXN], W[MAXN];
vector<pii> ady[MAXN];
int D[MAXN];

void dijkstra(int s){
	memset(D, oo, sizeof D);
	D[s] = 0;
	priority_queue<pii> PQ;
	PQ.push(MP(0,s));
	while (!PQ.empty()){
		pii cur = PQ.top(); PQ.pop();
		int t = -cur.first;
		int n = cur.second;
		if (D[n] < t) continue;
		for (int i = 0; i < (int)ady[n].size(); ++i){
			pii nx = ady[n][i];
			if (D[nx.first] > t + nx.second){
				D[nx.first] = t + nx.second;
				PQ.push(MP(-D[nx.first],nx.first));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, s;
	cin >> n >> m >> s;
	for (int i = 0; i < m; ++i){
		cin >> U[i] >> V[i] >> W[i];
		ady[U[i]].push_back(MP(V[i],W[i]));
		ady[V[i]].push_back(MP(U[i],W[i]));
	}
	dijkstra(s);
	int l, ans = 0;
	cin >> l;

	for (int i = 1; i <= n; ++i){
		if (D[i] == l) ++ans;
	}
	for (int i = 0; i < m; ++i){
		int x = D[U[i]], y = D[V[i]], d = W[i];
		if (0 < l - x && l - x < d)
			if (d - (l - x) + y >= l)
				++ans;
		if (0 < l - y && l - y < d)
			if (d - (l - y) + x > l)
				++ans;
	}

	cout << ans << endl;

	return 0;
}