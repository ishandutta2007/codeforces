#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

const int maxn = 1010, P = 505;
int stp[maxn][maxn];
#define sqr(x) ((x) * (x))
bool valid(int x, int y, int p, int q) {
	int val = sqr(p - x) + sqr(q - y), rt = sqrt(val);
	return sqr(rt) == val;
}

int main() {
	memset(stp, -1, sizeof stp);
	queue <pii> q;
	stp[P][P] = 0, q.push(make_pair(0, 0));
	while (!q.empty()) {
		pii nw = q.front(); q.pop();
		for (int i = -50; i <= 50; ++i)
			for (int j = -50; j <= 50; ++j)
				if (stp[i + P][j + P] == -1 && valid(nw.first, nw.second, i, j)) {
					stp[i + P][j + P] = stp[nw.first + P][nw.second + P] + 1;
					q.push(make_pair(i, j));
				}
	}
	int t; scanf("%d", &t);
	while (t--) {
		int x, y; scanf("%d%d", &x, &y);
		printf("%d\n", stp[x + P][y + P]);
	}
	return 0;
}