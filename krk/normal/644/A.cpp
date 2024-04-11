#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, a, b;
int odd = 1, ev = 2;
int B[Maxn][Maxn];

int main()
{
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			if ((i + j) % 2 == 0) {
				if (odd <= n) { B[i][j] = odd; odd += 2; }
			} else {
				if (ev <= n) { B[i][j] = ev; ev += 2; }
			}
	if (odd <= n || ev <= n) printf("-1\n");
	else for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				printf("%d%c", B[i][j], j + 1 < b? ' ': '\n');
	return 0;
}