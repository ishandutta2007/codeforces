#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int at_most(ll s, ll e) {
    int sz = 0;
    while (2 * s <= e) {
        sz++;
        s *= 2;
    }
    return sz;
}
int at_least(ll s, ll e) {
    int sz = 0;
    while (2 * s + 1 <= e) {
        sz++;
        s = 2 * s + 1;
    }
    return sz;
}
const int maxN = 1e5 + 10;
ll s[maxN], e[maxN];
int W(ll s, ll e);
int L(ll s, ll e);
int L(ll s, ll e) {
    if (s >= e / 2 + 1) return 1;
    return W(s, e / 2);
}
int W(ll s, ll e) {
    if (e % 2 == 1) {
        return !(s % 2);
    }
    if (s > e / 2) {
        return (s % 2);
    }
    if (2 * s > e / 2) return 1;
    return W(s, e / 4);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
    }
    reverse(s, s + n);
    reverse(e, e + n);
    int can_win = 1;
    int can_lose = 0;
    for (int i = 0; i < n; i++) {
        int cw = W(s[i], e[i]);
        int cl = L(s[i], e[i]);
        if (i == 0) {
            can_win = cw;
            can_lose = cl;
        }
        else {
            int ncw = 0, ncl = 0;
            if (can_win) {
                if (cl) ncw = 1;
                else ncw = 0;
            }
            else {
                if (cw) ncw = 1;
                else ncw = 0;
            }
            if (can_lose) {
                if (cl) ncl = 1;
                else ncl = 0;
            }
            else {
                if (cw) ncl = 1;
                else ncl = 0;
            }
            can_win = ncw;
            can_lose = ncl;
        }
    }
    cout << can_win << " " << can_lose;
    return 0;
}