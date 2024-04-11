#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;

int x0, y0, x1, y1;
int n;
map <ii, int> M;

int main()
{
	scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
	scanf("%d", &n);
	while (n--) {
		int r, a, b; scanf("%d %d %d", &r, &a, &b);
		ii p;
		for (int i = a; i <= b; i++) {
			M.insert ( pair<ii,int>(make_pair(r, i),Inf) );
		}
	}
	M[make_pair(x0, y0)] = 0;
	queue <ii> Q; Q.push(make_pair(x0, y0));
	while (!Q.empty()) {
		ii v = Q.front(); Q.pop();
		int d = M[v];
		if (v == make_pair(x1, y1)) { printf("%d\n", d); return 0; }
		for (int di = -1; di <= 1; di++)
			for (int dj = -1; dj <= 1; dj++) {
				ii u = make_pair(v.first + di, v.second + dj);
				if (M.find(u) != M.end() && d + 1 < M[u]) {
					M[u] = d + 1;
					Q.push(u);
				}
			}
	}
	printf("-1\n");
	return 0;
}