#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const ll MAX = 1ll << 40;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, k;

    cin >> n >> k;

    string s, t;

    cin >> s >> t;

    ll res = 0;
    int lcp = 0;

    while(lcp < n && s[lcp] == t[lcp]) lcp++;

    if(lcp == n) {
        cout << n << "\n";
        return 0;
    }

    res += lcp;

    ll cur = 1;

    for(int i = lcp;i < n;i++) {
        cur = min(MAX, cur << 1);
        if(s[i] == 'b') cur--;
        if(t[i] == 'a') cur--;
        res += min((ll)k, cur);
    }

    cout << res << "\n";

    return 0;
}