#include <stdio.h>
#include <queue>
using namespace std;

int n, m, t; char b[1010][1010]; bool chk[1010][1010];
int dist[1010][1010]; queue<pair<int, int> > q;

int main()
{
	scanf ("%d %d %d", &n, &m, &t);
	for (int i = 0; i < n; i++){
		scanf ("%s", b[i]);
		for (int j = 0; j < m; j++){
			if ((i + j) % 2) b[i][j] = '0' - b[i][j] + '1';
		}
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
		if (i && b[i - 1][j] != b[i][j]) chk[i - 1][j] = chk[i][j] = 1;
		if (j && b[i][j - 1] != b[i][j]) chk[i][j - 1] = chk[i][j] = 1;
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
		if (chk[i][j]){
			q.push({ i,j });
		}
		else dist[i][j] = -1;
	}


	if (q.empty()){
		while (t--){
			int x, y; long long p;
			scanf ("%d %d %lld", &x, &y, &p); x--; y--;
			char u = b[x][y];
			if ((x + y) % 2) u = '0' - u + '1';
			printf ("%c\n", u);
		}
	}
	else{
		while (!q.empty()){
			int x = q.front().first, y = q.front().second; q.pop();
			int dx[4] = { 0,1,0,-1 };
			int dy[4] = { 1,0,-1,0 };
			for (int k = 0; k < 4; k++){
				int px = x + dx[k];
				int py = y + dy[k];
				if (px < 0 || px >= n || py < 0 || py >= m) continue;
				if (dist[px][py] == -1){
					q.push({ px,py }); dist[px][py] = dist[x][y] + 1;
				}
			}
		}
		while (t--){
			int x, y; long long p;
			scanf ("%d %d %lld", &x, &y, &p); x--; y--;
			char u = b[x][y];
			if ((x + y) % 2) u = '0' - u + '1';
			if (dist[x][y] <= p){
				if ((p - dist[x][y]) & 1) u = '0' - u + '1';
			}
			printf ("%c\n", u);
		}
	}

	return 0;
}