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
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int N = 1005;

int rows, cols;

char t[N][N];

bool considered[N][N];
bool visited[N][N];

int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};

bool isCycle(vector<PII>& v) {
	FORE (it, v) {
		visited[it->ST][it->ND] = false;
		considered[it->ST][it->ND] = true;
	}
	int y = v[0].ST;
	int x = v[0].ND;
	int nVisited = 0;
	while (y != -1) {
		int ne = 0;
		int nxy = -1, nxx = -1;
		for (int d = 0; d < 4; ++d) {
			int cy = y + dy[d];
			int cx = x + dx[d];
			if (considered[cy][cx]) {
				++ne;
				if (!visited[cy][cx]) {
					nxy = cy;
					nxx = cx;
				}
			}
		}
		if (ne != 2) {
			break;
		}
		visited[y][x] = true;
		++nVisited;
		y = nxy;
		x = nxx;
	}
	FORE (it, v) {
		visited[it->ST][it->ND] = false;
		considered[it->ST][it->ND] = false;
	}
	return nVisited == (int) v.size();
}

vector<PII> boundary;
bool bad;

void dfs(int y, int x) {
	visited[y][x] = true;
	for (int d = 0; d < 8; ++d) {
		int cy = y + dy[d];
		int cx = x + dx[d];
		if (t[cy][cx] == '0' && !visited[cy][cx]) {
			dfs(cy, cx);
		} else if (t[cy][cx] == '1' && !visited[cy][cx]) {
			visited[cy][cx] = '1';
			boundary.PB(MP(cy, cx));
		} else if (t[cy][cx] != '0' && t[cy][cx] != '1') {
			bad = true;
		}
	}
}

int main() {
	scanf("%d %d", &rows, &cols);
	for (int i = 1; i <= rows; ++i) {
		scanf("%s", t[i] + 1);
	}
	int res = 0;
	for (int i = 1; i <= rows; ++i) {
		for (int j = 1; j <= cols; ++j) {
			if (i < rows && j < cols && t[i][j] == '1' && t[i + 1][j] == '1' && t[i][j + 1] == '1' && t[i + 1][j + 1] == '1') {
				res = max(res, 4);
			}
			if (t[i][j] == '0' && !visited[i][j]) {
				bad = false;
				boundary.clear();
				dfs(i, j);
				if (!bad && isCycle(boundary)) {
					res = max(res, (int) boundary.size());
				}
				FORE (it, boundary) {
					visited[it->ST][it->ND] = false;
				}
			}
		}
	}
	printf("%d\n", res);
}