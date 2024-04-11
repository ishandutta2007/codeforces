#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 1005;
const int Inf = 1000000000;

int n, m;
char B[Maxn][Maxn];
int lstr[Maxn], lstc[Maxn];
int sum[Maxn][Maxn];
int sumX;
int sr, sc;
int best = Inf;

int checkY(int Y)
{
	int curr = sr, curc = sc;
	while (curc <= lstr[curr])
		if (lstc[curc] >= curr + Y) return lstr[curr] - curc + 1;
		else curc++;
	return 1;
}

int checkX(int X)
{
	int curr = sr, curc = sc;
	while (curr <= lstc[curc])
		if (lstr[curr] >= curc + X) return lstc[curc] - curr + 1;
		else curr++;
	return 1;
}

bool Ok(int r, int c, int X, int Y)
{
	return sum[r + Y - 1][c + X - 1] - sum[r - 1][c + X - 1] - sum[r + Y - 1][c - 1] + sum[r - 1][c - 1] == X * Y;
}

bool Check(int X, int Y)
{
	int curr = sr, curc = sc;
	int taken = 0;
	if (Ok(curr, curc, X, Y)) taken += X * Y;
	else return false;
	while ((lstr[curr] >= curc + X) ^ (lstc[curc] >= curr + Y))
		if (lstr[curr] >= curc + X) { 
			curc++;
			if (Ok(curr, curc, X, Y)) taken += Y;
			else return false;
		} else {
			curr++;
			if (Ok(curr, curc, X, Y)) taken += X;
			else return false;
		}
	return taken == sumX;
}

int main()
{
	scanf("%d %d", &n, &m);
	fill(lstr, lstr + n + 1, -1); fill(lstc, lstc + m + 1, -1);
	sr = -1;
	for (int i = 1; i <= n; i++) {
		scanf("%s", B[i] + 1);
		for (int j = 1; j <= m; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (B[i][j] == 'X');
			if (B[i][j] == 'X') { 
				lstr[i] = j; lstc[j] = i; sumX++; 
				if (sr == -1) { sr = i; sc = j; }
			}
		}
	}
	if (sr == -1) { printf("-1\n"); return 0; }
	int X, Y;
	Y = lstc[sc] - sr + 1; X = checkY(Y);
	if (Check(X, Y)) best = min(best, X * Y);
	X = lstr[sr] - sc + 1; Y = checkX(X);
	if (Check(X, Y)) best = min(best, X * Y);
	printf("%d\n", best == Inf? -1: best);
	return 0;
}