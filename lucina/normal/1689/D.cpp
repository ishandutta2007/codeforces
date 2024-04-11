#include<bits/stdc++.h>
using namespace std;
const int nax = 1024;
#define int int64_t
char s[nax][nax];
int x[nax][nax];
int ans[nax][nax];
int a[nax][nax];
int n, m;


void solve() {
    cin >> n >> m;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> s[i] + 1;
        for (int j = 1 ; j <= m ; ++ j)
            x[i][j] = (s[i][j] == 'B'), ans[i][j] = -1e9;
    }

    auto fill = [&](int f) {
        for (int i = 0 ; i <= n + 1 ; ++ i) {
            for (int j = 0 ; j <= m + 1 ; ++ j) {
                a[i][j]= f;
            }
        }
    };

    const int INF = 1e9;
    fill(-INF);

    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ; j <= m ; ++ j) {
            a[i][j] = max(a[i - 1][j], a[i][j - 1]);
            if (x[i][j]) a[i][j] = max(a[i][j], -i - j);
            ans[i][j] = max(ans[i][j], i + j + a[i][j]);
        }
    }

    fill(-INF);
    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = m ; j >= 1 ; -- j) {

            /**
                x, y from upper right
                distance equal to
                y - j + i - x
                i - j + y - x
            */
            a[i][j] = max(a[i - 1][j], a[i][j + 1]);
            if (x[i][j]) a[i][j] = max(a[i][j], j - i);
            ans[i][j] = max(ans[i][j], i - j + a[i][j]);
        }
    }


    fill(-INF);
    for (int i = n ; i >= 1 ; -- i) {
        for (int j = 1 ; j <= m ; ++ j) {
            /**
                x, y from lower left
                x - i + j - y
            */
            a[i][j] = max(a[i + 1][j], a[i][j - 1]);
            if (x[i][j]) a[i][j] = max(a[i][j], i - j);
            ans[i][j] = max(ans[i][j], -i + j + a[i][j]);
        }
    }


    fill(-INF);
    for (int i = n ; i >= 1 ; -- i) {
        for (int j = m ; j >= 1 ; -- j) {
            /**
                x, y from lower left
                x + y - i - j
            */
            a[i][j] = max(a[i + 1][j], a[i][j + 1]);
            if (x[i][j]) a[i][j] = max(a[i][j], i + j);
            ans[i][j] = max(ans[i][j], -i - j + a[i][j]);
        }
    }

    int c_ans = INF, x, y;

    for (int i = 1 ; i <= n ; ++ i)
    for (int j = 1 ; j <= m ; ++ j) {
        if (ans[i][j] < c_ans) {
            c_ans = ans[i][j];
            x = i, y = j;
        }
    }
    cout << x << ' ' << y << '\n';

}

 main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    +_+ So bored lately.
*/