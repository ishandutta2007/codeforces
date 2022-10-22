#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;

bool dp[Maxn];

int T;
int n;

int main()
{
	dp[0] = true;
	for (int i = 0; i < Maxn; i++) if (dp[i]) {
		if (i + 11 < Maxn) dp[i + 11] = true;
		if (i + 111 < Maxn) dp[i + 111] = true;
		if (i + 1111 < Maxn) dp[i + 1111] = true;
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		printf("%s\n", n >= Maxn || dp[n]? "YES": "NO");
	}
    return 0;
}