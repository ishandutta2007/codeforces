#include<bits/stdc++.h>
using namespace std;
int const nax = 4e5 + 10;
using ll = long long ;
int n;
ll x;
ll w[nax];
ll s[nax];
ll f[nax];

ll get_sum(ll x) {
    return x * (x + 1) / 2;
}

int main () {

    scanf("%d %lld", &n, &x);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%lld", w + i);
        s[i] = s[i - 1] + w[i];
        f[i] = f[i - 1] + get_sum(w[i]);
    }

    for (int i = n + 1 ; i <= n + n ; ++ i) {
        w[i] = w[i - n];
        s[i] = s[i - 1] + w[i];
        f[i] = f[i - 1] + get_sum(w[i]);
    }


    ll ans = 0;

    for (int i = 1 ; i <= n + n ; ++ i) {
        ll cur = s[i];

        if (cur - x + 1 <= 0) continue;

        int l = 1, r = i, ans1 = -1;

        ll tar = cur - x + 1;

        while (l <= r) {
            int mid = l + r >> 1;

            if (s[mid] >= tar) {
                ans1 = mid;
                r = mid - 1;
            } else l = mid + 1;
        }



        ll pos_in_block = tar - s[ans1 - 1];



        ll res = f[i] - f[ans1 - 1];
        res -= get_sum(pos_in_block - 1);

        ans = max(ans, res);
    }

    printf("%lld\n", ans);

}
/*
    Long time no see...
        CF round
*/