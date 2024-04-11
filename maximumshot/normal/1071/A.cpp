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

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b;

    cin >> a >> b;

    vector<ll> ra, rb;

    unordered_set<ll> used;

    ll cur = 1;

    while (a >= cur) {
        ra.push_back(cur);
        a -= cur;
        cur++;
    }

    for (int j = a, i = (int) ra.size() - 1; i >= 0 && j > 0; i--, j--) {
        ra[i]++;
    }

    for (ll x : ra) {
        used.insert(x);
    }

    cur = 1;

    while (b >= cur) {
        if (used.count(cur)) {
            cur++;
            continue;
        }
        b -= cur;
        rb.push_back(cur);
        cur++;
    }

    cout << (int) ra.size() << "\n";
    for (ll x : ra) cout << x << " ";
    cout << "\n";

    cout << (int) rb.size() << "\n";
    for (ll x : rb) cout << x << " ";
    cout << "\n";

    return 0;
}