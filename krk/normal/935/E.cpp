#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;
const int Maxm = 105;
const int Inf = 1000000000;

string E;
int P, M;
bool cP;
int lim;
int nxt[Maxn];
vector <int> S;
int mn[Maxn][Maxm], mx[Maxn][Maxm];
int cur;

void Solve(int l, int r)
{
	int my = cur++;
	if (nxt[l] == l) mn[my][0] = mx[my][0] = E[l] - '0';
	else {
		int v = cur;
		Solve(l + 1, nxt[l + 1]);
		int mid = nxt[l + 1] + 1;
		int u = cur; 
		Solve(mid + 1, nxt[mid + 1]); 
		for (int i = 0; i <= lim; i++)
			for (int j = 0; i + j <= lim; j++) {
				int used = i + j;
				if (cP) used++;
				if (used <= lim) {
					mn[my][used] = min(mn[my][used], mn[v][i] + mn[u][j]);
					mx[my][used] = max(mx[my][used], mx[v][i] + mx[u][j]);
				}
				used = i + j;
				if (!cP) used++;
				if (used <= lim) {
					mn[my][used] = min(mn[my][used], mn[v][i] - mx[u][j]);
					mx[my][used] = max(mx[my][used], mx[v][i] - mn[u][j]);
				}
			}
	}
}

int main()
{
	cin >> E;
	for (int i = 0; i < E.length(); i++)
		if (E[i] == '(') S.push_back(i);
		else if (E[i] == ')') { nxt[S.back()] = i; S.pop_back(); }
		else nxt[i] = i;
	cin >> P >> M;
	cP = P <= M; lim = min(P, M);
	fill((int*)mn, (int*)mn + Maxn * Maxm, Inf);
	fill((int*)mx, (int*)mx + Maxn * Maxm, -Inf);
	Solve(0, int(E.length()) - 1);
	printf("%d\n", mx[0][lim]);
	return 0;
}