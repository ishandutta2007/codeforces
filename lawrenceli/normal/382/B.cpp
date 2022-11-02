#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXW = 1005;

ll a, b, w, x, c, dp[MAXW][2];

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> a >> b >> w >> x >> c;

    memset(dp, -1, sizeof(dp));

    ll t = 0, d = 0, p1, p2;
    while (1) {
        if (c <= a) {
            cout << t << '\n';
            return 0;
        }

        if (dp[b][0] != -1) {
            p1 = t - dp[b][0], p2 = d - dp[b][1];
            break;
        }

        dp[b][0] = t, dp[b][1] = d;

        if (b >= x) b -= x;
        else {
            d++;
            a--;
            b -= x - w;
        }

        t++; c--;
    }

    ll n = (c - a) / (p1 - p2) - 1;
    if (n > 0) {
        c -= p1 * n;
        a -= p2 * n;
        t += p1 * n;
    }

    while (1) {
        if (c <= a) {
            cout << t << '\n';
            return 0;
        }

        if (b >= x) b -= x;
        else {
            a--;
            b -= x - w;
        }

        c--; t++;
    }

    return 0;
}