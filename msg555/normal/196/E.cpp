#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define MAXN 100000

int P[MAXN];
int Q[MAXN];
long long D[MAXN];
vector<pair<int, int> > E[MAXN];
vector<pair<int, long long> > EE[MAXN];

int main() {
	int N, M; cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int u, v, c; cin >> u >> v >> c; u--; v--;
		E[u].push_back(make_pair(v, c));
		E[v].push_back(make_pair(u, c));
	}
	int K; cin >> K;
	priority_queue<pair<long long, int> > q;
	memset(D, 0x3f, sizeof(D));
	for(int i = 0; i < K; i++) {
		int p; cin >> p; p--;
		Q[p] = p;
		q.push(make_pair(D[p] = 0, P[i] = p));
	}
	while(!q.empty()) {
		int u = q.top().second;
		long long d = -q.top().first;
		q.pop();
		if(d != D[u]) continue;

		for(int i = 0; i < E[u].size(); i++) {
			int v = E[u][i].first;
			long long nd = d + E[u][i].second;
			if(nd < D[v]) {
				D[v] = nd;
				Q[v] = Q[u];
				q.push(make_pair(-nd, v));
			}
		}
	}
	for(int u = 0; u < N; u++) {
		for(int i = 0; i < E[u].size(); i++) {
			int v = E[u][i].first;
			long long d = D[u] + D[v] + E[u][i].second;
			if(Q[u] != Q[v]) {
				EE[Q[u]].push_back(make_pair(Q[v], d));
				EE[Q[v]].push_back(make_pair(Q[u], d));
			}
		}
	}
	long long cst = D[0];
	memset(D, 0x3f, sizeof(D));
	q.push(make_pair(D[P[0]] = 0, P[0]));
	while(!q.empty()) {
		int u = q.top().second;
		long long d = -q.top().first;
		q.pop();
		if(d != D[u]) continue;
		cst += d;
		D[u] = -1;
		
		for(int i = 0; i < EE[u].size(); i++) {
			int v = EE[u][i].first;
			long long nd = EE[u][i].second;
			if(nd < D[v]) {
				D[v] = nd;
				q.push(make_pair(-nd, v));
			}
		}
	}
	cout << cst << endl;
}