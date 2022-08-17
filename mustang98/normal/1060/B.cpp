#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

int sum(ll a) {
    int ans = 0;
    while (a) {
        ans += (a % 10);
        a /= 10;
    }
    return ans;
}

int solve_dumb(ll n) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int j = n - i;
        ans = max(ans, sum(i) + sum(j));
    }
    return ans;
}

ll solve(ll n) {
    if (n < 10) {
        return n;
    }
    ll ans = 9;
    while (ans * 10 + 9 <= n) {
        ans = ans * 10 + 9;
    }
    ll ans2 = n - ans;
    return sum(ans) + sum(ans2);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    cout << solve(n);
    return 0;
}