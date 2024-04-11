#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
using ll = long long ;
bool can_win (ll s, ll e) {
    if (e % 2) return !(s % 2);

    if (s * 2 > e) {
        return ((e - s) % 2);
    }

    if (s > (e >> 2)) return true;
    return can_win(s, e >> 2);
}

bool can_lose (ll s, ll e) {
    if (s + 1 > e || s * 2 > e) return true;
    return can_win(s, e >> 1);
}

int n;
bool win[nax];
bool lose[nax];
bool f[nax];
bool g[nax];

int main () {
    scanf("%d", &n);

    ll s, e;

    f[0] = true;

    for (int x = 1 ; x <= n ; ++ x) {
        scanf("%lld %lld", &s, &e);
        win[x] = can_win(s, e);
        lose[x] = can_lose(s, e);
       // fprintf(stderr, "win lose %s %s\n", win[x] ? "true" : "false", lose[x] ? "true" : "false");
        if (f[x - 1] && lose[x]) f[x] = true;
        if (g[x - 1] && ((win[x] && !lose[x]) || (!win[x] && !lose[x]))) f[x] = true;
        if (f[x - 1] && win[x]) g[x] = true;
        if (g[x - 1] && ((lose[x] && !win[x]) || (!win[x] && !lose[x]))) g[x] = true;
    }

    printf("%d %d\n", g[n], f[n]);


}

/**
    remark some dp
    f[x] is true if we can be first player after this turn
    g[x] is true fi we can be second player after this turn
    f[0] = 1
    g[0] = 0

    f[x] means he can choose to lose
    if (f[x - 1] && lose[x]) f[x] = true
    if (g[x - 1] && ((win[x] && !lose[x]) || (!win[x] && !lose[x])) f[x] = true;
    g[x] means he can choose to win
    if (f[x - 1] && win[x]) g[x] = true
    if (g[x - 1] && ((lose[x] && !win[x]) || (!win[x] && !lose[x])) g[x] = true;
*/

/*
    Leon is the best girl in A17.
*/