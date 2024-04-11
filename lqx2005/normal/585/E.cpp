#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef double db;
const int N = 1e7 + 10, P = 1e9 + 7, V = N - 10;
int n, p2[N];
int p[N], vis[N], cnt[N], tot = 0, tmp[N];

int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % P)
		if(b & 1)
			c = 1ll * c * a % P;
	return c;
}

void sieve(int n) {
	vis[0] = vis[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) p[++tot] = i;
		for(int j = 1; j <= tot && i * p[j] <= n; j++) {
			vis[i * p[j]] = 1;
			if(i % p[j] == 0) break;
		}
	}
	p2[0] = 1;
	for(int i = 1; i <= n; i++) p2[i] = 2ll * p2[i - 1] % P;
	return;
}

int main() {
	sieve(N - 10);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	for(int i = 1; i <= tot; i++) {
		for(int j = V / p[i]; j >= 1; j--) {
			cnt[j] += cnt[j * p[i]];
		}
	}
	for(int i = 1; i <= V; i++) tmp[i] = cnt[i];
	for(int i = 1; i <= V; i++) cnt[i] = (p2[cnt[i]] - 1 + P) % P;
	for(int i = 1; i <= tot; i++) {
		for(int j = 1; j <= V / p[i]; j++) {
			(cnt[j] += P - cnt[j * p[i]]) %= P;
		}
	}
	cnt[1] = 0;
	for(int i = 1; i <= tot; i++) {
		for(int j = V / p[i]; j >= 1; j--) {
			(cnt[j] += cnt[j * p[i]]) %= P;
		}
	}
	for(int i = 1; i <= V; i++) cnt[i] = 1ll * cnt[i] * tmp[i] % P;
	for(int i = 1; i <= tot; i++) {
		for(int j = 1; j <= V / p[i]; j++) {
			(cnt[j] += P - cnt[j * p[i]]) %= P;
		}
	}
	printf("%d\n", cnt[1]);
	return 0;
}