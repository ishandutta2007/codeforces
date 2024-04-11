#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const MAX_VALUE = 10 * 1000 * 1000 + 5;
int const N = 1000005;

int n, k;
int a[N];
int cnt[MAX_VALUE];

bool check(int mn) {
    for(int i = 0;i < MAX_VALUE;i++) cnt[i] = 0;
    for(int i = 1;i <= n;i++) cnt[a[i]]++;
    for(int x, y, i = MAX_VALUE - 1;i / 2 >= mn && i > 1;i--) {
        x = i / 2;
        y = i - x;
        cnt[x] += cnt[i];
        cnt[y] += cnt[i];
        cnt[i] = 0;
    }
    ll tot = 0;
    for(int i = mn;i < MAX_VALUE;i++) {
        tot += cnt[i];
    }
    return tot >= k;
}

int main() {

    scanf("%d %d", &n, &k);

    ll tot = 0;

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        tot += a[i];
    }

    if(tot < k) {
        puts("-1");
        return 0;
    }

    int bl = 1;
    int br = 10 * 1000 * 1000;
    int bm;

    while(br - bl > 1) {
        bm = (bl + br) >> 1;
        if(check(bm)) bl = bm;
        else br = bm - 1;
    }
    if(bl < br && check(br)) {
        printf("%d\n", br);
    }else {
        printf("%d\n", bl);
    }

    return 0;
}