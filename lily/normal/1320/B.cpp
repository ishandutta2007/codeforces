#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second


#define N 202111



int n,m, L, R, K;
int p[N];
vector <int> E[N];

int dis[N], mul[N];
queue<int>q;

void dij(int s) {
	for (int i = 1; i <= n; i++) dis[i] = 0x3f3f3f3f;	
	dis[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (auto v : E[x]) {
			if (dis[v] > n) {
				dis[v] = dis[x] + 1;
				q.push(v);
				mul[v] = 1;
			}
			else if (dis[v] == dis[x] + 1) {
				mul[v]++;
			}
		}
	}
}

int main() {
	read(n); read(m);
	for (int i = 1; i<= m; i++) {
		int u, v;
		read(u); read(v);
		E[v].push_back(u);
	}
	read(K);
	for (int i = 1; i <= K; i++) {
		read(p[i]);
	}
	dij(p[K]);
	for (int i = 1; i < K; i++) {
		if (dis[p[i]] != dis[p[i + 1]] + 1) {
			L ++ , R ++;
		}
		else if (mul[p[i]] > 1) {
			R ++;
		}
	}
	cout << L << " " << R << endl;
}