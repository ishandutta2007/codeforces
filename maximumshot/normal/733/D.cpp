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

    vec< vec< int > > a(n, vec< int >(3));

    map< pii, pii > mx;

    int ans_k = -1;
    int ans_1 = -1, ans_2 = -1;
    int tot = -1;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < 3;j++)
            scanf("%d", &a[i][j]);
        for(int mask = 0;mask < 8;mask++) {
            if(__builtin_popcount(mask) != 2) continue;
            int p1 = -1, p2 = -1, p3 = -1;
            for(int j = 0;j < 3;j++) {
                if((1 << j) & mask) {
                    if(p1 == -1) p1 = a[i][j];
                    else p2 = a[i][j];
                }else {
                    p3 = a[i][j];
                }
            }
            if(p1 > p2) swap(p1, p2);
            if(mx.count({p1, p2})) {
                pii cur = mx[{p1, p2}];
                int A, B, C, cur_res;
                A = p1;
                B = p2;
                C = p3 + cur.first;
                int id = cur.second;
                cur_res = min({A, B, C});
                if(cur_res > tot) {
                    tot = cur_res;
                    ans_1 = id;
                    ans_2 = i;
                    ans_k = 2;
                }
            }
        }
        for(int mask = 0;mask < 8;mask++) {
            if (__builtin_popcount(mask) != 2) continue;
            int p1 = -1, p2 = -1, p3 = -1;
            for(int j = 0;j < 3;j++) {
                if((1 << j) & mask) {
                    if(p1 == -1) p1 = a[i][j];
                    else p2 = a[i][j];
                }else {
                    p3 = a[i][j];
                }
            }
            if(p1 > p2) swap(p1, p2);
            mx[{p1, p2}] = max(mx[{p1, p2}], {p3, i});
        }
    }

    for(int i = 0;i < n;i++) {
        int cur_res = min({a[i][0], a[i][1], a[i][2]});
        if(cur_res > tot) {
            tot = cur_res;
            ans_k = 1;
            ans_1 = i;
        }
    }

    printf("%d\n", ans_k);

    if(ans_k == 1) {
        printf("%d\n", ans_1 + 1);
    }else {
        printf("%d %d\n", ans_1 + 1, ans_2 + 1);
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