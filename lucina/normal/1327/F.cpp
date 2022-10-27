#include<bits/stdc++.h>
using namespace std;
int const nax = 5e5 + 10, mod = 998244353;
int n, m, k;
int a[nax];

int l[nax], r[nax], x[nax];
int one[nax], lst[nax];

int add (int a, int b) {
    return ((a += b) >= mod) ? a - mod : a;
}

int mul (int a, int b) {
    //fprintf(stderr, "huh %d\n", b);
    return 1LL * a * b % mod;
}

int sub (int a, int b) {
    return ((a -= b) < 0) ? a + mod : a;
}


int  pre[nax];


int main () {
    scanf("%d %d %d", &n, &k, &m);

    for (int i = 1 ; i <= m ; ++ i)
        scanf("%d %d %d", l + i , r + i, x + i);


    int ans = 1;

    for (int b = 0 ; b < k ; ++ b) {

        fill(one + 1, one + 1 + n, 0);
        fill(lst + 1, lst + 1 + n, 0);

        for (int i = 1 ; i <= m ; ++ i) {
            if (x[i] >> b & 1) {
                one[l[i]] ++;
                one[r[i] + 1] --;
            } else {
                lst[r[i]] = max(lst[r[i]], l[i]);
            }
        }

        int cur_lst = 0;
        pre[0] = 1;
        for (int i = 1 ; i <= n ; ++ i) {
            one[i] += one[i - 1];
            int res ;

            if (!one[i]) {
                if (cur_lst > 0)
                    res = sub(pre[i - 1], pre[cur_lst - 1]);
                else res = pre[i - 1];
            } else res = 0;

            pre[i] = add(pre[i - 1], res);
            cur_lst = max(cur_lst, lst[i]);
        }

        ans = mul(ans, sub(pre[n], cur_lst > 0 ? pre[cur_lst - 1]: 0));
    }

    printf("%d\n", ans);
}