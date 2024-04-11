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

int main() {

    int n, k, s, t;

    scanf("%d %d %d %d", &n, &k, &s, &t);

    vec< int > c(n), v(n);

    for(int i = 0;i < n;i++) {
        scanf("%d %d", &c[i], &v[i]);
    }

    vec< int > g(k);

    for(int i = 0;i < k;i++) scanf("%d", &g[i]);

    sort(ALL(g));

    vec< int > L;

    L.push_back(g[0]);

    for(int i = 1;i < k;i++) {
        L.push_back(g[i] - g[i - 1]);
    }

    L.push_back(s - g[k - 1]);

    sort(ALL(L));

    vec< ll > pr((int)L.size());

    pr[0] = L[0];
    for(int i = 1;i < (int)L.size();i++) {
        pr[i] = pr[i - 1] + L[i];
    }

    int res = -1;

    for(int i = 0;i < n;i++) {
        if(L.back() > v[i]) continue;
        int pos = lower_bound(ALL(L), (v[i] + 1) / 2) - L.begin();
        // pos ..
        ll sum, cnt;
        if(pos == (int)L.size()) sum = cnt = 0;
        else {
            sum = pr.back() - (pos ? pr[pos - 1] : 0);
            cnt = (int)L.size() - pos;
        }
        ll total = 1ll * v[i] * cnt - sum;
        if(pos > 0) total += pr[pos - 1];
        ll y = s - total;
        if(s + y <= t) {
            if(res == -1 || res > c[i])
                res = c[i];
        }
    }

    printf("%d\n", res);

    return 0;
}