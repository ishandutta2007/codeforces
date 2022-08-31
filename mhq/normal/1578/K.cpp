#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = 258;
int dp[maxN][maxN][maxN];
int ndp[maxN][maxN][maxN];
int p[maxN];
int q[maxN];
int from[maxN];
int back[maxN];
bool mark[maxN];
void upd(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
int fact[maxN];
signed main() {
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
    int zeroes = 0;
    int X = 0;
    int twos = 0;
    int Y = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }
    memset(from, -1, sizeof from);
    memset(back, -1, sizeof back);
    for (int i = 1; i <= n; i++) {
        if (p[i] != 0) from[p[i]] = q[i];
        if (q[i] != 0) back[q[i]] = p[i];
    }
    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] == 0) {
            if (q[i] == 0) {
                zeroes++;
            }
            else {
                int z = q[i];
                while (true) {
                    mark[z] = true;
                    if (from[z] == -1) {
                       X++;
                       break;
                    }
                    z = from[z];
                    if (z == 0) {
                        zeroes++;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (q[i] == 0 && p[i] != 0) {
            if (mark[p[i]]) continue;
            int z = p[i];
            while (true) {
                mark[z] = true;
                if (back[z] == -1) {
                    Y++;
                    break;
                }
                z = back[z];
                if (z == 0) {
                    assert(false);
                    mark[z] = true;
                    zeroes++;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] != 0 && q[i] != 0 && back[p[i]] == -1 && !mark[p[i]]) {
            twos++;
            int st = p[i];
            while (true) {
                mark[st] = true;
                st = from[st];
                assert(st != 0);
                if (st == -1) break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] != 0 && q[i] != 0 && !mark[p[i]]) {
            k++;
            int st = p[i];
            while (!mark[st]) {
                mark[st] = true;
                st = from[st];
            }
        }
    }
    dp[X][twos][k] = 1;
    for (int i = X; i > 0; i--) {
        for (int cnt_twos = 0; cnt_twos <= n; cnt_twos++) {
            for (int cur_k = 0; cur_k <= n; cur_k++) {
                if (!dp[i][cnt_twos][cur_k]) continue;
                int d = dp[i][cnt_twos][cur_k];
                upd(dp[i - 1][cnt_twos][cur_k + 1], d);
                upd(dp[i - 1][cnt_twos][cur_k], mult(d, i - 1));
                upd(dp[i - 1][cnt_twos][cur_k], mult(d, cnt_twos));
                upd(dp[i - 1][cnt_twos + 1][cur_k], mult(d, zeroes - cnt_twos));
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[0][i][j]) {
             //   cout << i << " " << j << " ?? " << dp[0][i][j] << endl;
            }
            ndp[Y][i][j] = dp[0][i][j];
        }
    }
    memset(dp, 0, sizeof dp);
    memcpy(dp, ndp, sizeof dp);
    for (int i = Y; i > 0; i--) {
        for (int cnt_twos = 0; cnt_twos <= n; cnt_twos++) {
            for (int cur_k = 0; cur_k <= n; cur_k++) {
                if (!dp[i][cnt_twos][cur_k]) continue;
                int d = dp[i][cnt_twos][cur_k];
                upd(dp[i - 1][cnt_twos][cur_k + 1], d);
                upd(dp[i - 1][cnt_twos][cur_k], mult(d, i - 1));
                upd(dp[i - 1][cnt_twos][cur_k], mult(d, cnt_twos));
                upd(dp[i - 1][cnt_twos + 1][cur_k], mult(d, zeroes - cnt_twos));
            }
        }
    }
    memset(ndp, 0, sizeof ndp);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = mult(fact[i - 1], i);
    for (int cnt_twos = 0; cnt_twos <= n; cnt_twos++) {
        for (int cyc = 0; cyc <= n; cyc++) {
            if (dp[0][cnt_twos][cyc]) {
        //        cout << " ??? " << cnt_twos << " " << cyc << " " << dp[0][cnt_twos][cyc] << endl;
                assert(zeroes >= cnt_twos);
                ndp[zeroes][0][cyc] = sum(ndp[zeroes][0][cyc], mult(dp[0][cnt_twos][cyc], fact[zeroes]));
            }
        }
    }
    memset(dp, 0, sizeof dp);
    memcpy(dp, ndp, sizeof dp);
    //for (int i = 0; i <= n; i++) {
  //      for (int cyc = 0; cyc <= n; cyc++) {
  //          if (dp[i][0][cyc]) {
              //  cout << i << " " << cyc << " ?? " << dp[i][0][cyc] << endl;
  //          }
//        }
  //  }

    for (int i = n; i > 0; i--) {
        for (int cnt_twos = 0; cnt_twos <= n; cnt_twos++) {
            for (int cur_k = 0; cur_k <= n; cur_k++) {
                if (!dp[i][cnt_twos][cur_k]) continue;
                assert(cnt_twos == 0);
                int d = dp[i][cnt_twos][cur_k];
                upd(dp[i - 1][cnt_twos][cur_k + 1], d);
                upd(dp[i - 1][cnt_twos][cur_k], mult(d, i - 1));
                //upd(dp[i - 1][cnt_twos][cur_k], mult(d, cnt_twos));
                //upd(dp[i - 1][cnt_twos + 1][cur_k], mult(d, zeroes - cnt_twos));
            }
        }
    }
    //cout << dp[0][0][4] << " ?????? " << k << endl;
    for (int t = 0; t < n; t++) {
        cout << dp[0][0][n - t] << " ";
    }
    return 0;
}