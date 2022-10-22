#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 100005;

int n, k;
string s[2];
int dist[2][Maxn];

bool Possible()
{
	fill((int*)dist, (int*)dist + 2 * Maxn, Inf); dist[0][0] = 0;
	queue <ii> Q; if (s[0][0] != 'X') Q.push(ii(0, 0));
	while (!Q.empty()) {
		ii v = Q.front(); int d = dist[v.first][v.second]; Q.pop();
		if (s[v.first][v.second] == 'X' || d > v.second) continue;
		ii u = ii(v.first, v.second - 1);
		if (u.second >= 0 && d + 1 < dist[u.first][u.second])
			dist[u.first][u.second] = d + 1, Q.push(u);
		u = ii(v.first, v.second + 1);
		if (u.second >= n) return true;
		if (d + 1 < dist[u.first][u.second])
			dist[u.first][u.second] = d + 1, Q.push(u);
		u = ii(1 - v.first, v.second + k);
		if (u.second >= n) return true;
		if (d + 1 < dist[u.first][u.second])
			dist[u.first][u.second] = d + 1, Q.push(u);
	}
	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin >> n >> k;
	cin >> s[0] >> s[1];
	printf("%s\n", Possible()? "YES": "NO");
	return 0;
}