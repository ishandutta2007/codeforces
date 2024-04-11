#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxm = 1000005;

int mx[Maxm];
int has[Maxm];
int n, k;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
	for (int i = 2; i < Maxm; i++) if (mx[i] == 0)
		for (int j = i; j < Maxm; j += i) mx[j] = i;
	scanf("%d %d", &n, &k);
	while (k > 1) {
		has[mx[k]]++;
		k /= mx[k];
	}
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		while (a > 1) {
			int cur = mx[a];
			int cnt = 0;
			while (a % cur == 0) {
				cnt++; a /= cur;
			}
			if (has[cur] <= cnt) has[cur] = 0;
		}
	}
	for (int i = 1; i < Maxm; i++)
		if (has[i] > 0) { printf("No\n"); return 0; }
	printf("Yes\n");
	return 0;
}