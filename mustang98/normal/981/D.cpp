#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 55, infi = 1000111222;

ll dp[max_n][max_n];

ll m[max_n];
int n, k;


bool can_get(ll a) {
    bool dp[max_n][max_n];
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < max_n; ++j) {
            dp[i][j] = 0;
        }
    }
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += m[i];
        dp[i][0] = ((sum & a) == a);
    }

    for (int book = 1; book < n; ++book) {
        for (int pol = 1; pol < k; ++pol) {
            ll sum = 0;
            for (int from = book; from >= 1; --from) {
                sum += m[from];
                if (dp[from - 1][pol - 1] && ((sum & a) == a)) {
                    dp[book][pol] = 1;
                }
            }
        }
    }
    return dp[n - 1][k - 1];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
        //m[i] = (1LL * rand() * rand()) % (1LL << 50);
    }
    ll ans = 0;
    for (int i = 63; i >= 0; --i) {
        ans |= (1LL << i);
        if (can_get(ans) == 0) {
            ans ^= (1LL << i);
        }
    }
    cout << ans;

    return 0;
}