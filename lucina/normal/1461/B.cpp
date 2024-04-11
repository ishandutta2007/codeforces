#include<bits/stdc++.h>
using namespace std;
const int N = 512;
int n, m;
char s[N][N];
int up[N][N];


void solve() {
    cin >> n >> m;
    memset(up, 0, sizeof(up));

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> (s[i] + 1);

    }


    for (int i = 1 ; i <= n ; ++ i)
    for (int j = 1 ; j <= m ; ++ j) {
        if (s[i][j] != '*') continue;
        int top = 0;
        for (int k = i ; k >=1 ; -- k) {
            if (s[k][j] != '*') break;
            ++ top;
        }
        up[i][j] = top;

      //  cout << up[i][j] << ' ';

    }

    int ans = 0;

    for (int i = 1 ; i <= n ; ++ i)
    for (int j = 1 ; j <= m ; ++ j) {
        static int bar[N];
        if (!up[i][j]) continue;


        for (int k = j - 1, foo = 1 ; k > 0 && j + foo <= m ; -- k, ++ foo) {
            bar[foo] = min(up[i][k], up[i][j + foo]);
        }
        bar[0] = up[i][j];

        int t = min(j - 1, m - j);
        int max_can = bar[0];
        ++ ans;

       // cout << "T " << t << '\n';

        for (int k = 1 ; k <= t ; ++ k) {
            -- max_can;
            max_can = min(max_can, bar[k]);
            if (max_can <= 0) break;
            ++ ans;
        }
    //    cout << ans << '\n';


    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}