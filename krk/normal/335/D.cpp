#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 3000;
const int nil = 3005;
const int Maxd = 6015;

int n;
int X1[Maxn], Y1[Maxn], X2[Maxn], Y2[Maxn];
ii P[4][Maxm][Maxm]; // L, R, U, D
int len[4][Maxm][Maxm];
int S[Maxm][Maxm];
vector <ii> B[Maxd], E[Maxd];
bool found;
int rX1, rY1, rX2, rY2;
vector <int> res;

int Get(ii P[][Maxm], int len[][Maxm], int r, int c, bool tk = false)
{
	if (r < 0 || c < 0 || r >= Maxm || c >= Maxm && P[r][c] == ii(r, c)) return 0;
	if (tk) return len[r][c];
	return abs(r - P[r][c].first) + abs(c - P[r][c].second) + Get(P, len, P[r][c].first, P[r][c].second, true);
}

int getCalc(int x1, int y1, int x2, int y2)
{
	return S[x2][y2] - (x1? S[x1 - 1][y2]: 0) - (y1? S[x2][y1 - 1]: 0) + (x1 && y1? S[x1 - 1][y1 - 1]: 0);
}

int main()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < Maxm; j++)
			for (int k = 0; k < Maxm; k++)
				P[i][j][k] = ii(j, k);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
		P[0][X2[i] - 1][Y2[i] - 1] = ii(X2[i] - 1, Y1[i] - 1);
		P[1][X1[i]][Y1[i]] = ii(X1[i], Y2[i]);
		P[2][X2[i] - 1][Y2[i] - 1] = ii(X1[i] - 1, Y2[i] - 1);
		P[3][X1[i]][Y1[i]] = ii(X2[i], Y1[i]);
		for (int j = X1[i]; j < X2[i]; j++)
			for (int k = Y1[i]; k < Y2[i]; k++)
				S[j][k]++;
	}
	for (int i = 0; i < Maxm; i++)
		for (int j = 0; j < Maxm; j++) {
			if (i) S[i][j] += S[i - 1][j];
			if (j) S[i][j] += S[i][j - 1];
			if (i && j) S[i][j] -= S[i - 1][j - 1];
			len[0][i][j] = Get(P[0], len[0], i, j);
			len[2][i][j] = Get(P[2], len[2], i, j);
		}
	for (int i = Maxm - 1; i >= 0; i--)
		for (int j = Maxm - 1; j >= 0; j--) {
			len[1][i][j] = Get(P[1], len[1], i, j);
			len[3][i][j] = Get(P[3], len[3], i, j);
		}
	for (int i = 0; i < n; i++) {
		B[X1[i] - Y1[i] + nil].push_back(ii(X1[i], min(len[1][X1[i]][Y1[i]], len[3][X1[i]][Y1[i]])));
		E[X2[i] - Y2[i] + nil].push_back(ii(X2[i] - 1, min(len[0][X2[i] - 1][Y2[i] - 1], len[2][X2[i] - 1][Y2[i] - 1])));
	}
	for (int i = 0; i < Maxd && !found; i++) {
		sort(B[i].begin(), B[i].end()); sort(E[i].begin(), E[i].end());
		vector <ii> Stack;
		int cur = 0;
		for (int j = 0; j < E[i].size() && !found; j++) {
			while (cur < B[i].size() && B[i][cur].first <= E[i][j].first) { Stack.push_back(B[i][cur]); cur++; }
			while (!Stack.empty() && Stack.back().first + Stack.back().second <= E[i][j].first) Stack.pop_back();
			if (Stack.empty()) continue;
			if (E[i][j].first - E[i][j].second < Stack.back().first) {
				int d = nil - i;
				int r = E[i][j].first - Stack.back().first + 1;
				if (getCalc(Stack.back().first, Stack.back().first + d, E[i][j].first, E[i][j].first + d) == r * r) {
					found = true;
					rX1 = Stack.back().first; rY1 = Stack.back().first + d; rX2 = E[i][j].first + 1; rY2 = E[i][j].first + d + 1;
				}
			}
		}
	}
	if (found) {
		printf("YES ");
		for (int i = 0; i < n; i++)
			if (rX1 <= X1[i] && X2[i] <= rX2 && rY1 <= Y1[i] && Y2[i] <= rY2)
				res.push_back(i + 1);
		printf("%d\n", res.size());
		for (int i = 0; i < res.size(); i++)
			printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	} else printf("NO\n");
	return 0;
}