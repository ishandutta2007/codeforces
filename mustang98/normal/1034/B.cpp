#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 30, inf = 1000111222;

bool f[max_n][max_n];

int ans = 0;
int n, m;

void rec(int cnt, int i, int j) {
    int a;
    ans = max(ans, cnt);
    if (ans == n * m - (n * m) % 2) {
        return;
    }
    for (int i1 = i; i1 < n; ++i1) {
        for (int j1 = 0; j1 < m; ++j1) {
            for (int i2 = i1; i2 < n; ++i2) {
                for (int j2 = 0; j2 < m; ++j2) {
                    if (i1 == i2 && j1 == j2) continue;
                    if (f[i1][j1] == 0 && f[i2][j2] == 0 && abs(i1 - i2) + abs(j1 - j2) == 3) {
                        f[i1][j1] = 1;
                        f[i2][j2] = 1;
                        rec(cnt + 2, i1, j1);
                        f[i1][j1] = f[i2][j2] = 0;
                    }
                }
            }
        }
    }
}

int precalc[6][6] = {
{0,0,0,0,0,0},
{0,0,0,0,2,4},
{0,0,0,4,8,10},
{0,0,4,8,12,14},
{0,2,8,12,16,20},
{0,4,10,14,20,24}
};

ll solve_ok(ll n, ll m) {
    if (n > m) {
        swap(n, m);
    }
    if (n < 6 && m < 6) {
        return precalc[n][m];
    }
    if (n == 1) {
        ll ans = m;
        if (m % 6 == 5) ans -= 1;
        if (m % 6 == 4) ans -= 2;
        if (m % 6 == 3) ans -= 3;
        if (m % 6 == 2) ans -= 2;
        if (m % 6 == 1) ans -= 1;
        return ans;
    }
    if (n == 2 && m == 7) return 12;
    return n * m - (n * m) % 2;

}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    cout << solve_ok(n, m) << endl;
    return 0;
    for (n = 1; n <= 10; ++n) {
        for (m = 1; m <= 12; ++m) {
            ans = 0;
            rec(0, 0, 0);
            int my_ans = solve_ok(n, m);
            if (ans != my_ans) {
                cout << n << ' ' << m << endl;
                exit(228);
            }
            cout << "OK" << endl;
        }
        cout << endl;
    }
    return 0;
}