# include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

bool a[420][420];
int d[420][420];
int n, m;

int dis[420];
int calc(bool flag) {
    queue<int> q;
    q.push(1);
    memset(dis, -1, sizeof(dis));
    dis[1] = 0;
    while(!q.empty()) {
	int u = q.front();
	q.pop();
	for(int i = 1; i <= n; ++i) if(a[u][i] ^ flag)
	    if(dis[i] == -1) dis[i] = dis[u] + 1, q.push(i);
    }
    return dis[n];
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i) {
	int u, v; 
	scanf("%d%d", &u, &v);
	a[u][v] = a[v][u] = true;
    }
    printf("%d\n", calc(a[1][n]));
}