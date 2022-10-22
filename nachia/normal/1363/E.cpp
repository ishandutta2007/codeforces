#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

UL N;
vector<UL> E[200000];
UL P[200000];
UL C[200000];
pair<UL, UL> D[200000];

pair<UL, UL> operator+(const pair<UL, UL> & l, const pair<UL, UL> & r) {
	return make_pair(l.first + r.first, l.second + r.second);
}

int main() {
	scanf("%u", &N);
	{
		int K = 0;
		rep(i, N) {
			UL a, b, c; scanf("%u%u%u", &a, &b, &c);
			C[i] = a;
			if (b == 1 && c == 0) { K--; D[i].first++; }
			if (b == 0 && c == 1) { K++; D[i].second++; }
		}
		if (K != 0) { printf("-1"); return 0; }
	}
	rep(i, N - 1) {
		UL u, v; scanf("%u%u", &u, &v); u--; v--;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	rep(i, N) P[i] = ~0u;
	queue<UL> Q; Q.push(0);
	stack<UL> S;
	while (Q.size()) {
		UL p = Q.front(); Q.pop();
		for (UL e : E[p]) {
			if (e == P[p]) continue;
			P[e] = p;
			C[e] = min(C[e], C[p]);
			Q.push(e);
			S.push(e);
		}
	}
	ULL ans = 0;
	while (S.size()) {
		UL p = S.top(); S.pop();
		UL t = min(D[p].first, D[p].second);
		ans += (ULL)t * C[p];
		D[p].first -= t; D[p].second -= t;
		D[P[p]] = D[P[p]] + D[p];
	}
	ans += (ULL)D[0].first * C[0];
	ans *= 2;
	printf("%llu", ans);
	return 0;
}