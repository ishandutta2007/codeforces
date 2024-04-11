#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
array <int, 2> a[nax];
int n;
int b[nax];
int side(int x) {
    return x <= n ? 0 : 1;
}
bool up[nax + nax];

int main() {
    #define NO return !printf("-1");
/**
    simple test case
    when LIS wrong
    5 1 2 3 6 7 4
*/
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d %d", &a[i][0], &a[i][1]);
        if (side(a[i][0]) == side(a[i][1])) NO;
        up[a[i][0]] = true;
    }
    sort(a + 1, a + 1 + n, [](const array <int, 2> &a, const array <int, 2> &b)->bool {
            return min(a[0], a[1]) > min(b[0], b[1]);
    });
    int ans = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        b[i] = max(a[i][0], a[i][1]) - n;
    }

    for (int i = 1, lst = 0; i <= n ; ) {
        int j = i;
        int mx = b[i];
        int c[2]{}, d[2]{};
        c[0] += up[mx + n], c[1] += !up[mx + n];
        int ls = 0;
        while (j - i + 1 != mx - lst) {
            ++ j;
            int x = b[j];
            if (x > mx) {
                c[0] += up[x + n], c[1] += !up[x + n];
                mx = x;
            } else {
                if (x < ls) NO;
                d[0] += up[x + n], d[1] += !up[x + n];
                ls = x;
            }
        }
        ans += min(c[0] + d[1], c[1] + d[0]);
        i = j + 1;
        lst = mx;
    }
    printf("%d\n", ans);
        /**

        */
}