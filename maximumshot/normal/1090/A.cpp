#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;

const int inf = (int)1e9;
const ll md = (ll)1e9 + 7, inf64 = (ll)1e18;

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<vector<ll>> v(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        while (m--) {
            int x;
            cin >> x;
            v[i].push_back(x);
            mx = max(mx, x);
        }
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll cur = 0;
        for (ll x : v[i]) {
            cur = max(cur, x);
        }
        ans += v[i].size() * (mx - cur);
    }

    cout << ans << '\n';

    return 0;
}