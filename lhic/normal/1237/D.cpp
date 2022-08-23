#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int N = 310000;

int n;
int a[N];

deque<int> dq;

void add(int x) {
    while (!dq.empty() && dq.back() < x) {
        dq.pop_back();
    }
    dq.push_back(x);
}

void del(int x) {
    if (!dq.empty() && dq.front() == x) {
        dq.pop_front();
    }
}

int get() {
    if (dq.empty()) {
        return 0;
    } else {
        return dq.front();
    }
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[n + i] = a[i];
        a[n + n + i] = a[i];
    }
    int mn = *min_element(a, a + n);
    int mx = *max_element(a, a + n);
    if (mn * 2 >= mx) {
        for (int i = 0; i < n; ++i) {
            cout << -1 << " ";
        }
        cout << "\n";
        return 0;
    }

    int now = 0;
    for (int i = 0; i < n; ++i) {
        while (a[now] * 2 >= get()) {
            add(a[now]);
            ++now;
        }
        cout << now - i << " ";
        del(a[i]);
    }

	return 0;
}