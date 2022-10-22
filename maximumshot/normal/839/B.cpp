#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int n, k;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    int c4 = n;
    int c2 = 2 * n;

    vec< int > cnt(4);

    for(int x, i = 0;i < k;i++) {
        scanf("%d", &x);
        while(x >= 4 && c4 > 0) {
            x -= 4;
            c4--;
        }
        while(x >= 2 && c2 > 0) {
            x -= 2;
            c2--;
        }
        if(x > 4) {
            puts("NO");
            return 0;
        }
        if(x == 0) continue;
        cnt[x]++; // {1, 2, 3}
    }

    int t = min(cnt[2], c2);

    cnt[2] -= t;
    c2 -= t;

    if(c2 > 0) {
        while(cnt[3] > 0 && c4 > 0) {
            c4--;
            cnt[3]--;
        }
        while(cnt[3] > 0 && c2 > 0) {
            cnt[3]--;
            cnt[1]++;
            c2--;
        }
        if(cnt[3] > 0) {
            puts("NO");
            return 0;
        }
        if(cnt[1] <= c2 + 2 * c4) {
            puts("YES");
        }else {
            puts("NO");
        }
    }else {
        while(cnt[3] > 0 && c4 > 0) {
            cnt[3]--;
            c4--;
        }
        if(cnt[3] > 0) {
            puts("NO");
            return 0;
        }
        while(cnt[1] > 0 && cnt[2] > 0 && c4 > 0) {
            cnt[1]--;
            cnt[2]--;
            c4--;
        }
        if(cnt[1] > 0 && cnt[2] > 0) {
            puts("NO");
            return 0;
        }
        if(cnt[1] > 0) {
            if(cnt[1] <= 2 * c4) {
                puts("YES");
            }else {
                puts("NO");
            }
        }else if(cnt[2] > 0) {
            int c1 = 0;
            while(cnt[2] > 0 && c4 > 0) {
                cnt[2]--;
                c4--;
                c1++;
            }
            if(2 * cnt[2] <= c1) {
                puts("YES");
            }else {
                puts("NO");
            }
        }else {
            puts("YES");
        }
    }

    return 0;
}