#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int a00, a01, a10, a11;
int cnt[Maxn];

int Get(int x)
{
	int my = 1;
	while (ll(my) * (my - 1) / 2 <= x)
		my++;
	my--;
	return ll(my) * (my - 1) / 2 == x? my: -1;
}

void Print(int hm, char ch = '1')
{
	while (hm--)
		printf("%c", ch);
}

int main()
{
	scanf("%d %d %d %d", &a00, &a01, &a10, &a11);
	int a = Get(a00), b = Get(a11);
	if (a == -1 || b == -1) { printf("Impossible\n"); return 0; }
	if (a00 == 0 && a01 == 0 && a10 == 0) {
		Print(b); printf("\n");
		return 0;
	}
	if (a01 == 0 && a10 == 0 && a11 == 0) {
		Print(a, '0'); printf("\n");
		return 0;
	}
	if (ll(a) * b != a01 + a10) { printf("Impossible\n"); return 0; }
	for (int i = 0; i < b; i++) {
		int tk = min(a, a01);
		cnt[tk]++; a01 -= tk; a10 -= (a - tk);
	}
	Print(cnt[0]);
	for (int i = 1; i <= a; i++) {
		printf("0");
		Print(cnt[i]);
	}
	printf("\n");
	return 0;
}