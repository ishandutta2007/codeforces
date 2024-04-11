#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n;
    scanf("%d", &n);

    vec< int > x(n);

    for(int i = 0;i < n;i++) scanf("%d", &x[i]);

    sort(ALL(x));

    vec< ll > sum(n);
    for(int i = 0;i < n;i++) {
        sum[i] = (i?sum[i - 1] : 0) + x[i];
    }

    pair< ll , int > res = {inf64, -1};

    for(int i = 0;i < n;i++) {
        ll tmp_sum = 1ll * (i + 1) * x[i] - sum[i] +
            sum[n] - sum[i] - 1ll * (n - 1 - i) * x[i];
        res = min(res, {tmp_sum, x[i]});
    }

    cout << res.second << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}