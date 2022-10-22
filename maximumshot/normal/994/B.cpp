#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

#define vec vector
#define ALL(x) begin(x), end(x)

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n, k;
int p[N];
int c[N];
pii perm[N];
ll pref[N];
ll res[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++) {
        cin >> p[i];
        perm[i] = {p[i], i};
    }

    sort(perm, perm + n);

    for(int i = 0;i < n;i++) {
        cin >> c[i];
    }

    multiset< int > ms;
    ll cur = 0;

    for(int i = 0;i < n;i++) {
        ms.insert(c[perm[i].second]);
        cur += c[perm[i].second];
        if(ms.size() > k) {
            cur -= *ms.begin();
            ms.erase(ms.begin());
        }
        pref[i] = cur;
    }

    for(int i = 0;i < n;i++) {
        int j = lower_bound(perm, perm + n, perm[i]) - perm - 1;
        res[perm[i].second] = j >= 0 ? pref[j] : 0ll;
    }

    for(int i = 0;i < n;i++) {
        cout << res[i] + c[i] << " \n"[i + 1 == n];
    }

    return 0;
}