#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<bitset>
#include<numeric>
#include<climits>
#include<cassert>
#include<complex>
#include<functional>
using namespace std;

typedef long long ll;
template<typename A,typename B>inline void chmin(A &a, B b) { if (a > b)a = b; }
template<typename A,typename B>inline void chmax(A &a, B b) { if (a < b)a = b; }

string S = "*^>@v|@L<@-D@RU+";

int H, W;
int fld[1000][1000];
int sy, sx, gy, gx;
const int INF = 1001001001;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int dist[1000][1000][4];


int main() {
	scanf("%d%d", &H, &W);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			char c;
			scanf(" %c", &c);
			fld[i][j] = find(S.begin(), S.end(), c) - S.begin();
		}
	}
	cin >> sy >> sx >> gy >> gx;
	sy--; sx--; gy--; gx--;

	fill(**dist,**dist+1000*1000*4, INF);
	dist[sy][sx][0] = 0;
	queue<tuple<int, int, int>>que;
	que.push(make_tuple(sy, sx, 0));
	
	while (que.size()) {
		int y, x, d;
		tie(y, x, d) = que.front();
		que.pop();
		

		int nd = (d + 1) % 4;
		if (dist[y][x][nd] == INF) {
			dist[y][x][nd] = dist[y][x][d] + 1;
			que.push(make_tuple(y, x, nd));
		}

		for (int i = 0; i < 4; i++) {
			nd = (i - d + 4) % 4;
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || ny >= H || nx < 0 || nx >= W)continue;
			if (!(fld[y][x] >> nd & 1) || !(fld[ny][nx] >> ((nd + 2) % 4) & 1))continue;
			if (dist[ny][nx][d] != INF)continue;
			dist[ny][nx][d] = dist[y][x][d] + 1;
			que.push(make_tuple(ny, nx, d));
		}
	}

	int ans = INF;
	for (int i = 0; i < 4; i++)ans = min(ans, dist[gy][gx][i]);
	if (ans == INF)puts("-1");
	else printf("%d\n", ans);
	return 0;
}