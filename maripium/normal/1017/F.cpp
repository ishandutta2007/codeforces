#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;

int n;
unsigned int a, b, c, d;
unsigned int res = 0;
bool np[N];
int pr[N], lst[N];
int cnt = 0;

void add(unsigned int p) {
	unsigned int F = d + p * (c + p * (b + p * a));
	unsigned int A = 0;
	unsigned int pw = 1;
	while (1) {
		if (1ll * pw * p > 1ll * n) break;
		pw *= p; A += n / pw;
	}
	res += F * A;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> a >> b >> c >> d;
	for (int i = 2; i < N; ++i) if (!np[i]) {
		add(i); pr[++cnt] = i;
		lst[cnt] = i + i;
		while (lst[cnt] < N) {
			np[lst[cnt]] = 1;
			lst[cnt] += i;
		}
		lst[cnt] -= N;
	}
	
	for (int i = N; i <= n; i += N) {
		for (int j = 0; j < N; ++j) np[j] = 0;
		for (int j = 1; j <= cnt; ++j) {
			while (lst[j] < N) {
				np[lst[j]] = 1;
				lst[j] += pr[j];
			}
			lst[j] -= N;
		}
		for (int j = 0; j < N; ++j) if (!np[j]) {
			add(i + j);
		}
	}
	cout << res << '\n';
}