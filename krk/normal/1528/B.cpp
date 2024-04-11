#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int Maxn = 1000005;

int n;
int res[Maxn];
int sum;

int main()
{
	for (int i = 1; i < Maxn; i++)
		for (int j = i + i; j < Maxn; j += i)
			res[j]++;
	sum = 1;
	for (int i = 1; i < Maxn; i++) {
		res[i] = (res[i] + sum) % mod;
		sum = (sum + res[i]) % mod;
	}
	scanf("%d", &n);
	printf("%d\n", res[n]);
    return 0;
}