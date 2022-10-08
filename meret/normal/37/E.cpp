#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
#include<bitset>
#include<cassert>
using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LDB;
typedef vector<string> VS;

int n, m;

char t[55][55];

int dist[55][55];
bool v[55][55];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int res;

void bfs(int y, int x) {
	deque<PII> q;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			dist[i][j] = 1e9;
			v[i][j] = false;
		}
	dist[y][x] = 0;
	bool black = t[y][x] == 'B';
	q.push_front(MP(y, x));
	int cur = 0;
	while (!q.empty()) {
		PII c = q.front();
		q.pop_front();
		y = c.first;
		x = c.second;
		if (v[y][x])
			continue;
		v[y][x] = true;
		cur = max(cur, dist[y][x]);
		for (int d = 0; d < 4; ++d) {
			int cy = y + dy[d];
			int cx = x + dx[d];
			if (cy >= 1 && cy <= n && cx >= 1 && cx <= m && dist[cy][cx] > dist[y][x] + (t[y][x] != t[cy][cx])) {
				dist[cy][cx] = dist[y][x] + (t[y][x]  != t[cy][cx]);
				if (t[y][x] == t[cy][cx])
					q.push_front(MP(cy, cx));
				else
					q.push_back(MP(cy, cx));
			}
		}
	}
	if (cur % 2 != black)
		++cur;
	if (cur < res)
		res = cur;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%s", t[i] + 1);
	res = 1e9;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			bfs(i, j);
	printf("%d\n", res);
}