#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int N = 1005;

char board[N][N];

vector<PII> neighbours[N][N];

int getColor(vector<PII> v) {
	bool forbidden[10];
	for (int i = 0; i < 10; ++i)
		forbidden[i] = false;
	FOREACH (it, v)
		FOREACH (jt, neighbours[it->ST][it->ND])
			if (board[jt->ST][jt->ND] >= '0' && board[jt->ST][jt->ND] <= '9')
				forbidden[board[jt->ST][jt->ND] - '0'] = true;
	int result = 0;
	while (forbidden[result])
		++result;
	return result;
}

bool visited[N][N];
bool taken[N][N];

vector<PII> lastBrick;

int rootY, rootX;

void dfs(int y, int x) {
	visited[y][x] = true;
	vector<PII> sons;
	FOREACH (it, neighbours[y][x]) {
		if (!visited[it->ST][it->ND]) {
			dfs(it->ST, it->ND);
			if (!taken[it->ST][it->ND])
				sons.PB(MP(it->ST, it->ND));
		}
	}
	if (!sons.empty()) {
		sons.PB(MP(y, x));
		int distRoot = 2;
		FOREACH (it, sons)
			distRoot = min(distRoot, abs(it->ST - rootY) + abs(it->ND - rootX));
		if (SIZE(sons) < 5 && distRoot == 1) {
			lastBrick = sons;
		}
		FOREACH (it, sons)
			taken[it->ST][it->ND] = true;
		int color = getColor(sons);
		FOREACH (it, sons)
			board[it->ST][it->ND] = color + '0';
	}
}

int rows, cols;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };

int main() {
	scanf("%d %d", &rows, &cols);
	for (int i = 1; i <= rows; ++i)
		scanf("%s", board[i] + 1);
	for (int i = 1; i <= rows; ++i)
		for (int j = 1; j <= cols; ++j) {
			if (board[i][j] == '#')
				visited[i][j] = true;
			for (int d = 0; d < 4; ++d) {
				int y = i + dy[d];
				int x = j + dx[d];
				if (y >= 1 && y <= rows && x >= 1 && x <= cols)
					neighbours[i][j].PB(MP(y, x));
			}
		}
	for (int i = 1; i <= rows; ++i)
		for (int j = 1; j <= cols; ++j) {
			if (!visited[i][j]) {
				lastBrick.clear();
				rootY = i;
				rootX = j;
				dfs(i, j);
				if (!taken[i][j]) {
					if (lastBrick.empty()) {
						printf("-1\n");
						return 0;
					}
					lastBrick.PB(MP(i, j));
					int color = getColor(lastBrick);
					taken[i][j] = true;
					FOREACH (it, lastBrick)
						board[it->ST][it->ND] = color + '0';
				}
			}
		}

	for (int i = 1; i <= rows; ++i)
		printf("%s\n", board[i] + 1);

}