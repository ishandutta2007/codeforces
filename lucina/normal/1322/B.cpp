#include<bits/stdc++.h>
using namespace std;
int const nax = 4e5 + 10;

struct num {
    int val, id;
    num () : val () , id () {}
    num (int val, int id) : val (val), id (id) {}
    bool operator < (const num & x) const {
        return val < x.val;
    }
}b[nax];

int n, a[nax], pre[nax];
inline int get_one (int l, int r) {
    return pre[r] - pre[l - 1];
}
inline int get_zero (int l, int r) {
    return r - l + 1 - pre[r] + pre[l - 1];
}

int main () {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; ++ i)
         scanf("%d", a + i);

    const int iter = __lg((int)1e7);

    for (int i = 1 ; i <= n ; ++ i)
        b[i] = num(0, i);
    int ans = 0;
    for (int j = 0 ; j <= iter + 1; ++ j) {
        sort(b + 1 , b + 1 + n);
        for (int i = 1 ; i <= n ; ++ i)
            pre[i] = pre[i - 1] + ((a[b[i].id] & (1 << j)) ? 1 : 0);

        int one = 0;

        for (int i = 1 ; i < n ; ++ i) {
            int l = i + 1, r = n , ans = -1;

            while ( l <= r) {
                int mid = l + r >> 1;
                if (b[i].val + b[mid].val >= (1 << j)) {
                    ans = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }

            bool now = (a[b[i].id] & (1 << j)) ? true : false;
            if (ans == -1)
                (one += now ? get_zero(i + 1, n) : get_one(i + 1 ,  n)) &= 1;
            else {
                if (ans - 1 >= i + 1)
                    (one += now ? get_zero(i + 1 , ans - 1) : get_one(i + 1 , ans - 1)) &= 1;

                (one += now ? get_one(ans, n) : get_zero(ans, n)) &= 1;
            }
        }

        if (one) ans ^= (1 << j);

        for (int v = 1 ; v <= n ; ++ v)
            b[v].val ^= (a[b[v].id] & (1 << j));

    }
    printf("%d\n", ans);
}
/*
    Good Luck
        -Lucina
*/