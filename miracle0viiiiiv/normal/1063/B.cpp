#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, m, sx, sy, cl, cr;
char ch[2005][2005];
int dis[2005][2005];

void bfs()
{
	memset(dis, INF, sizeof(dis));
	deque<PII> que;
	que.push_back(MP(sx, sy));
	dis[sx][sy] = 0;
	while(!que.empty()) {
		int cx = que.front().first, cy = que.front().second;
		que.pop_front();
		if(ch[cx][cy] != '.') continue;
		ch[cx][cy] = '#';
		if(dis[cx][cy - 1] > dis[cx][cy] + 1) {
			dis[cx][cy - 1] = dis[cx][cy] + 1;
			que.push_back(MP(cx, cy - 1));
		}
		if(dis[cx][cy + 1] > dis[cx][cy] + 1) {
			dis[cx][cy + 1] = dis[cx][cy] + 1;
			que.push_back(MP(cx, cy + 1));
		}
		if(dis[cx - 1][cy] > dis[cx][cy]) {
			dis[cx - 1][cy] = dis[cx][cy];
			que.push_front(MP(cx - 1, cy));
		}
		if(dis[cx + 1][cy] > dis[cx][cy]) {
			dis[cx + 1][cy] = dis[cx][cy];
			que.push_front(MP(cx + 1, cy));
		}
	}
}

int main()
{
	scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &cl, &cr);
	rep1(i, n) scanf("%s", ch[i] + 1);
	bfs();
	int cnt = 0;
	rep1(i, n) rep1(j, m) {
		int ttl = (dis[i][j] + sy - j) / 2, ttr = (dis[i][j] + j - sy) / 2;
		if(ch[i][j] == '#' && ttl <= cl && ttr <= cr) cnt ++;
	}
	printf("%d\n", cnt);
	return 0;
}