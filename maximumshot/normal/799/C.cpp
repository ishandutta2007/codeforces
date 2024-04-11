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

vec< pii > a[2];
int n, c, d;

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &c, &d);

    for(int i = 1;i <= n;i++) {
        int b, p;
        char type;
        scanf("%d %d %c", &b, &p, &type);
        if(type == 'C') {
            a[0].push_back({p, b});
        }else {
            a[1].push_back({p, b});
        }
    }

    sort(ALL(a[0]));
    sort(ALL(a[1]));

    int res = 0;

    for(int iter = 0;iter < 2;iter++) {
        if(a[iter].empty()) continue;
        int have = iter == 0 ? c : d;
        int sz = (int)a[iter].size();
        vec< int > pref(sz, 0);
        for(int i = 0;i < sz;i++) {
            pref[i] = a[iter][i].second;
            if(i > 0) {
                pref[i] = max(pref[i], pref[i - 1]);
            }
        }
        for(int j = 0, i = 1;i < sz;i++) {
            int bl, br, bm;
            bl = 0;
            br = i - 1;
            while(br - bl > 1) {
                bm = (bl + br) / 2;
                if(a[iter][bm].first + a[iter][i].first <= have) {
                    bl = bm;
                }else {
                    br = bm - 1;
                }
            }
            if(bl < br && a[iter][br].first + a[iter][i].first <= have) {
                j = br;
            }else if(a[iter][bl].first + a[iter][i].first <= have) {
                j = bl;
            }else {
                continue;
            }
            res = max(res, pref[j] + a[iter][i].second);
        }
    }

    if(!a[0].empty() && !a[1].empty()) {
        int r1 = -inf;
        int r2 = -inf;
        for(pii x : a[0]) {
            if(x.first <= c) {
                r1 = max(r1, x.second);
            }
        }
        for(pii x : a[1]) {
            if(x.first <= d) {
                r2 = max(r2, x.second);
            }
        }
        if(r1 != -inf && r2 != -inf) {
            res = max(res, r1 + r2);
        }
    }

    printf("%d\n", res);

    return 0;
}