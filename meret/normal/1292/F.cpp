#include "bits/stdc++.h"

using namespace std;

typedef long long LL;

const int N = 65;
const int MX = (1<<20) + 5;
const int MD = (int)1e9 + 7;

int set_base[25];
int n_sets;

int n;
int a[N];

int best[MX];
int dp[MX];

bool is_base(int i) {
    for (int j = 0; j < i; ++j) {
        if (a[i] % a[j] == 0) {
            return false;
        }
    }
    int n_multiples = 0;
    for (int j = i + 1; j < n; ++j) {
        if (a[j] % a[i] == 0) {
            ++n_multiples;
        }
    }
    return n_multiples > 1;
}

inline void ad(int& a, int b) {
    a = (a + b) % MD;
}

inline int mul(int a, int b) {
    return (a * (LL)b) % MD;
}

int mpow(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b & 1) {
            result = mul(result, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return result;
}

int fact[N];
int rfact[N];

inline int min_element(int x) {
    if (x == 0) {
        return 1 << 28;
    }
    return x & -x;
}

inline int cao(int possible, int chosen) {
    return mul(fact[possible], rfact[possible - chosen]);
}

int main() {
    cin >> n;
    fact[0] = 1;
    rfact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = mul(fact[i - 1], i);
        rfact[i] = mpow(fact[i], MD - 2);
        assert(mul(fact[i], rfact[i]) == 1);
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        if (is_base(i)) {
            set_base[n_sets] = a[i];
            ++n_sets;
        }
    }
    int new_n = 0;
    for (int i = 0; i < n; ++i) {
        int set_mask = 0;
        for (int j = 0; j < n_sets; ++j) {
            if (a[i] > set_base[j] && a[i] % set_base[j] == 0) {
                set_mask |= 1 << j;
            }
        }
        if (set_mask > 0) {
            a[new_n] = set_mask;
            ++new_n;
        }
    }
    n = new_n;
    for (int mask = 0; mask < (1 << n_sets); ++mask) {
        best[mask] = 1000;
    }
    best[0] = 0;
    dp[0] = 1;
    for (int mask = 0; mask < (1 << n_sets); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (min_element(a[i]) < min_element(mask)) {
                int nx = mask | a[i];
                if (best[mask] + 1 < best[nx]) {
                    best[nx] = best[mask] + 1;
                    dp[nx] = 0;
                }
                if (best[mask] + 1 == best[nx]) {
                    ad(dp[nx], dp[mask]);
                }
            }
        }
    }
    for (int mask = 0; mask < (1 << n_sets); ++mask) {
        int fitting = 0;
        for (int i = 0; i < n; ++i) {
            if (!(a[i] & ~mask)) {
                ++fitting;
            }
        }
        dp[mask] = mul(dp[mask], cao(n - best[mask], fitting - best[mask]));
    }
    for (int mask = 0; mask < (1 << n_sets); ++mask) {
        int contained = 0;
        for (int i = 0; i < n; ++i) {
            if (!(a[i] & ~mask)) {
                ++contained;
            }
        }
        for (int i = 0; i < n; ++i) {
            if ((a[i] & mask) && (a[i] & ~mask)) {
                int nx = a[i] | mask;
                int fitting = 0;
                for (int j = 0; j < n; ++j) {
                    if (!(a[j] & ~nx) && (a[j] & ~mask) ) {
                        ++fitting;
                    }
                }
                if (best[mask] < best[nx]) {
                    best[nx] = best[mask];
                    dp[nx] = 0;
                }
                if (best[mask] == best[nx]) {
                    ad(dp[nx], mul(dp[mask], cao(n - contained - 1, fitting - 1)));
                }
            }
        }
    }
    cout << dp[(1 << n_sets) - 1] << endl;
}