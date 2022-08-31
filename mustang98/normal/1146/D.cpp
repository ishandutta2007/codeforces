#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, inf = 1000111222;

bool vis[max_n];
ll a, b, n;
ll curn;
ll border;

bool onf(ll x) {
    return x >= 0 && x <= curn;
}
ll cvis = 0;
bool reach[max_n];

void dfs(ll cur) {
    vis[cur] = 1;
    ++cvis;
    if (onf(cur + a) && !vis[cur + a]) {
        dfs(cur + a);
    }
    if (cur + a > curn && cur + a <= border) {
        reach[cur + a] = true;
    }
    if (onf(cur - b) && !vis[cur - b]) {
        dfs(cur - b);
    }
}

long long sumto(ll a) {
    return a * (a + 1) / 2;
}

long long sum(ll a, ll g) {
    ll cnt = a / g;
    ll from = a - (a % g);
    --cnt;
    ll res = 0;
    if (cnt >= 0) {
        res = sumto(cnt);
        res *= g;
    }
    for (int i = from; i <= a; ++i) {
        res += a / g;
    }
    return res + a + 1;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> a >> b;
    border = min(1000000LL, n);
    ll ans = 0;
    reach[0] = 1;
    for (curn = 0; curn <= border; ++curn) {
        if (reach[curn]) {
            dfs(curn);
        }
        ans += cvis;
    }
    ll g = __gcd(a, b);
    long long ans1 = sum(n, g) - sum(border, g);
    ans += ans1;
    cout << ans << endl;
    return 0;
}