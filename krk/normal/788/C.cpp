#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;
const int Inf = 2000000007;
const int Maxm = 2015;
const int nil = 1005;

int n, k;
bool has[Maxn];
vector <int> rem, add;
int dist[Maxm];

int main()
{
	scanf("%d %d", &n, &k);
	while (k--) {
		int a; scanf("%d", &a);
		has[a] = true;
	}
	if (has[n]) { printf("1\n"); return 0; }
	for (int i = 0; i < Maxn; i++) if (has[i])
		if (i < n) rem.push_back(n - i);
		else add.push_back(i - n);
	fill(dist, dist + Maxm, Inf);
	queue <int> Q;
	for (int i = 0; i < Maxn; i++) if (has[i]) {
		dist[i - n + nil] = 1; Q.push(i - n + nil);
	}
	while (!Q.empty()) {
		int v = Q.front(); int d = dist[v]; Q.pop();
		if (v == nil) { printf("%d\n", d); return 0; }
		if (v > nil) {
			for (int i = 0; i < rem.size(); i++)
				if (d + 1 < dist[v - rem[i]]) {
					dist[v - rem[i]] = d + 1; Q.push(v - rem[i]);
				}
		} else for (int i = 0; i < add.size(); i++)
				if (d + 1 < dist[v + add[i]]) {
					dist[v + add[i]] = d + 1; Q.push(v + add[i]);
				}
	}
	printf("-1\n");
	return 0;
}