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

const int Maxn = 52;

int n;
int B[Maxn][Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &B[i][j]);
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++) if (B[x][y] != 1) {
			bool was = false;
			for (int s = 0; s < n && !was; s++)
				for (int t = 0; t < n && !was; t++)
					was = B[x][y] == B[x][s] + B[t][y];
			if (!was) { printf("No\n"); return 0; }
		}
	printf("Yes\n");
	return 0;
}