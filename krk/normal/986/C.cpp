#include <bits/stdc++.h>
using namespace std;

const int Maxm = 1 << 22;
const int Maxn = 22;

int n, m;
int a[Maxm];
vector <int> has[Maxm];
bool don[Maxm];
bool tk[Maxm];
int res;

void Fill(int x);

void fillAll(int val)
{
	if (don[val]) return;
	don[val] = true;
	for (int j = 0; j < has[val].size(); j++) {
		int u = has[val][j];
		if (!tk[u]) Fill(u);
	}
	for (int j = 0; j < Maxn; j++) if (val & 1 << j)
		fillAll(val ^ 1 << j);
}

void Fill(int x)
{
	tk[x] = true;
	fillAll((Maxm - 1) ^ a[x]);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
		has[a[i]].push_back(i);
	}
	int res = 0;
	for (int i = 0; i < m; i++) if (!tk[i]) {
		res++; Fill(i);
	}
	printf("%d\n", res);
	return 0;
}