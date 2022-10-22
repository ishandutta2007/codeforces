#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];

int main()
{
	scanf("%d", &n); n *= 2;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int res = 2000000000;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			vector <int> V;
			for (int k = 0; k < n; k++) if (k != i && k != j)
				V.push_back(a[k]);
			sort(V.begin(), V.end());
			int cand = 0;
			for (int i = 0; i < V.size(); i += 2)
				cand += V[i + 1] - V[i];
			res = min(res, cand);
		}
	printf("%d\n", res);
	return 0;
}