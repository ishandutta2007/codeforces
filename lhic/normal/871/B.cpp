#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int MAXN = 5100;

int n;

int ax[MAXN], bx[MAXN];
int ans[MAXN];
int a[MAXN], b[MAXN];

int ask(int x, int y) {
	cout << "? " << x << " " << y << "\n";
	cout.flush();
	int ans;
	cin >> ans;
	return ans;
}


int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ax[i] = ask(i, 0);
	}
	for (int i = 0; i < n; ++i) {
		bx[i] = ask(0, i);
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		a[0] = i;
		for (int j = 1; j < n; ++j)
			a[j] = a[j - 1] ^ ax[j] ^ ax[j - 1];
		for (int j = 0; j < n; ++j)
			b[a[j]] = j;
		int fl = 0;
		for (int j = 0; j < n; ++j)
			if (ax[j] != (a[j] ^ b[0]) || bx[j] != (b[j] ^ a[0]))
				fl = 1;
		if (!fl) {
			for (int i = 0; i < n; ++i)
				ans[i] = a[i];
			++cnt;
		}
	}
	cout << "!\n";
	cout << cnt << "\n";
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
	cout.flush();
	return 0;
}