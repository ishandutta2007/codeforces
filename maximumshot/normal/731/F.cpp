#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n;
    scanf("%d", &n);

    vec< int > cnt(200200);
    vec< ll > pr_cnt(200200);

    for(int x, i = 0;i < n;i++) {
        scanf("%d", &x);
        cnt[x]++;
    }

    for(int i = 1;i < 200200;i++) {
        pr_cnt[i] = pr_cnt[i - 1] + cnt[i];
    }

    ll res = 0;

    for(int i = 1;i < 200200;i++) {
        if(!cnt[i]) continue;
        ll tot = 0;
        for(int ql, qr, j = i;j < 200200;j += i) {
            tot += 1ll * cnt[j] * j;
            ql = j + 1;
            qr = min(200200 - 1, j + i - 1);
            if(ql <= qr) {
                tot += 1ll * (pr_cnt[qr] - (ql?pr_cnt[ql - 1] : 0)) * j;
            }
        }
        res = max(res, tot);
    }

    cout << res << "\n";

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}