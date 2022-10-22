#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxl = 100005;

int n, k;
char s[Maxl];
int sum[Maxl];

int Get(int x)
{
	if (x < 0) return 0;
	if (x >= n) return sum[n - 1];
	return sum[x];
}

bool Possible(int val)
{
	for (int i = 0; i < n; i++)
		if (s[i] == '0') {
			int got = (Get(i - 1) - Get(i - val - 1)) + (Get(i + val) - Get(i));
			if (got >= k) return true;
		}
	return false;
}

int main()
{
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	for (int i = 0; i < n; i++) {
		sum[i] = i? sum[i - 1]: 0;
		if (s[i] == '0') sum[i]++;
	}
	int l = 1, r = n + 5;
	int res;
	while (l <= r) {
		int m = l + r >> 1;
		if (Possible(m)) { res = m; r = m - 1; }
		else l = m + 1;
	}
	printf("%d\n", res);
	return 0;
}