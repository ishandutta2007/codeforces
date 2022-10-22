#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int A, B, K;
int cntA[Maxn], cntB[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &A, &B, &K);
		fill(cntA, cntA + A + 1, 0);
		fill(cntB, cntB + B + 1, 0);
		for (int i = 0; i < K; i++) {
			int num; scanf("%d", &num);
			cntA[num]++;
		}
		for (int i = 0; i < K; i++) {
			int num; scanf("%d", &num);
			cntB[num]++;
		}
		ll res = ll(K) * (K - 1) / 2;
		for (int i = 1; i <= A; i++)
			res -= ll(cntA[i]) * (cntA[i] - 1) / 2;
		for (int i = 1; i <= B; i++)
			res -= ll(cntB[i]) * (cntB[i] - 1) / 2;
		printf("%I64d\n", res);
	}
    return 0;
}