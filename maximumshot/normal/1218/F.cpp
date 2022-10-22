#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n, k, a;
int x[N], c[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    cin >> a;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    ll cur = k;
    ll res = 0;

    set<int> qq;

    for (int i = 1; i <= n; i++) {
        qq.insert(c[i]);
        while (!qq.empty() && cur < x[i]) {
            auto fnd = qq.begin();
            res += *fnd;
            qq.erase(fnd);
            cur += a;
        }
        if (cur < x[i]) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << res << "\n";

    return 0;
}