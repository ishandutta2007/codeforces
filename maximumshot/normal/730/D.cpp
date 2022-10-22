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

int const N = 200005;
int const max_size = 100000;

ll way[max_size];
int cur_sz = 0;

int n;
ll r;
int len[N];
int Time[N];
ll sum_len[N];

bool solve() {

    cur_sz = 0;

    scanf("%d %I64d", &n, &r);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &len[i]);
        sum_len[i] = sum_len[i - 1] + len[i];
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &Time[i]);
        if(len[i] > Time[i]) {
            printf("-1\n");
            return true;
        }
    }

    ll last = -r, last_time = -r;
    ll K = 0;

    for(int i = 1;i <= n;i++) {
        ll st = max(last + r, sum_len[i - 1]);
        if(st >= sum_len[i] || (st - sum_len[i - 1]) + 2ll * (sum_len[i] - st) <= Time[i]) continue;
        ll pref = st - sum_len[i - 1];
        ll x = Time[i] - len[i];
        ll st_time = (last + r >= sum_len[i - 1] ? last_time + r : last_time + r + (sum_len[i - 1] - last - r) * 2);
        K += (len[i] - pref - x + r - 1) / r;
        for(ll x0 = st + x;x0 < sum_len[i] && cur_sz < max_size;x0 += r) {
            way[cur_sz++] = st_time + 2 * x + (x0 - st - x);
        }
        last = st + x + ((len[i] - pref - x + r - 1) / r - 1) * r;
        last_time = st_time + 2 * x + ((len[i] - pref - x + r - 1) / r - 1) * r;
    }

    printf("%I64d\n", K);

    if(K <= max_size) {
        for(int i = 0;i < K;i++) {
            printf("%I64d ", way[i]);
        }
        printf("\n");
    }

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