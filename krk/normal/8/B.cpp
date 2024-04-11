#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 215;
const int nil = 105;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

string s;
bool ok[Maxn][Maxn];
int sr = nil, sc = nil;
int er, ec;
int dist[Maxn][Maxn];

void Traverse(int sr, int sc, int &er, int &ec)
{
	ok[sr][sc] = true;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'L') sc--;
		else if (s[i] == 'R') sc++;
		else if (s[i] == 'U') sr--;
		else sr++;
		ok[sr][sc] = true;
	}
	er = sr; ec = sc;
}

int Shortest(int er, int ec)
{
	fill((int*)dist, (int*)dist + Maxn * Maxn, Maxn * Maxn); dist[nil][nil] = 0;
	queue <ii> Q; Q.push(ii(nil, nil));
	while (!Q.empty()) {
		ii v = Q.front(); int d = dist[v.first][v.second]; Q.pop();
		if (v == ii(er, ec)) return d;
		for (int i = 0; i < Maxd; i++) {
			ii u = ii(v.first + dy[i], v.second + dx[i]);
			if (ok[u.first][u.second] && d + 1 < dist[u.first][u.second]) {
				dist[u.first][u.second] = d + 1; Q.push(u);
			}
		}
	}
	return -1;
}

int main()
{
	getline(cin, s);
	Traverse(sr, sc, er, ec);
	printf("%s\n", Shortest(er, ec) == s.length()? "OK": "BUG");
	return 0;
}