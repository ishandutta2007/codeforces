#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 100005;
int const X = 1024;

int n, k, x;
int cnt[X];
int cnt2[X];

int main() {

    scanf("%d %d %d", &n, &k, &x);

    for(int v, i = 0;i < n;i++) {
        scanf("%d", &v);
        cnt[v]++;
    }

    for(int iter = 0;iter < k;iter++) {
        int tot = 0;
        for(int v = 0;v < X;v++) {
            cnt2[v] = 0;
        }
        for(int t, v = 0;v < X;v++) {
            if(tot % 2) {
                t = cnt[v] / 2;
            }else {
                t = (cnt[v] + 1) / 2;
            }
            tot += cnt[v];
            cnt2[v] += cnt[v] - t;
            cnt2[v ^ x] += t;
        }
        for(int v = 0;v < X;v++) {
            cnt[v] = cnt2[v];
        }
    }

    int mx = 0;
    int mn = X - 1;

    for(int v = 0;v < X;v++) {
        if(cnt[v]) {
            mn = min(mn, v);
            mx = max(mx, v);
        }
    }

    printf("%d %d\n", mx, mn);

    return 0;
}