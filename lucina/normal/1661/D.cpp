#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, k;
int64_t a[nax];
int64_t sub[nax];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%lld", a + i);
    reverse(a + 1, a + 1 + n);
    int64_t carry = 0;
    int64_t cnt = 0;
    int64_t ans = 0;
    int64_t mx_need = 0;
    for (int i = 1 ; i <= n; ++ i) {
        int64_t cur = a[i];
        cur -= carry;
        if (i >= n - k + 1) {
            if (cur > 0) {
                int now = n - i + 1;
                mx_need = max(mx_need, (cur + now - 1) / now);
            }
        } else if (cur > 0) {
            int64_t need = (cur + k - 1) / k;
            carry += need * k;
            cnt += need;
            ans += need;
            sub[i + k - 1] += need;
        }

        carry -= cnt;
        cnt -= sub[i];

    }
    printf("%lld\n", ans + mx_need);
}