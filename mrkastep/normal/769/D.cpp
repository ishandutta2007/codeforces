#include <bits/stdc++.h>


#define pb push_back
#define eb emplace_back
#define mp make_pair
#define x first
#define y second

#ifdef _DEBUG
#define gets gets_s
#endif

typedef long long ll;

const int INF = 2e9;
const int mod = 1e9 + 7;

using namespace std;

ll s[20100];

void solve() {
    for (int i = 0; i < 20100; ++i) {
        s[i] = 0;
    }
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        ++s[a];
    }
    ll ans = 0;
    if (k == 0)
        for (int i = 0; i < 10100; ++i)
            ans += s[i] * (s[i] - 1);
    else
        for (int d = 0; d < (1 << 14); ++d)
            if (__builtin_popcount(d) == k)
                for (int i = 0; i < 10100; ++i)
                    ans += s[i] * s[i ^ d];
    cout << ans / 2;
}

int main() {
    solve();
    return 0;
}