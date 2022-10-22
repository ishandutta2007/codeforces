#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

UL N, K;
UL S[1000];

 bool Loop() {
	scanf("%u%u", &N, &K);
	rep(i, N) S[i] = K;
	rep(i, K) {
		UL C; scanf("%u", &C);
		rep(c, C) {
			UL j; scanf("%u", &j); j--;
			S[j] = i;
		}
	}

	int M;
	{
		printf("? %u", N);
		rep(i, N) printf(" %u", i + 1);
		printf("\n"); fflush(stdout);
		int res; scanf("%d", &res);
		if (res == -1) return false;
		M = res;
	}

	UL l, r; l = 0; r = K + 1;
	while (l + 1 < r) {
		UL m = (l + r) >> 1;
		printf("? ");
		vector<UL> Q;
		rep(i, N) if (l <= S[i] && S[i] < m) Q.push_back(i);
		printf("%u", Q.size());
		rep(i, Q.size()) printf(" %u", Q[i] + 1);
		printf("\n"); fflush(stdout);
		int res; scanf("%d", &res);
		if (res == -1) return false;
		if (M == res) r = m; else l = m;
	}

	int M2;
	{
		printf("? ");
		vector<UL> Q;
		rep(i, N) if (S[i] != l) Q.push_back(i);
		printf("%u", Q.size());
		rep(i, Q.size()) printf(" %u", Q[i] + 1);
		printf("\n"); fflush(stdout);
		int res; scanf("%d", &res);
		if (res == -1) return false;
		M2 = res;
	}

	{
		printf("!");
		rep(i, K) {
			if (i == l) printf(" %d", M2);
			else printf(" %d", M);
		}
		printf("\n"); fflush(stdout);
		string r; cin >> r;
		if (r == "Incorrect") return false;
	}
	return true;
}

int main() {
	UL T; scanf("%u", &T);
	rep(t, T) if (!Loop()) break;
	return 0;
}