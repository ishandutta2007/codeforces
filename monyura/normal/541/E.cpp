#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <bitset>
#include <sstream>
//#include <random>

using namespace std;

template<typename T> T mabs(const T &a){ return a<0 ? -a : a; }
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, int> pdi;

struct Vert {
	vector<int> edges;
	int depth;
	void init() {
		depth = -1;
	}
} verts[1005];

vector<int> filled;
int bfs(int start) {
	queue<int> q;
	q.push(start);
	verts[start].depth = 0;
	int lastVert = start;
	filled.clear();

	while (!q.empty()) {
		int cur = q.front();
		filled.push_back(cur);
		q.pop();
		Vert &cv = verts[cur];
		rep(i, 0, cv.edges.size()) {
			int to = cv.edges[i];
			Vert &tv = verts[to];
			if (tv.depth == cv.depth) {
				return -1;
			}
			else if (tv.depth == -1) {
				lastVert = to;
				tv.depth = cv.depth + 1;
				q.push(to);
			}
		}
	}
	return lastVert;
}

void run()
{
	int n, m;
	scanf("%d%d", &n, &m);

	rep(i, 0, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		//a = rand() % 1000, b = rand() % 1000;
		verts[a].edges.push_back(b);
		verts[b].edges.push_back(a);
	}
	rep(i, 0, n) {
		verts[i].init();
	}

	//srand(time(0));
	bool fail = 0;
	int farthest = 0;
	set<int> starts;
	rep(i, 0, n) {
		if (verts[i].depth == -1) {
			starts.insert(i);
			int tv = bfs(i);
			if (tv == -1) {
				fail = 1;
				break;
			}
			int dist = verts[tv].depth;
			vector<int> filled2 = filled;
			rep(i, 1, filled2.size()) {
				rep(i, 0, filled2.size()) {
					verts[filled2[i]].init();
				}
				int to = bfs(filled2[i]);
				dist = max(dist, verts[to].depth);
			}
			
			//tv = filled[rand() % filled.size()];
			
			//tv = 0;
			//while (1) {
			//	rep(i, 0, filled.size()) {
			//		verts[filled[i]].init();
			//	}
			//	int f2 = bfs(tv);
			//	if (dist < verts[f2].depth) {
			//		dist = verts[f2].depth;
			//		tv = f2;
			//	}
			//	else
			//		break;
			//}
			
			farthest += dist;
		}
	}

	if (fail)
		farthest = -1;
	printf("%d\n", farthest);
	//rep(i, 1, 1000) {
	//	ll cres = calc(i);
	//	cout << cres << endl;
	//}
}

int main()
{
#ifdef LOCAL_DEBUG
	freopen("test.in", "r", stdin);
	freopen("test.out","w",stdout);
	time_t st = clock();
#else
#ifdef prob
	freopen(prob".in", "r", stdin);
	//freopen(prob".out","w",stdout);
#endif
#endif
	run();
#ifdef LOCAL_DEBUG
	printf("\n=============\n");
	printf("Time: %.2lf sec\n", (clock() - st) / double(CLOCKS_PER_SEC));
#endif

	return 0;
}