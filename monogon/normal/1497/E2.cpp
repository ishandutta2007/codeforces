
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e7 + 5;
int pr[N];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<ll, int> ma;
    int cnt = 0;
    rep(i, 0, n) {
        ll x;
        cin >> x;
        a[i] = 1;
        while(x > 1) {
            int p = pr[x];
            int cnt = 0;
            while(x % p == 0) {
                x /= p;
                cnt++;
            }
            if(cnt % 2 == 1) {
                a[i] *= p;
            }
        }
        if(!ma.count(a[i])) ma[a[i]] = cnt++;
        a[i] = ma[a[i]];
    }
    vi num(cnt, 0);
    vector<vi> nxt(n, vi(k + 1));

    rep(l, 0, k + 1) {
        fill(all(num), 0);
        int cost = 0;
        int j = 0;
        rep(i, 0, n) {
            while(j < n && cost + (num[a[j]] > 0) <= l) {
                cost += (num[a[j]] > 0);
                num[a[j]]++;
                j++;
            }
            nxt[i][l] = j;
            num[a[i]]--;
            cost -= (num[a[i]] > 0);
        }
    }
    vector<vi> dp(n + 1, vi(k + 1));
    for(int i = n - 1; i >= 0; i--) {
        rep(j, 0, k + 1) {
            dp[i][j] = INT_MAX;
            rep(j2, 0, j + 1) {
                dp[i][j] = min(dp[i][j], 1 + dp[nxt[i][j - j2]][j2]);
            }
        }
    }
    cout << dp[0][k] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(i, 2, N) {
        if(pr[i] == 0) {
            for(int p = i; p < N; p += i) {
                pr[p] = i;
            }
        }
    }

    int te;
    cin >> te;
    while(te--) solve();
}