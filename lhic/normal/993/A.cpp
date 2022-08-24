#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

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
#define y1 asdfasf

int x1[4];
int x2[4];
int y1[4];
int y2[4];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	for (int i = 0; i < 4; ++i)
		cin >> x1[i] >> y1[i];
	for (int i = 0; i < 4; ++i)
		cin >> x2[i] >> y2[i];
	sort(x1, x1 + 4);
	sort(y1, y1 + 4);
	sort(x2, x2 + 4);
	sort(y2, y2 + 4);
	for (int i = x1[0]; i <= x1[3]; ++i)
		for (int j = y1[0]; j <= y1[3]; ++j) {
			if (i + j <= x2[3] + y2[2])
				if (i + j >= x2[0] + y2[2])
					if (i - j >= -y2[3] + x2[2])
						if (i - j <= x2[3] - y2[2]) {
							cout << "YES\n";
							return 0;
						}
		}
	cout << "NO\n";
	return 0;
}