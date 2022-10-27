#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
using ll = long long ;
int n;
ll a[nax];
map<ll, int> ss;

int main () {
    scanf("%d", &n);

    for (int i = 1 ; i <= n; ++ i) {
        scanf("%lld", a + i);
        a[i] += a[i - 1];
    }

    ss[0] = 0;
    int l = 0;

    ll ans = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        if (!ss.count(a[i])) {
            ss[a[i]] = i;
        } else {
            int h = ss[a[i]];
            for (int j = l ; j <= h ; ++ j) {
                ss.erase(a[j]);
            }
            l = h + 1;
            ss[a[i]] = i;
        }

        ans += i - l;
    }

    printf("%lld\n", ans);
}
/*
    Good Luck
        -Lucina
*/