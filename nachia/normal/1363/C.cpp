#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

UL N, X;
vector<UL> E[1000];
UL P[1000];
UL G[1000] = {};

void Loop() {
	scanf("%u%u", &N, &X); X--;
	rep(i, N) E[i].clear();
	rep(i, N - 1) {
		UL u, v; scanf("%u%u", &u, &v); u--; v--;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	bool ans = false;
	if (E[X].size() <= 1) ans = true;
	else ans = !(N & 1);
	printf(ans ? "Ayush\n" : "Ashish\n");
}

int main() {
	UL T; scanf("%u", &T);
	rep(t, T) Loop();
	return 0;
}