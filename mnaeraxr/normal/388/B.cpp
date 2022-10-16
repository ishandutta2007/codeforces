#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 1000;

int cur, tot;
bool matrix[maxn][maxn];
int dist[maxn], p[maxn];

int nxt(){
	int ans = cur++;
	assert(ans < maxn);
	return ans;
}

void addedge(int u, int v){
	// printf("%d %d\n", u + 1, v + 1);
	matrix[u][v] = matrix[v][u] = true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int k;
	scanf("%d", &k);
	
	if (k == 1){
		printf("2\nNY\nYN\n");
		exit(0);
	}

	cur = 2;
	tot = __lg(k);

	dist[0] = 1;
	for (int i = 1; i <= 2 * tot; ++i){
		dist[i] = nxt();
		addedge(dist[i - 1], dist[i]);
	}

	p[0] = 0;
	for (int i = 1; i <= tot; ++i){
		int u = nxt(), v = nxt();
		p[i] = nxt();
		addedge(p[i - 1], u); addedge(p[i - 1], v);
		addedge(u, p[i]); addedge(v, p[i]);
	}

	for (int i = 0; i <= tot; ++i){
		if (k & (1 << i))
			addedge(p[i], dist[2 * tot - 2 * i]);
	}


	printf("%d\n", cur);
	for (int i = 0; i < cur; ++i){
		for (int j = 0; j < cur; ++j)
			if (matrix[i][j]) putchar('Y');
			else putchar('N');
		putchar('\n');
	}

	return 0;
}