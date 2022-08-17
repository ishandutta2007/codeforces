#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1011, inf = 1000111222;

ll sq(ll i, ll j) {
    return i * i + j * j;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    if (n <= m) {
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (sq(i, j) % m == 0) {
                    ++ans;
                }
            }
        }
        cout << ans << endl;
        return 0;
    }
    ll ANS = 0;
    ll cntf = n / m;
    cntf *= cntf;
    ll anssq = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (sq(i, j) % m == 0) {
                ++anssq;
            }
        }
    }
    ANS = cntf * anssq;
    anssq = 0;
    for (int i = 1; i <= n % m; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (sq(i, j) % m == 0) {
                ++anssq;
            }
        }
    }
    ANS += anssq * 2 * (n / m);
    for (int i = 1; i <= n % m; ++i) {
        for (int j = 1; j < n % m; ++j) {
            if (sq(i, j) % m == 0) {
                ++ANS;
            }
        }
    }
    cout << ANS << endl;
    return 0;
}