#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int mod = 7;

int n, m;

int Cnt(int x)
{
	int res = 0;
	do {
		res++;
		x /= mod;
	} while (x);
	return res;
}

bool Ok(int x, int y, int a, int b)
{
	int cnt[mod] = {};
	for (int i = 0; i < a; i++) {
		if (cnt[x % mod]++ > 0) return false;
		x /= mod;
	}
	for (int i = 0; i < b; i++) {
		if (cnt[y % mod]++ > 0) return false;
		y /= mod;
	}
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	int a = Cnt(n - 1), b = Cnt(m - 1);
	if (a + b > 7) printf("0\n");
	else {
		int res = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (Ok(i, j, a, b)) res++;
		printf("%d\n", res);
	}
	return 0;
}