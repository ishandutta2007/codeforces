#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

UL N, M;
pair<UL, UL> T[500000];
UL A[500000];
vector<UL> E[500000];

int main() {
	UL N, M; scanf("%u%u", &N, &M);
	rep(i, M) {
		UL u, v; scanf("%u%u", &u, &v); u--; v--;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	rep(i, N) {
		scanf("%u", &T[i].first);
		T[i].second = i;
	}
	sort(T, T + N);
	rep(i, N) A[i] = 1;
	rep(i, N) {
		if (A[T[i].second] != T[i].first) { printf("-1"); return 0; }
		for (UL e : E[T[i].second]) if (A[e] == T[i].first) A[e]++;
	}
	rep(i, N) {
		if (i) printf(" ");
		printf("%u", T[i].second + 1);
	}
	return 0;
}