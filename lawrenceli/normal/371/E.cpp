#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 300100;

int n, lt, k;
pii x[MAXN];
ll cur, ans, pre[MAXN];

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x[i].fi;
        x[i].se = i;
    }
    cin >> k;

    sort(x, x + n);
    for (int i=0; i<n; i++) pre[i+1] = pre[i] + x[i].fi;

    for (int i=0; i<k; i++) cur += x[i].fi * (k+1-2*(k-i));
    ans = cur, lt = 0;

    for (int i=1; i<=n-k; i++) {
        cur += ll(k-1) * (x[i+k-1].fi + x[i-1].fi) - 2 * (pre[i+k-1] - pre[i]);
        if (cur < ans)
            ans = cur, lt = i;
    }

    for (int i=lt; i<lt+k; i++)
        cout << x[i].se+1 << ' ';

    return 0;
}