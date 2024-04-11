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

bitset<150> board[150];

bitset<150> accessible[150];

bitset<150> noMoveUp[150];
bitset<150> noMoveDown[150];
bitset<150> noMoveRight[150];
bitset<150> noMoveLeft[150];

int height, width;

void up() {
	for (int i = 0; i + 1 < height; ++i)
		board[i] = (board[i + 1] & accessible[i]) | (board[i] & noMoveUp[i]);
	board[height - 1] &= noMoveUp[height - 1];
}

void down() {
	for (int i = height - 1; i > 0; --i)
		board[i] = (board[i - 1] & accessible[i]) | (board[i] & noMoveDown[i]);
	board[0] &= noMoveDown[0];
}

void left() {
	for (int i = 0; i < height; ++i)
		board[i] = ((board[i] >> 1) & accessible[i]) | (board[i] & noMoveLeft[i]);
}

void right() {
	for (int i = 0; i < height; ++i)
		board[i] = ((board[i] << 1) & accessible[i]) | (board[i] & noMoveRight[i]);
}

int k;

char buf[100005];

int exitY, exitX;

int main() {
	scanf("%d %d %d", &height, &width, &k);
	for (int i = 0; i < height; ++i) {
		scanf("%s", buf);
		for (int j = 0; j < width; ++j) {
			accessible[i][j] = (buf[j] != '#');
			if (buf[j] == 'E') {
				exitY = i;
				exitX = j;
			}
			if (buf[j] == '#') {
				if (i > 0)
					noMoveDown[i - 1][j] = 1;
				if (i < height - 1)
					noMoveUp[i + 1][j] = 1;
				if (j > 0)
					noMoveRight[i][j - 1] = 1;
				if (j < width - 1)
					noMoveLeft[i][j + 1] = 1;
			}
		}
		board[i] = accessible[i];
	}
	scanf("%s", buf);
	for (int i = 0; i <= k; ++i) {
		if (i > 0) {
			if (buf[i - 1] == 'U')
				up();
			else if (buf[i - 1] == 'D')
				down();
			else if (buf[i - 1] == 'L')
				left();
			else
				right();
		}
		bool finished = true;
		for (int y = 0; y < height; ++y) {
			if (y == exitY) {
				if (board[y].count() != 1) {
					finished = false;
					break;
				}
				if (board[y][exitX] != 1) {
					finished = false;
					break;
				}
			} else {
				if (board[y].count() != 0) {
					finished = false;
					break;
				}
			}
		}
		if (finished) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
}