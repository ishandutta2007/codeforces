#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int, int> cnt;
    ll res = 0;

    unordered_map<ll, int> pr;

    for (int w, h, i = 0; i < n; i++) {
        cin >> w >> h;
        cnt[w]++;
        if (w != h)
            cnt[h]++;
        if (w > h) swap(w, h);
        if (w < h) pr[1ll * (inf + 10) * w + h]++;
    }

    for (auto [h, c] : cnt) {
//        cout << h << " : " << c << "\n";
        res += 1ll * c * (c - 1) / 2;
    }

    for (auto [p, c] : pr) {
//        cout << p / (inf + 10) << " " << p % (inf + 10) << " : " << c << "\n";
        res -= 1ll * c * (c - 1) / 2;
    }

    cout << res << "\n";

    return 0;
}