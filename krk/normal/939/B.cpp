#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxk = 100005;

ll N;
int K;
ll A[Maxk];
ll best = -1;
int bi;

int main()
{
	scanf("%I64d %d", &N, &K);
	for (int i = 1; i <= K; i++) {
		scanf("%I64d", &A[i]);
		if (N / A[i] * A[i] > best) {
			best = N / A[i] * A[i];
			bi = i;
		}
	}
	printf("%d %I64d\n", bi, N / A[bi]);
	return 0;
}