#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, inf = 1000111222;
const ll mod = 998244353;

ll dp[max_n];
int cnt[max_n];
void prec() {
    for (int i = 1; i < max_n; ++i) {
        for (int j = i; j < max_n; j += i) {
            ++cnt[j];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    prec();

    dp[1] = 1;
    ll sum = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = (sum + cnt[i]) % mod;
        sum += dp[i];
        sum %= mod;
    }
    cout << dp[n] << endl;


    return 0;
}