#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

int T;
int n, k;

int main()
{
	scanf("%d", &T);
	while (T--) {
		int res = 1;
		scanf("%d %d", &n, &k);
		for (int i = 0; i < k; i++)
			res = ll(res) * n % mod;
		printf("%d\n", res);
	}
    return 0;
}