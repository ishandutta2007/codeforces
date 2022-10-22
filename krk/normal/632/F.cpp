#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef unsigned long long ull;

const int Maxn = 2500;
const int Maxd = 40;
const int Maxb = 64;

int n;
int a[Maxn][Maxn];
map <int, vector <ii> > M;
ull has[Maxn][Maxd];

void Insert(int row, int val)
{
	has[row][val / Maxb] |= ull(1) << ull(val % Maxb);
}

bool Check(int r1, int r2)
{
	for (int j = 0; j < Maxd; j++)
		if (has[r1][j] & has[r2][j]) return true;
	return false;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			if (i <= j) M[a[i][j]].push_back(ii(i, j));
			if (i == j && a[i][j]) { printf("NOT MAGIC\n"); return 0; }
			if (j < i && a[i][j] != a[j][i]) { printf("NOT MAGIC\n"); return 0; }
		}
	for (map <int, vector <ii> >::iterator it = M.begin(); it != M.end(); it++) {
		for (int j = 0; j < it->second.size(); j++) {
			ii p = it->second[j];
			if (Check(p.first, p.second)) { printf("NOT MAGIC\n"); return 0; }
		}
		for (int j = 0; j < it->second.size(); j++) {
			ii p = it->second[j];
			Insert(p.first, p.second);
			Insert(p.second, p.first);
		}
	}
	printf("MAGIC\n");
	return 0;
}