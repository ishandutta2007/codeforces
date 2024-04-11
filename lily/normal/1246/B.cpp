#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define N 100111

int n, K;
int a[N];
LL po[N];

bool vis[N];

int p[N], pcnt, cc[N];
map <int, int> cnt;
int main() {
	read(n); read(K);
	for (int i = 2; i < N; i++) {
		if (!vis[i]) p[++pcnt] = i;
		for (int j = 1, k; (k = i * p[j]) < N; j++) {
			vis[k] = 1;
			if (i % p[j] == 0) break;
		}
	}
	for (int i = 1; i <= int(1e5 + 5); i++) {
		po[i] = 1;
		if (po[i - 1] > 1e13) po[i] = po[i - 1];
		else for (int k = 1; k <= K; k++) {
			po[i] *= i;
			if (po[i] > 1e13) break;
		}
	}
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		for (int j = 2; po[j] <= a[i]; j++) {
			while (a[i] % po[j] == 0) a[i] /= int(po[j]);
		}
		LL co = 1, cura = a[i];
		for (int j = 2; co != -1 && j * j <= cura; j++) if (!vis[j]) {
			if (a[i] % j == 0) {
				LL q = j;
				while (a[i] % q == 0) q *= j;
				q /= j;
				cura /= q;
				if ((double)co * po[j] / q > N) co = -1;
				else co *= po[j] / q;
			}
		}
		if (co > 0 && cura > 1) {
			if ((double)co * po[cura] / cura > N) co = -1;
			else co *= po[cura] / cura;
		}
		if (co > 0 && co < N) {
			cc[i] = co;
		}
	}
	LL ans = 0;
	for (int i = n; i; i--) {
		if (cc[i] > 0) ans += cnt[cc[i]];
		cnt[a[i]]++;
	}
	cout << ans << endl;
}