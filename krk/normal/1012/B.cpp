#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, m, q;
vector <int> fromR[Maxn], fromC[Maxn];
bool R[Maxn], C[Maxn];
int res;

void fillC(int c);

void fillR(int r)
{
	if (R[r]) return;
	R[r] = true;
	for (int i = 0; i < fromR[r].size(); i++)
		fillC(fromR[r][i]);
}

void fillC(int c)
{
	if (C[c]) return;
	C[c] = true;
	for (int i = 0; i < fromC[c].size(); i++)
		fillR(fromC[c][i]);
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	while (q--) {
		int r, c; scanf("%d %d", &r, &c);
		fromR[r].push_back(c);
		fromC[c].push_back(r);
	}
	for (int i = 1; i <= n; i++)
		if (!R[i]) {
			res++;
			fillR(i);
		}
	for (int i = 1; i <= m; i++)
		if (!C[i]) {
			res++;
			fillC(i);
		}
	printf("%d\n", res - 1);
	return 0;
}