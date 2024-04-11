#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005;
const int Maxd = 4;
const int dx[Maxd] = {1, 0, -1, 0};
const int dy[Maxn] = {0, -1, 0, 1};

char tmp[Maxn];
int n, m;
string B[Maxn];
int res;
vector <int> neigh[Maxn];
int cur, low[Maxn], tim[Maxn];
bool onStack[Maxn];
vector <int> S;
int my[Maxn], mylen;
int in[Maxn];

void Read(string &s)
{
	scanf("%s", tmp);
	s = tmp;
}

int Id(int r, int c) { return r * m + c; }

bool inGrid(int r, int c)
{
	return 0 <= r && r < n && 0 <= c && c < m;
}

void Fill(int r, int c)
{
	if (r < 0 || r >= n || c < 0 || c >= m || B[r][c] == 'X' || B[r][c] == 'Y') return;
	B[r][c] = B[r][c] == '#'? 'Y': 'X';
	for (int i = 0; i < Maxd; i++) {
		int nr = r + dx[i], nc = c + dy[i];
		if (inGrid(nr, nc))
			if (i == 0 || B[nr][nc] == '#' || B[nr][nc] == 'Y') {
				neigh[Id(r, c)].push_back(Id(nr, nc));
				Fill(nr, nc);
			}
	}
}

void SCC(int v)
{
	low[v] = tim[v] = ++cur;
	S.push_back(v);
	onStack[v] = true;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (!tim[u]) { SCC(u); low[v] = min(low[v], low[u]); }
		else if (onStack[u]) low[v] = min(low[v], tim[u]);
	}
	if (tim[v] == low[v]) {
		mylen++;
		int u;
		do {
			u = S.back(); S.pop_back();
			onStack[u] = false;
			my[u] = mylen;
		} while (u != v);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		Read(B[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (B[i][j] == '#')
				Fill(i, j);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (B[i][j] == 'Y') {
			int v = Id(i, j);
			if (!tim[v]) SCC(v);
		}
	for (int i = 0; i < n * m; i++)
		for (int j = 0; j < neigh[i].size(); j++) {
			int a = my[i], b = my[neigh[i][j]];
			if (a != b) in[b]++;
		}
	for (int i = 1; i <= mylen; i++) if (!in[i])
		res++;
	printf("%d\n", res);
    return 0;
}