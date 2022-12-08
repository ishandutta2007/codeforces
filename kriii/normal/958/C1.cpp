#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

void proc()
{
	int N, P, A[100100];

	scanf("%d %d", &N, &P);
	long long S = 0, s = 0, ans = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		S = (S + A[i]) % P;
	}

	for (int i = 0; i < N - 1; i++) {
		s = (s + A[i]) % P;
		S = (S + P - A[i] % P) % P;
		if (ans < s + S)
			ans = s + S;
	}
	printf("%lld\n", ans);
}

int main()
{
#ifdef __LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	proc();
	return 0;
}