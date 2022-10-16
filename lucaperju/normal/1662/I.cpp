/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 200000;
const int M_MAX = 200000;

const int INF = INT_MAX / 2;

int n, m;

int p[N_MAX + 2];
int x[M_MAX + 2];

set <int> xs;

set <int> pos;
map <int, ll> add;
map <int, ll> sub;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> x[i];
    }

    for (int i = 1; i <= m; i++) {
        xs.insert(x[i]);
    }
    xs.insert(-INF);
    xs.insert(+INF);
    for (int i = 1; i <= n; i++) {
        int X = (i - 1) * 100;
        set <int> :: iterator itr = xs.lower_bound(X);
        if (*itr == X) {
            continue;
        }
        set <int> :: iterator itl = prev(itr);
        int R = *itr, L = *itl;
        int dmin = min(X - L, R - X);
        add[X - dmin] += p[i];
        sub[X + dmin] += p[i];
        pos.insert(X - dmin);
        pos.insert(X + dmin);
    }

    ll answer = 0;
    ll curr = 0;
    for (int u : pos) {
        answer = max(answer, curr);
        curr -= sub[u];
        answer = max(answer, curr);
        curr += add[u];
    }
    cout << answer << "\n";

    return 0;
}