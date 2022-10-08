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

const int N = 1e6 + 5;

int getmin(const vi &ve, int k) {
    vi cnt(N, 0);
    bitset<N> dp;
    dp.set(0, true);
    for(int x : ve) {
        cnt[x]++;
    }
    rep(i, 0, N) {
        if(cnt[i] == 0) continue;
        for(int x = 0; (1 << x) < cnt[i]; x++) {
            dp |= (dp << ((1 << x) * i));
            cnt[i] -= (1 << x);
        }
        dp |= (dp << (cnt[i] * i));
    }
    return dp[k] ? k : k + 1;
}

int getmax(const vi &ve, int k) {
    vi a;
    for(int len : ve) {
        rep(i, 0, len / 2) {
            a.push_back(0);
            a.push_back(2);
        }
        if(len % 2 == 1) a.push_back(1);
    }
    sort(all(a), greater<>());
    int sum = 0;
    rep(i, 0, k) sum += a[i];
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vi p(n + 1);
    rep(i, 1, n + 1) cin >> p[i];
    vector<bool> vis(n + 1, false);
    vi ve;
    rep(i, 1, n + 1) {
        if(!vis[i]) {
            int x = i, len = 0;
            while(!vis[x]) {
                vis[x] = true;
                x = p[x];
                len++;
            }
            ve.push_back(len);
        }
    }
    sort(all(ve));
    cout << getmin(ve, k) << ' ' << getmax(ve, k) << '\n';
}