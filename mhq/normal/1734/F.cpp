#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m;
ll dp[65][2][2][2];
void solve() {
    cin >> n >> m;
    memset(dp, 0, sizeof dp);
    dp[0][0][0][0] = 1;

    for (int bit = 0; bit <= 62; bit++) {
        int his_add = (ll)((n >> (ll)bit) & 1);
        int his_bit = (ll)((m >> (ll)bit) & 1);
        for (int carry = 0; carry < 2; carry++) {
            for (int flag = 0; flag < 2; flag++) {
                for (int dif = 0; dif < 2; dif++) {
                    if (!dp[bit][carry][flag][dif]) continue;
                    for (int our_bit = 0; our_bit < 2; our_bit++) {
                        int new_flag = ((our_bit < his_bit) || (our_bit == his_bit && flag));
                        int new_dif = (dif ^ (our_bit ^ ((our_bit + his_add + carry) & 1)));
                        int new_carry = (our_bit + his_add + carry) / 2;
                        dp[bit + 1][new_carry][new_flag][new_dif] += dp[bit][carry][flag][dif];
                    }
                }
            }
        }
    }
    cout << dp[63][0][1][1] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}