#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, max_val = 20000011, inf = 1000111222;

vector<int> prdiv[max_val];
int n;
int cnt[max_val];
ll dp[max_val];

void proc(int x) {
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            int j = x / i;
            cnt[i]++;
            if (j != i) cnt[j]++;
        }
    }
}

bool is_sost[max_val];

void init() {
    for (int i = 2; i < max_val; ++i) {
        if (is_sost[i]) continue;
        prdiv[i].PB(i);
        for (int j = i + i; j < max_val; j += i) {
            is_sost[j] = true;
            if (cnt[j]) {
                prdiv[j].push_back(i);
            }
        }
    }
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        proc(x);
    }
    init();
    dp[1] = n;
    ll ans = n;
    for (int i = 2; i < max_val; ++i) {
        if (cnt[i] == 0) continue;
        for (int x : prdiv[i]) {
            int to = i / x;
            ll val = dp[to] + 1LL * cnt[i] * (i - to);
            dp[i] = max(dp[i], val);
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << endl;
    return 0;
}