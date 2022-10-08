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

bitset<81 * 81 * 81 * 8 * 8 * 8 * 3> vis(0);

int pos[3], mov[3], thr[3];

struct State {
	int p[3], s[3];

	int hash() {
		int result = 0;
		for (int i = 0; i < 3; ++i)
			result = result * 81 + p[i];
		for (int i = 0; i < 3; ++i)
			result = result * 8 + s[i];
		return result * 3 + firstGrab;
	}

	int firstGrab;
};

void print(State c) {
	printf("%d %d %d %d %d %d\n", c.p[0], c.p[1], c.p[2], c.s[0], c.s[1], c.s[2]);
}

int main() {
	for (int i = 0; i < 3; ++i) {
		scanf("%d %d %d", &pos[i], &mov[i], &thr[i]);
	}
	State st;
	REP (i, 3) {
		st.p[i] = pos[i];
		st.s[i] = 0;
	}
	st.firstGrab = 0;
	vis[st.hash()] = 1;
	queue<State> q;
	q.push(st);
	int result = 0;
	while (!q.empty()) {
		State c = q.front();
		q.pop();
		for (int i = 0; i < 3; ++i) {
			result = max(result, c.p[i]);
			int nx = (i + 1) % 3;
			int pr = (i + 2) % 3;
			for (int j = 0; j < 3; ++j) {
				if (((c.s[i] >> j) & 1) == 0) {
					if (j == 2 && ((c.s[i] >> 1) & 1) == 0)
						continue;
					if ((c.p[i] == c.p[nx] || c.p[i] == c.p[pr]) && !((c.s[i]
							>> 1) & 1))
						continue;
					if ((c.p[i] == c.p[nx] && c.p[i] == c.p[pr]) && c.firstGrab
							== i)
						continue;
					if (j == 0) {
						if (c.p[nx] == c.p[i] || c.p[pr] == c.p[i])
							continue;
						for (int k = max(1, c.p[i] - mov[i]); k <= c.p[i]
								+ mov[i]; ++k) {
							if (k == c.p[0] || k == c.p[1] || k == c.p[2])
								continue;
							State nx = c;
							nx.s[i] |= (1 << j);
							for (int l = 0; l < 3; ++l)
								if (c.p[l] == c.p[i])
									nx.p[l] = k;
							if (!vis[nx.hash()]) {
								vis[nx.hash()] = 1;
								q.push(nx);
							}
						}
					} else if (j == 1) {
						int forb = -1;
						if (c.p[nx] == c.p[pr]) {
							if (c.firstGrab == nx)
								forb = pr;
							else
								forb = nx;
						}
						for (int o = 0; o < 3; ++o) {
							if (o == i || o == forb)
								continue;
							if (abs(c.p[i] - c.p[o]) != 1)
								continue;
							State nx = c;
							for (int l = 0; l < 3; ++l)
								if (c.p[l] == c.p[o])
									nx.p[l] = c.p[i];
							nx.s[i] |= (1 << j);
							if (((c.s[0] & 2) | (c.s[1] & 2) | (c.s[2] & 2)) == 0)
								nx.firstGrab = i;
							if (!vis[nx.hash()]) {
								vis[nx.hash()] = 1;
								q.push(nx);
							}
						}
					} else {
						int grabbed = -1;
						int cnt = 0;
						for (int o = 0; o < 3; ++o)
							if (c.p[o] == c.p[i])
								++cnt;
						if (cnt == 1)
							continue;
						if (cnt == 2) {
							for (int o = 0; o < 3; ++o)
								if (o != i && c.p[o] == c.p[i])
									grabbed = o;
						} else {
							int cg = 0;
							for (int o = 0; o < 3; ++o)
								if (o != i && ((c.s[o] >> 1) & 1) == 1) {
									++cg;
									grabbed = o;
								}
							if (cg == 2) {
								if (nx == c.firstGrab)
									grabbed = pr;
								else
									grabbed = nx;
							}
						}
						for (int k = max(1, c.p[i] - thr[i]); k <= c.p[i] + thr[i]; ++k) {
							if (k == c.p[0] || k == c.p[1] || k == c.p[2])
								continue;
							State nx = c;
							nx.s[i] |= (1 << j);
							for (int l = 0; l < 3; ++l)
								if (l != i && c.p[l] == c.p[i])
									nx.p[l] = k;
							if (!vis[nx.hash()]) {
								vis[nx.hash()] = 1;
								q.push(nx);
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n", result);
}