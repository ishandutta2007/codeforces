#include <cstdio>
#include <set>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 1005;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m;
char B[Maxn][Maxn];
bool X[Maxn][Maxn];
int odd;
int res;

bool Has(int r, int c)
{
	return 0 <= r && r < n && 0 <= c && c < m && B[r][c] == '1';
}

int Neighs(int r, int c)
{
	int res = 0;
	for (int i = 0; i < Maxd; i++)
		res += Has(r + dy[i], c + dx[i]);
	return res;
}

bool Corner(int r, int c)
{
	for (int i = 0; i < Maxd; i++)
		if (Has(r + dy[i], c + dx[i]) && Has(r + dy[(i + 1) % Maxd], c + dx[(i + 1) % Maxd]))
			return true;
	return false;
}

void Erase(int r, int c)
{
	if (r < 0 || r >= n || c < 0 || c >= m || B[r][c] == '0') return;
	B[r][c] = '0';
	for (int i = 0; i < Maxd; i++)
		Erase(r + dy[i], c + dx[i]);
}

bool Connected()
{
	int comp = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (B[i][j] == '1') { comp++; Erase(i, j); }
	return comp == 1;
}

int getRes(int r, int c, int dy, int dx, int delta)
{
	if (X[r][c]) return delta;
	return getRes(r + dy, c + dx, dy, dx, delta + 1);
}

int gcd(int a, int b) { return a? gcd(b % a, a): b; }

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &B[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			X[i][j] = B[i][j] == '1' && (Corner(i, j) || Neighs(i, j) <= 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (X[i][j]) {
				int deg = 0;
				for (int d = 0; d < Maxd; d++) if (Has(i + dy[d], j + dx[d])) {
					deg++;
					int got = getRes(i + dy[d], j + dx[d], dy[d], dx[d], 1);
					res = gcd(res, got);
				}
				odd += deg % 2;
			}
	if (odd <= 2 && Connected() && res > 1) {
		set <int> divs;
		for (int i = 1; i * i <= res; i++)
			if (res % i == 0) {
				if (i > 1) divs.insert(i);
				if (res / i > 1) divs.insert(res / i);
			}
		for (set <int>::iterator it = divs.begin(); it != divs.end(); it++) {
			if (it != divs.begin()) printf(" ");
			printf("%d", *it);
		}
		printf("\n");
	} else printf("-1\n");
	return 0;
}