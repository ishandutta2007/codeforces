#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 1e6, M = N * 2 + 10, K = 6, P1 = 998244353, P2 = 1e9 + 7;
i64 n;
int ans = 0;
int del[K + 1][M], sum[K + 1][M], tot[K + 1];
void Add(int &x, int y) {if((x += y) >= P2) x -= P2; }
void Sub(int &x, int y) {if((x -= y) < 0) x += P2; }
string To_string(int x, int y) {
	string num;
	for(int i = 0; i < y; i++, x /= 10) {
		num.push_back(x % 10);
	}
	reverse(num.begin(), num.end());
	return num;
}

void dfs1(int now, int len, int &rank) {
	if(len > K) return;
	rank++;
	del[len][++tot[len]] = (rank - now + P1) % P1;
	for(int i = 0; i < 10; i++) dfs1(now * 10 + i, len + 1, rank);
	return;
}

void dfs2(i64 now, int &rank) {
	if(now > n) return;
	if(now * N * 10 > n && now * N + N - 1 <= n) {
		int p10 = 1, res = rank;
		for(int i = 0; i <= K; i++) {
			int d = (rank - 1ll * now * p10 % P1 + P1) % P1;
			int p = lower_bound(del[i] + 1, del[i] + tot[i] + 1, P1 - d) - del[i];
			Add(ans, 1ll * tot[i] * d % P2);
			Add(ans, sum[i][tot[i]]);
			Sub(ans, 1ll * (tot[i] - p + 1) * P1 % P2);
			(res += p10) %= P1;
			p10 *= 10;
		}
		rank = res;
	} else {
		rank = (rank + 1) % P1;
		Add(ans, (rank - now % P1 + P1) % P1);
		for(int i = 0; i < 10; i++) dfs2(now * 10 + i, rank);
	}
	return;
}

int main() {
	scanf("%lld", &n);
	int cnt = 0;
	dfs1(0, 0, cnt);
	for(int i = 0; i <= K; i++) {
		sort(del[i] + 1, del[i] + tot[i] + 1);
		for(int j = 1; j <= tot[i]; j++) sum[i][j] = (sum[i][j - 1] + del[i][j]) % P2;
	}
	cnt = 0;
	for(int i = 1; i < 10; i++) dfs2(i, cnt);
	printf("%d\n", ans);
	return 0;
}