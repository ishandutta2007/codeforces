#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 1005;

int C[Maxn][Maxn];
int T;
int n, k;
int freq[Maxn];

int main()
{
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		fill(freq, freq + Maxn, 0);
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			freq[a]++;
		}
		int res = 1;
		for (int i = n; i > 0; i--)
			if (k >= freq[i]) k -= freq[i];
			else { res = C[freq[i]][k]; break; }
		printf("%d\n", res);
	}
    return 0;
}