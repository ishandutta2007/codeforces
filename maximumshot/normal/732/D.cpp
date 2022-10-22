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

int const N = 100005;

int n, m;
int d[N];
int a[N];
int mn[N];
int mx[N];
int used[N];

bool check(int x) {
    for(int i = 1;i <= m;i++) mx[i] = 0;
    for(int i = 1;i <= n;i++) used[i] = 0;
    for(int i = 1;i <= x;i++) {
        if(d[i] > 0) {
            mx[d[i]] = max(mx[d[i]], i);
        }
    }
    for(int i = 1;i <= m;i++) {
        used[mx[i]] = i;
    }
    for(int pr = 0, i = 1;i <= x;i++) {
        if(!used[i]) pr++;
        else {
            if(a[used[i]] > pr) {
                return 0;
            }else {
                pr -= a[used[i]];
            }
        }
    }
    return 1;
}

bool solve() {

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= m;i++) {
        mn[i] = n + 1;
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &d[i]);
        if(d[i] > 0) {
            mn[d[i]] = min(mn[d[i]], i);
        }
    }

    for(int i = 1;i <= m;i++) {
        scanf("%d", &a[i]);
    }

    int bl = 1;
    for(int i = 1;i <= m;i++) {
        if(mn[i] == n + 1) {
            printf("-1\n");
            return true;
        }
        bl = max(bl, mn[i]);
    }
    int br = n;
    int bm;

    while(br - bl > 1) {
        bm = (bl + br) >> 1;
        if(check(bm)) br = bm;
        else bl = bm + 1;
    }

    if(bl < br && check(bl)) {
        printf("%d\n", bl);
    }else if(check(br)) {
        printf("%d\n", br);
    }else {
        printf("-1\n");
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