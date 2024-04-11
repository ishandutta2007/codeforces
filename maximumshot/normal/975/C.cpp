#include <bits/stdc++.h>

using namespace std;

#define ALL(x) begin(x), end(x)
#define vec vector

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = ll(1e18);

const int N = 2e5 + 5;

int n, q;
int a[N];
ll pref[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &q);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        pref[i] = pref[i - 1] + a[i];
    }

    int pos = 1;
    int cur = 0;

    for(int it = 0;it < q;it++) {
        ll k;
        scanf("%lld", &k);
        if(cur + k < a[pos]) {
            cur += k;
            printf("%d\n", n - pos + 1);
            continue;
        }
        k -= (a[pos] - cur);
        pos++;
        if(pos > n) {
            pos = 1;
            cur = 0;
            printf("%d\n", n);
            continue;
        }
        if(pref[n] - pref[pos - 1] <= k) {
            pos = 1;
            cur = 0;
            printf("%d\n", n);
            continue;
        }
        int bl = pos - 1;
        int br = n;
        int bm;
        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            if(pref[bm] - pref[pos - 1] <= k) {
                bl = bm;
            }else {
                br = bm;
            }
        }
        int npos = br;
        k -= (pref[npos - 1] - pref[pos - 1]);
        pos = npos;
        cur = k;
        printf("%d\n", n - pos + 1);
    }

    return 0;
}