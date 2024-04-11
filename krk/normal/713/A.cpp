#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

const int Maxn = 18;

int t;
int has[1 << Maxn];
char str[Maxn + 5];

int Mask(ll a)
{
	int mask = 0;
	for (int i = 0; i < Maxn; i++) {
		mask |= a % 2 << i;
		a /= 10;
	}
	return mask;
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		char ch; scanf(" %c", &ch);
		if (ch == '+') {
			ll a; scanf("%I64d", &a);
			has[Mask(a)]++;
		} else if (ch == '-') {
			ll a; scanf("%I64d", &a);
			has[Mask(a)]--;
		} else {
			scanf("%s", str);
			int slen = strlen(str);
			int mask = 0;
			for (int i = 0; i < slen; i++)
				if (str[slen - 1 - i] == '1') mask |= 1 << i;
			printf("%d\n", has[mask]);
		}
	}
	return 0;
}