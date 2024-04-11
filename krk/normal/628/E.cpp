#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 3005;
const int Maxm = 6015;
const int Maxs = 32768;

int n, m;
char B[Maxn][Maxn];
int L[Maxn][Maxn], R[Maxn][Maxn];
int T[Maxn][Maxn];
int ID[Maxn][Maxn];
vector <int> V[Maxs];
ll res;

void Clear(int v, int l, int r)
{
	V[v].clear();
	if (l < r) {
		int m = l + r >> 1;
		Clear(2 * v, l, m); Clear(2 * v + 1, m + 1, r);
	}
}

void Insert(int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) V[v].push_back(val);
	else {
		int m = l + r >> 1;
		if (a <= m) Insert(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Insert(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
	}
}

int Get(int v, int l, int r, int x, int val)
{
	int res = V[v].end() - lower_bound(V[v].begin(), V[v].end(), val);
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) res += Get(2 * v, l, m, x, val);
		else res += Get(2 * v + 1, m + 1, r, x, val);
	}
	return res;
}

void Diag(int r, int c)
{
	int tp = 0;
	while (r < n && c >= 0) {
		if (B[r][c] == 'z') tp++;
		else tp = 0;
		T[r][c] = tp;
		r++; c--;
	}
}

void Diag2(int r, int c)
{
	int cr = r, cc = c;
	int id = 0;
	while (cr >= 0 && cc < m) {
		ID[cr][cc] = id++;
		cr--; cc++;
	}
	Clear(1, 0, id - 1);
	cr = r, cc = c;
	while (cr >= 0 && cc < m) {
		if (B[cr][cc] == 'z') {
			int mx = ID[cr][cc] + min(R[cr][cc], T[cr][cc]) - 1;
			Insert(1, 0, id - 1, ID[cr][cc], min(id - 1, mx), ID[cr][cc]);
			int mn = ID[cr][cc] - L[cr][cc] + 1;
			res += Get(1, 0, id - 1, ID[cr][cc], mn);
		}
		cr--; cc++;
	}
}

int main() 
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	for (int i = 0; i < n; i++) {
		int tp = 0;
		for (int j = 0; j < m; j++) {
			if (B[i][j] == 'z') tp++;
			else tp = 0;
			L[i][j] = tp;
		}
		tp = 0;
		for (int j = m - 1; j >= 0; j--) {
			if (B[i][j] == 'z') tp++;
			else tp = 0;
			R[i][j] = tp;
		}
	}
	for (int j = 0; j < m; j++)
		Diag(0, j);
	for (int i = 1; i < n; i++)
		Diag(i, m - 1);
	for (int j = 0; j < m; j++)
		Diag2(n - 1, j);
	for (int i = 0; i < n - 1; i++)
		Diag2(i, 0);
	printf("%I64d\n", res);
    return 0;
}