#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 200 * 1000 + 10;

bool banned[N];
int n;
int m;

ll mabs(ll a) {
    return a > 0 ? a : -a;
}

ll gcd(ll a, ll b) {
    a = mabs(a);
    b = mabs(b);
    if (a == 0 || b == 0)
        return a + b;
    return __gcd(a, b);
}

void gcd_ext(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    ll x0;
    ll y0;
    gcd_ext(b, a % b, x0, y0);
    x = y0;
    y = x0 - a / b * y0;
}

vector<ll> ans_num;
vector<ll> ans_prod;

void add(ll x) {
    if (ans_num.empty()) {
        ans_num.push_back(x);
    } else {
        ll y = ans_prod.back();
        ll a;
        ll t;
        ll g = gcd(m, y);
        gcd_ext(y, m, a, t);
        assert (y * a + m * t == g);
        a *= x / g;
        a = (a % m + m) % m;
        ans_num.push_back(a);
    }
    ans_prod.push_back(x);
}

int dp[N];
vector<int> at[N];

int calc(int v) {
    if (dp[v] != -1)
        return dp[v];
    dp[v] = (int)at[v].size();
    for (int j = 2 * v; j < m; j += v)
        dp[v] = max(dp[v], calc(j) + (int)at[v].size());
    return dp[v];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        banned[x] = true; 
    }
    for (int i = 1; i < m; i++)
        if (!banned[i])
            at[gcd(i, m)].push_back(i);
    fill(dp, dp + m, -1);
    int cur = 1;
    for (int i = 1; i < m; i++)
        if (calc(i) > calc(cur))
            cur = i;
    for (;;) {
        for (int x : at[cur])
            add(x);
        int to = -1;
        for (int j = 2 * cur; j < m; j += cur)
            if (calc(j) + (int)at[cur].size() == calc(cur)) {
                to = j;
                break;
            }
        if (to == -1)
            break;
        else
            cur = to;
    }
    if (!banned[0])
        ans_num.push_back(0);
    cout << ans_num.size() << endl;
    for (int x : ans_num)
        cout << x << " ";
    cout << endl;
}