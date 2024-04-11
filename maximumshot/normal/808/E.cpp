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

int const N = 1e5 + 5;
int const M = 3e5 + 5;

int n, m;
int w[N];
int c[N];

vec< int > perm;
int mn[N];
int mn2[N];
int mx[N];
ll pc[N];
ll pw[N];
int sz;
ll value[M];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        scanf("%d %d", &w[i], &c[i]);
        if(w[i] <= 2) {
            perm.push_back(i);
        }
    }

    sort(ALL(perm), [&](int i, int j) {
        return 2 * c[i] / w[i] > 2 * c[j] / w[j];
    });

    sz = (int)perm.size();

    for(int i = sz - 1;i >= 0;i--) {
        if(i == sz - 1) {
            mx[i] = -inf;
        }else mx[i] = mx[i + 1];
        if(w[perm[i]] == 1)
            mx[i] = max(mx[i], c[perm[i]]);
    }

    for(int i = 0;i < sz;i++) {
        pc[i] = (i > 0 ? pc[i - 1] : 0ll) + c[perm[i]];
        pw[i] = (i > 0 ? pw[i - 1] : 0ll) + w[perm[i]];
        if(i == 0) mn[i] = mn2[i] = inf;
        else mn[i] = mn[i - 1], mn2[i] = mn2[i - 1];
        if(w[perm[i]] == 1) {
            mn[i] = min(mn[i], c[perm[i]]);
        }else {
            mn2[i] = min(mn2[i], c[perm[i]]);
        }
    }

    for(int j = 0;j < M;j++) {
        int idx = lower_bound(pw, pw + sz, j) - pw;
        int ql = max(0, idx - 3);
        int qr = min(sz - 1, idx + 3);
        for(int i = ql;i <= qr;i++) {
            if(pw[i] <= j) {
                value[j] = max(value[j], pc[i]);
            }else if(pw[i] == j + 1) {
                value[j] = max(value[j], pc[i] - mn[i]);
                value[j] = max(value[j], pc[i] - mn2[i] + (i + 1 < sz ? mx[i] : -inf));
            }
        }
    }

    ll res = 0;

    for(int j = 0;j <= m;j++) {
        res = max(res, value[j]);
        if(j > 0) {
            value[j] = max(value[j], value[j - 1]);
        }
    }

    vec< ll > arr;

    for(int i = 1;i <= n;i++) {
        if(w[i] == 3) {
            arr.push_back(c[i]);
        }
    }

    sort(ALL(arr));
    reverse(ALL(arr));

    for(int i = 0;i < (int)arr.size();i++) {
        if(i > 0) arr[i] += arr[i - 1];
        if(3 * (i + 1) > m) break;
        res = max(res, value[m - 3 * (i + 1)] + arr[i]);
    }

    cout << res << "\n";

    return 0;
}