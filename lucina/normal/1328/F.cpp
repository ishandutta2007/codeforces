#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int a[nax];
int n, k;

map <int, int> ct;

int main () {
    scanf("%d %d", &n, &k);

    for (int i = 1 ; i <= n;  ++ i) {
        scanf("%d", a + i);
        ++ ct[a[i]];
    }

    for (auto & it : ct) {
        if (it.second >= k) {
            return !printf("0");
        }

    }


    long long ans = LLONG_MAX;
    long long pre = 0, suf = accumulate(a + 1 , a + 1 + n, 0LL);

    int ct_pre = 0, ct_suf = n;

    for (auto it = ct.begin() ; it  != ct.end() ; ++ it ) {

        ct_suf -= it -> second;
        suf -= 1LL * (it -> first) * (it -> second);

        long long use_pre = 1LL * ((it -> first) - 1) * ct_pre - pre;
        long long use_suf = suf - (1LL * (it ->first + 1) * ct_suf);

        int need = k - (it -> second);

        if (ct_pre >= need) {
            ans = min(ans, use_pre + need);
        }

        if (ct_suf >= need) {
            ans = min(ans, use_suf + need);
        }

        ans = min(ans, use_pre + use_suf + need);

        ct_pre += it -> second;
        pre += 1LL * (it -> first) * (it -> second);
    }

    printf("%lld\n", ans);
}