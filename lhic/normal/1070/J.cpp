#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = uint64_t;

using namespace std;

int n, m, k;

const int MAXK = 200228;
const int L = 26;

int l[L + 1][MAXK];
int r[L + 1][MAXK];

int cn[L];

void g(int* prev, int* nxt, int c) {
    copy(prev, prev + k + 1, nxt);
    for (int i = c; i <= k; ++i) {
        nxt[i] = min(nxt[i], prev[i - c]);
    }
}

ll gall(int* lhs, int* rhs, int n) {
    int ans = k;
    for (int i = 0; i <= n; ++i) {
        ans = min(ans, lhs[i] + rhs[n - i]);
    }

    return ans;
}

void solve() {
    fill(cn, cn + L, 0);
    cin >> n >> m >> k;
    string s;
    cin >> s;
    for (char c: s) {
        ++cn[c - 'A'];
    }


    for (int i = 0; i <= k; ++i) {
        l[0][i] = r[L][i] = i;
    }

    for (int i = 0; i < L; ++i) {
        g(l[i], l[i + 1], cn[i]);
    }

    for (int i = L; i > 0; --i) {
        g(r[i], r[i - 1], cn[i - 1]);
    }
	for (int i = n; i + m <= k; ++i) {
		if (l[L][i] == 0) {
			cout << 0 << "\n";
			return;
		}
	}

    ll ans = ll(k) * (k + 1);

    for (int i = 0; i < L; ++i) {
        int lg = min(gall(l[i], r[i + 1], n), gall(l[i], r[i + 1], m));
        if (lg >= cn[i]) {
            continue;
        }

        int rg = max(0, m + n + cn[i] - k - lg);
        ans = min(ans, ll(lg) * rg);
    }

    cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
	return 0;
}