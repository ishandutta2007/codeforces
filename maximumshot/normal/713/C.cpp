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

ll fast(int n, vector<int> a) {
    for (int i = 1; i <= n; i++)
        a[i] -= i;

    ll k, b;
    map<ll, ll> ps;

    { // init
        k = 0;
        b = 0;
        ps[a[1]] = 1;
    }

    for (int i = 2; i <= n; i++) {
        ps[a[i]] += 2;
        k++;
        b -= a[i];
        while (k > 0) {
            auto it = --ps.end();
            auto [x0, dk] = *it;
            dk = min(dk, k);
            k -= dk;
            b += dk * x0;
            if (it->second <= k) {
                ps.erase(it);
            } else {
                ps[x0] -= dk;
                break;
            }
        }
    }

    return b;
}

void work() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll res = fast(n, a);
    cout << res << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}