#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 2000005;
const int Maxl = 26;
const int mod = 1000000007;

int n, k;
char s[Maxn];
int slen;
int bef[Maxl], was[Maxl];

int main()
{
	scanf("%d %d", &n, &k);
	scanf("%s", s + 1); slen = strlen(s + 1);
	int res = 1;
	for (int i = 1; i <= slen; i++) {
		int let = s[i] - 'a';
		int tmp = res;
		res = 2ll * ll(res) % mod;
		if (was[let]) res = (res - bef[let] + mod) % mod;
		bef[let] = tmp; was[let] = i;
	}
	for (int i = slen + 1; i <= slen + n; i++) {
		int let = 0;
		for (int j = 1; j < k; j++)
			if (was[j] < was[let]) let = j;
		int tmp = res;
		res = 2ll * ll(res) % mod;
		if (was[let]) res = (res - bef[let] + mod) % mod;
		bef[let] = tmp; was[let] = i;
	}
	printf("%d\n", res);
	return 0;
}