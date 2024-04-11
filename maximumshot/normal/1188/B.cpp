#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, p, k;

    cin >> n >> p >> k;

    vector<int> a(n + 1);

    unordered_map<int, int> cnt;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        int v1 = (1ll * a[i] * a[i]) % p;
        v1 = (1ll * v1 * v1) % p;
        int v2 = (1ll * a[i] * k) % p;
        v1 = (v1 - v2 + p) % p;
        cnt[v1]++;
    }

    ll res = 0;

    for (auto it : cnt) {
        int t = it.second;
        res += 1ll * t * (t - 1) / 2;
    }

    cout << res << "\n";

    return 0;
}