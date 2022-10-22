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

int n;
int S;
int a[N];
int perm[N];

bool check(int k) {
    sort(perm + 1, perm + n + 1, [&](int i, int j) {
        return a[i] + 1ll * i * k < a[j] + 1ll * j * k;
    });
    int cur = 0;
    int res = 0;
    for(int i = 1;i <= n;i++) {
        if(cur + a[perm[i]] + 1ll * perm[i] * k <= S) {
            cur += a[perm[i]] + 1ll * perm[i] * k;
            res++;
        }
    }
    return res >= k;
}

int get_cost(int k) {
    sort(perm + 1, perm + n + 1, [&](int i, int j) {
        return a[i] + 1ll * i * k < a[j] + 1ll * j * k;
    });
    int cur = 0;
    int res = 0;
    for(int i = 1;i <= n && res < k;i++) {
        if(cur + a[perm[i]] + 1ll * perm[i] * k <= S) {
            cur += a[perm[i]] + 1ll * perm[i] * k;
            res++;
        }
    }
    return cur;
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &S);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        perm[i] = i;
    }

    int bl = 1;
    int br = n;
    int bm;

    while(br - bl > 1) {
        bm = (bl + br) / 2;
        if(check(bm)) {
            bl = bm;
        }else {
            br = bm - 1;
        }
    }

    if(bl < br && check(br)) {
        printf("%d %d\n", br, get_cost(br));
    }else if(check(bl)) {
        printf("%d %d\n", bl, get_cost(bl));
    }else {
        printf("0 0\n");
    }

    return 0;
}