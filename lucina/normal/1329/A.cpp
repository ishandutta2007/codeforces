#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
using ll = long long ;
int n, m;
int l[nax];
ll a[nax];

int main () {
    scanf("%d %d", &n, &m);

    ll cur = 0;

    for (int i = 1 ; i <= m ; ++ i) {
        scanf("%d", l + i);
        a[i] = cur + 1;
        cur += l[i];

        if (l[i] + i - 1 > n) return !printf("-1");
    }

    if (cur < n) return !printf("-1");

    ll sub = 0;
    ll need_to_minus = cur - n;

    for (int i = 2 ; i <= m ; ++ i) {
        int huh = min(need_to_minus, (ll)(l[i - 1] - 1));
        sub += huh;
        need_to_minus -= huh;
        a[i] -= sub;
    }

    for (int i = 1 ; i <= m ; ++ i) {
        printf("%lld ", a[i]);
    }
}

/*
    Good Luck
        -Lucina
*/