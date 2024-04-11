#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int n, k;
    cin >> n >> k;
    VI a(n);
    rep(i, n) cin >> a[i];
    VI div(n, 1);
    int c = k - n;
    priority_queue<
        pair<long long,int>> q;
    auto score = [](ll a, ll d) {
        ll r = a % d;
        ll b = a / d;
        return b * b * (d - r) + (b + 1) * (b + 1) * r;
    };
    rep(i, n) {
        if (div[i] == a[i]) continue;
        //cout << i << ' ' << score(a[i], div[i]) - score(a[i], div[i] + 1) << endl;
        q.emplace(score(a[i], div[i]) - score(a[i], div[i] + 1), i);
    }
    rep(_, c) {
        int i = q.top().second; q.pop();
        //cout << "zz" << i << endl;
        div[i]++;
        if (div[i] == a[i]) continue;
        q.emplace(score(a[i], div[i]) - score(a[i], div[i] + 1), i);
    }
    ll ans = 0;
    //rep(i, n) cout << div[i] << " \n"[i == n - 1];
    rep(i, n) ans += score(a[i], div[i]);
    cout << ans << endl;
}