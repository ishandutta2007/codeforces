#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 100005;
const int Maxm = 512;

int n, m;
vector <int> neigh[Maxn];
int tk[Maxn];
int nim[Maxn];
int hm[Maxm];
int B[Maxm][Maxm + 1];
int myrow[Maxm];
int res[Maxm];

int getNim(int v)
{
	if (!tk[v]) {
		tk[v] = true;
		set <int> S;
		for (int i = 0; i < neigh[v].size(); i++)
			S.insert(getNim(neigh[v][i]));
		while (S.find(nim[v]) != S.end()) nim[v]++;
	}
	return nim[v];
}

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

void Swap(int r1, int r2)
{
	for (int j = 0; j <= Maxm; j++)
		swap(B[r1][j], B[r2][j]);
}

void Sub(int r1, int r2, int c)
{
	if (B[r2][c] == 0) return;
	int mult = (mod - ll(B[r2][c]) * Inv(B[r1][c]) % mod) % mod;
	for (int j = c; j <= Maxm; j++)
		B[r2][j] = (B[r2][j] + ll(B[r1][j]) * mult) % mod;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		if (!tk[i]) nim[i] = getNim(i);
		hm[nim[i]]++;
	}
	int prob = Inv(n + 1);
	for (int i = 0; i < Maxm; i++) {
		B[i][i] = 1;
		for (int j = 0; j < Maxm; j++) {
			int nw = (i ^ j);
			B[i][nw] = (B[i][nw] - ll(hm[j]) * prob % mod + ll(mod)) % mod; 
		}
		B[i][Maxm] = i > 0? prob: 0;
	}
	int row = 0;
	for (int j = 0; j < Maxm; j++) {
		int pnt = row;
		while (pnt < Maxm && B[pnt][j] == 0) pnt++;
		if (pnt >= Maxm) { myrow[j] = -1; continue; }
		if (pnt > row) Swap(row, pnt);
		myrow[j] = row;
		for (int i = pnt + 1; i < Maxm; i++)
			Sub(row, i, j);
		row++;
	}
	for (int j = Maxm - 1; j >= 0; j--) if (myrow[j] != -1) {
		int i = myrow[j];
		int cur = B[i][Maxm];
		for (int j2 = j + 1; j2 < Maxm; j2++)
			cur = (cur - ll(res[j2]) * B[i][j2] % mod + mod) % mod;
		res[j] = ll(cur) * Inv(B[i][j]) % mod;
	}
	printf("%d\n", res[0]);
    return 0;
}