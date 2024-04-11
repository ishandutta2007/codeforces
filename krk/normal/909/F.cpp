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

const int Maxn = 100005;

int n;
int P[Maxn], Q[Maxn];

void genP(int n)
{
	if (n == 0) return;
	int bts = 0;
	while ((1 << bts) <= n) bts++;
	int lef = (((1 << bts) - 1) ^ n);
	for (int i = lef; i <= n; i++)
		P[i] = lef + n - i;
	genP(lef - 1);
}

void solveP()
{
	genP(n);
	for (int i = 1; i <= n; i++)
		printf("%d%c", P[i], i + 1 <= n? ' ': '\n');
}

bool Power(int n)
{
	while (n % 2 == 0) n /= 2;
	return n == 1;
}

void solveQ()
{
	if (n == 6) printf("3 6 1 5 4 2\n");
	else if (n == 7) printf("3 6 1 5 4 7 2\n");
	else {
		Q[1] = 3; Q[2] = 6; Q[3] = 1; Q[4] = 5; Q[5] = 4; Q[6] = 7; Q[7] = 2;
		for (int i = 8; i <= n; i <<= 1) {
			int lim = min((i << 1) - 1, n);
			for (int j = i; j < lim; j++)
				Q[j] = j + 1;
			Q[lim] = i;
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c", Q[i], i + 1 <= n? ' ': '\n');
	}
}

int main()
{
	scanf("%d", &n);
	if (n % 2 == 1) printf("NO\n");
	else {
		printf("YES\n");
		solveP();
	}
	if (Power(n) || n <= 5) printf("NO\n");
	else {
		printf("YES\n");
		solveQ();
	}
	return 0;
}