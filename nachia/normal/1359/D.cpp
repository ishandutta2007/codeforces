#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

UL N;
int A[100000];
int ML[61][100000] = {};
int MR[61][100000] = {};
int ans = 0;

int main() {
	scanf("%u", &N);
	rep(i, N) scanf("%d", A + i);
	rep(j, 61) {
		rep(i, N - 1) {
			if (A[i] + 30 <= j) ML[j][i + 1] = max(0, ML[j][i] + A[i]);
			if (A[N - 1 - i] + 30 <= j) MR[j][N - 2 - i] = max(0, MR[j][N - 1 - i] + A[N - 1 - i]);
		}
	}
	rep(i, N) ans = max(ans, ML[A[i] + 30][i] + MR[A[i] + 30][i]);
	printf("%d\n", ans);
	return 0;
}