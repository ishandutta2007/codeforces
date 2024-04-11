#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 500005;

int n;
int p[Maxn];
char str[Maxn];
ll LA[Maxn], LB[Maxn];
ll RA[Maxn], RB[Maxn];
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	scanf("%s", str + 1);
	LA[0] = LB[0] = 0;
	for (int i = 1; i <= n; i++) {
		LA[i] = LA[i - 1]; LB[i] = LB[i - 1];
		if (str[i] == 'A') LA[i] += p[i];
		else if (str[i] == 'B') LB[i] += p[i];
	}
	RA[n + 1] = RB[n + 1] = 0;
	for (int i = n; i >= 1; i--) {
		RA[i] = RA[i + 1]; RB[i] = RB[i + 1];
		if (str[i] == 'A') RA[i] += p[i];
		else if (str[i] == 'B') RB[i] += p[i];
	}
	for (int i = 0; i <= n; i++)
		res = max(res, max(LA[i] + RB[i + 1], LB[i] + RA[i + 1]));
	printf("%I64d\n", res);
	return 0;
}