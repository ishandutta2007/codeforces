#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long lld;

int N, M, S, B, K, H;
int w[101][101];
struct {
	int x, a, f;
} SS[1001];
struct {
	int x, d;
} DB[1001];

int match[1001], dist[1001];
bool used[1001];
vector <int> con[1001];

void bfs()
{
	queue <int> que;
	for (int i=1;i<=S;i++) dist[i] = 1e9;
	for (int i=1;i<=S;i++) if (!used[i]) dist[i] = 0, que.push(i);
	while (!que.empty()){
		int q = que.front(); que.pop();
		for (int t: con[q]){
			int m = match[t];
			if (m && dist[m] == 1e9) dist[m] = dist[q]+1, que.push(m);
		}
	}
}

bool dfs(int n)
{
	for (int t: con[n]){
		int m = match[t];
		if (!m || dist[m] == dist[n]+1 && dfs(m)){
			used[n] = 1; match[t] = n;
			return 1;
		}
	}
	dist[n] = 1e9;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) w[i][j] = i == j ? 0 : (int)1e9+1;
	for (int i=1;i<=M;i++){
		int a, b; cin >> a >> b;
		w[a][b] = w[b][a] = 1;
	}
	for (int k=1;k<=N;k++) for (int i=1;i<=N;i++) for (int j=1;j<=N;j++)
		w[i][j] = min(w[i][j], w[i][k]+w[k][j]);
	cin >> S >> B >> K >> H;
	for (int i=1;i<=S;i++) cin >> SS[i].x >> SS[i].a >> SS[i].f;
	for (int i=1;i<=B;i++) cin >> DB[i].x >> DB[i].d;
	for (int i=1;i<=S;i++) for (int j=1;j<=B;j++) if (w[SS[i].x][DB[j].x] <= SS[i].f && DB[j].d <= SS[i].a)
		con[i].pb(j);
	
	int matched = 0;
	for (;;){
		bfs();
		int flow = 0;
		for (int i=1;i<=S;i++) if (!used[i] && dfs(i)) flow++;
		if (!flow) break;
		matched += flow;
	}
	cout << min((lld)matched * K, (lld)S * H) << endl;
}