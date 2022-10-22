#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)


UL N;
LL X;
LL Y;
LL D[200005] = {};
LL A[200005] = {};
LL B[200005] = {};
vector<pair<LL, LL>> F;

int main() {
	scanf("%u%llu", &N, &X);
	rep(i, N) scanf("%lld", &D[i]);
	Y = 0; rep(i, N) Y += D[i];
	B[0] = 0;
	rep(i, N) B[i + 1] = D[i];
    rep(i, N - 1) B[i + 2] += B[i + 1];
	rep(i, N) A[i + 1] = (B[i] + (Y - X)) % Y;
	sort(A + 1, A + N + 1);
	A[0] = A[N] - Y;
    A[N + 1] = Y + 10;
	B[N + 1] = Y + 10;
	{
		UL p = 0, q = 1;
		while (p <= N || q <= N) {
			if (B[p] <= A[q]) {
				F.push_back({ B[p], B[p] - A[q - 1] });
				p++;
			}
			else {
				F.push_back({ A[q], B[p - 1] - A[q] });
			q++;
			}
		}
	}
	F.push_back({ Y, 0 });
	LL ans = 0;
	rep(i, F.size() - 1) F[i].second *= F[i + 1].first - F[i].first;
	rep(i, F.size() - 1) {
		F[i + 1].second += F[i].second;
		ans = max(ans, F[i].second);
	}
	rep(i, N) {
		LL d = min(D[i], X);
		ans += d * (d + 1) / 2;
		X -= d;
	}
	printf("%lld", ans);
	return 0;
}