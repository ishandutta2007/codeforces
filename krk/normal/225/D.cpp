#include <cstdio>
#include <queue>
#include <cctype>
#include <algorithm>
using namespace std;

const int Inf = 2000000000;
const int Maxn = 15;
const int Maxm = 14745700;
const int Maxl = 10;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, 1, 0, -1};

struct board {
	char m[Maxn][Maxn];
};

int n, m;
board B;
int len;
int fy, fx;
int mod;
int dist[Maxm];
int res = -1;
int mx;

int toInt(const board &B)
{
	int r[Maxl], c[Maxl];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (isdigit(B.m[i][j])) { r[B.m[i][j] - '0'] = i; c[B.m[i][j] - '0'] = j; }
	int res = 0;
	for (int i = len; i >= 2; i--) {
		res *= Maxd;
		int j = 0;
		while (r[i - 1] + dy[j] != r[i] || c[i - 1] + dx[j] != c[i]) j++;
		res += j;
	}
	res *= Maxn; res += r[1];
	res *= Maxn; res += c[1];
	return res;
}

board toBoard(int p)
{
	board nB;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			nB.m[i][j] = B.m[i][j] == '#'? '#': '.';
	int j = p % Maxn; p /= Maxn;
	int i = p % Maxn; p /= Maxn;
	char dig = '1'; nB.m[i][j] = dig;
	for (int l = 2; l <= len; l++) {
		int d = p % Maxd; p /= Maxd;
		i += dy[d]; j += dx[d]; 
		dig++; nB.m[i][j] = dig;
	}
	return nB;
}

board Move(const board &B, int ni, int nj)
{
	board nB;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (B.m[i][j] == '#') nB.m[i][j] = '#';
			else if (i == ni && j == nj) nB.m[i][j] = '1';
			else if (isdigit(B.m[i][j]) && B.m[i][j] < '0' + len) nB.m[i][j] = B.m[i][j] + 1;
			else nB.m[i][j] = '.';
	return nB;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf(" %c", &B.m[i][j]);
			if (B.m[i][j] == '@') { fy = i; fx = j; B.m[i][j] = '.'; }
			else if (isdigit(B.m[i][j])) len = max(len, B.m[i][j] - '0');
		}
	mod = Maxn * Maxn;
	for (int i = 0; i < len - 2; i++) mod *= Maxd;
	int v = toInt(B);
	fill(dist, dist + Maxm, Inf); dist[v] = 0;
	queue <int> Q; Q.push(v);
	while (!Q.empty()) {
		v = Q.front(); int d = dist[v]; Q.pop();
		board nB = toBoard(v);
		int j = v % Maxn, i = v / Maxn % Maxn;
		if (i == fy && j == fx) { res = d; break; }
		for (int k = 0; k < Maxd; k++) {
			int ni = i + dy[k], nj = j + dx[k];
			if (0 <= ni && ni < n && 0 <= nj && nj < m && (nB.m[ni][nj] == '.' || nB.m[ni][nj] == '0' + len)) {
				int u = v % mod; u = u / Maxn / Maxn; u *= Maxd;
				u += (k + 2) % Maxd;
				u *= Maxn; u += ni;
				u *= Maxn; u += nj;
				if (d + 1 < dist[u]) { dist[u] = d + 1; Q.push(u); }
			}
		}
	}
	printf("%d\n", res);
	return 0;
}