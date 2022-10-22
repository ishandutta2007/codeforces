#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;

    int sum = 0;

    for(int x, i = 0;i < n;i++) {
        cin >> x;
        sum += x;
    }

    int res = inf;

    int m;

    cin >> m;

    for(int l, r, i = 0;i < m;i++) {
        cin >> l >> r;
        if(sum > r) continue;
        res = min(res, max(l, sum));
    }

    if(res == inf) {
        cout << "-1\n";
    }else {
        cout << res << "\n";
    }

    return 0;
}