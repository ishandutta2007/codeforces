#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 205;
const int Maxl = 26;
const int Inf = 1000000000;

string s;
int freq[Maxl];
int n;
int N;
vector <int> neigh[Maxn];
int R[Maxn][Maxn], C[Maxn][Maxn];
int dist[Maxn], par[Maxn];
int mf;
int res;

void getFreq()
{
	fill(freq, freq + Maxl, 0);
	for (int i = 0; i < s.length(); i++)
		freq[s[i] - 'a']++;
}

bool getFlow(int &cost)
{
	fill(dist, dist + N, Inf); dist[0] = 0;
	priority_queue <ii> Q; Q.push(ii(-dist[0], 0));
	while (!Q.empty()) {
		int v = Q.top().second, d = -Q.top().first; Q.pop();
		if (dist[v] != d) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (R[v][u] && d + C[v][u] < dist[u]) dist[u] = d + C[v][u], par[u] = v, Q.push(ii(-dist[u], u));
		}
	}
	if (dist[N - 1] == Inf) return false;
	int v = N - 1; cost = dist[N - 1];
	while (v) {
		int u = par[v];
		R[u][v]--; R[v][u]++;
		v = u;
	}
	return true;
}

int main()
{
	cin >> s; getFreq(); mf = s.length();
	for (int i = 1; i <= Maxl; i++) if (freq[i - 1]) {
		R[0][i] = freq[i - 1]; neigh[0].push_back(i); neigh[i].push_back(0);
	}
	scanf("%d", &n); N = n + Maxl + 2;
	for (int i = 1; i <= n; i++) {
		cin >> s; getFreq();
		for (int j = 1; j <= Maxl; j++) if (freq[j - 1]) {
			R[j][Maxl + i] = freq[j - 1]; C[j][Maxl + i] = i; C[Maxl + i][j] = -i;
			neigh[j].push_back(Maxl + i); neigh[Maxl + i].push_back(j);
		}
		int lim; scanf("%d", &lim);
		R[Maxl + i][N - 1] = lim; neigh[Maxl + i].push_back(N - 1); neigh[N - 1].push_back(Maxl + i);
	}
	int cost;
	while (getFlow(cost)) { mf--; res += cost; }
	printf("%d\n", mf? -1: res);
	return 0;
}