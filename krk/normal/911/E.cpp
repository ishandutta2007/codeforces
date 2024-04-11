#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxn = 200005;

int n, k;
int p[Maxn];
vector <int> S;
int nd;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++)
		scanf("%d", &p[i]);
	nd = 1;
	for (int i = 0; i < k; i++) {
		S.push_back(p[i]);
		while (!S.empty() && S.back() == nd) { nd++; S.pop_back(); }
		if (int(S.size()) >= 2 && S[int(S.size()) - 2] < S.back()) { printf("-1\n"); return 0; }
	}
	int pnt = k;
	while (nd <= n) {
		if (!S.empty() && nd == S.back()) { nd++; S.pop_back(); continue; }
		int lim = S.empty()? n + 1: S.back();
		for (int i = lim - 1; i >= nd; i--)
			p[pnt++] = i;
		nd = lim;
	}
	for (int i = 0; i < n; i++)
		printf("%d%c", p[i], i + 1 < n? ' ': '\n');
	return 0;
}