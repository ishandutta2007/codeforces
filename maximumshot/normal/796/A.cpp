#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n, m, k;

    cin >> n >> m >> k;

    int res = inf;

    for(int x, i = 1;i <= n;i++) {
        cin >> x;
        if(x == 0) continue;
        if(k >= x) {
            res = min(res, abs(i - m));
        }
    }

    cout << res*10 << "\n";

    return 0;
}