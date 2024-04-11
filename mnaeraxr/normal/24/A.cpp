#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 110;

int neig[maxn][2];
int weight[maxn][2];

void addNeig(int u, int v, int w){
	int c = 0;
	if (neig[u][0] != 0) c++;
	neig[u][c] = v;
	weight[u][c] = w;
}

int get_cost(int move){	
	int prev = 1;
	int cur = neig[1][move];
	int cost = weight[1][move];

	while (cur != 1){
		int c = 0;
		if (neig[cur][0] == prev)
			c = 1;
		
		cost += weight[cur][c];
		prev = cur;
		cur = neig[cur][c];
	}
	return cost;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// freopen("data.in", "r", stdin);		

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i){
		int u, v, w;
		cin >> u >> v >> w;

		addNeig(u, v, 0);
		addNeig(v, u, w);
	}

	cout << min(get_cost(0), get_cost(1)) << endl;

	return 0;
}