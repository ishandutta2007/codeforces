#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k, l, m;
ll dp[10][10], dp2[10][10], dp3[10][10];

void calc(ll e) {
    if (e == 1) {
        dp[0][0] = dp[1][1] = 1;
    } else if (e&1) {
        calc(e-1);
        dp2[0][0] = dp2[1][1] = 1, dp2[0][1] = dp2[1][0] = 0;
        memset(dp3, 0, sizeof(dp3));
        for (int i1=0; i1<2; i1++)
            for (int j1=0; j1<2; j1++)
                for (int i2=0; i2<2; i2++)
                    for (int j2=0; j2<2; j2++)
                        if (!(j1&&i2)) {
                            dp3[i1][j2] = (dp3[i1][j2]+dp[i1][j1]*dp2[i2][j2]%m)%m;
                        }

        for (int i=0; i<2; i++)
            for (int j=0; j<2; j++)
                dp[i][j] = dp3[i][j];
    } else {
        calc(e/2);
        for (int i=0; i<2; i++)
            for (int j=0; j<2; j++)
                dp2[i][j] = dp[i][j];
        memset(dp3, 0, sizeof(dp3));

        for (int i1=0; i1<2; i1++)
            for (int j1=0; j1<2; j1++)
                for (int i2=0; i2<2; i2++)
                    for (int j2=0; j2<2; j2++)
                        if (!(j1&&i2)) {
                            dp3[i1][j2] = (dp3[i1][j2]+dp[i1][j1]*dp2[i2][j2]%m)%m;
                        }

        for (int i=0; i<2; i++)
            for (int j=0; j<2; j++)
                dp[i][j] = dp3[i][j];
    }
}

ll exp(ll b, ll e) {
    if (!e) return 1;
    if (e&1) return b*exp(b, e-1)%m;
    ll res = exp(b, e/2);
    return res*res%m;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    }

    cin >> n >> k >> l >> m;
    for (int i=l; i<63; i++)
        if (k&(1LL<<i)) {
            cout << 0;
            return 0;
        }

    calc(n);

    ll num = 0;
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            num = (num+dp[i][j])%m;

    //cerr << num << endl;

    ll ans = 1%m;
    for (int i=0; i<l; i++)
        if ((i<=61) && (k&(1LL<<i))) {
            ll a1 = exp(2, n), a2 = num;
            ll a3 = (a1-a2+m)%m;
            ans = ans*a3%m;
        } else {
            ans = ans*num%m;
        }

    cout << ans;
}