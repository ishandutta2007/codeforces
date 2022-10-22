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

    ll n, k;
    int m;

    cin >> n >> m >> k;

    set<ll> q;

    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        q.insert(x - 1);
    }

    int res = 0;
    ll sh = 0;

    while (!q.empty()) {
        ll  b = (*q.begin() - sh) / k;
        ll tmp = 0;
        while (!q.empty() && (*q.begin() - sh) / k == b) {
            q.erase(q.begin());
            tmp++;
        }
        res++;
        sh += tmp;
    }

    cout << res << "\n";

    return 0;
}