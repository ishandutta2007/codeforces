#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, k, m;

    cin >> n >> k >> m;

    vec< string > a(n);
    unordered_map< string, int > mp;

    for(int i = 0;i < n;i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }

    vec< int > cost(n);

    for(int& x : cost) cin >> x;

    vec< int > mn(k);
    vec< int > gr(n);

    for(int sz, i = 0;i < k;i++) {
        cin >> sz;
        int mnv = inf;
        for(int x, j = 0;j < sz;j++) {
            cin >> x;
            x--;
            gr[x] = i;
            mnv = min(mnv, cost[x]);
        }
        mn[i] = mnv;
    }

    ll res = 0;

    for(int i = 0;i < m;i++) {
        string s;
        cin >> s;
        int ps = mp[s];
        int g = gr[ps];
        int cs = mn[g];
        res += cs;
    }

    cout << res << "\n";

    return 0;
}