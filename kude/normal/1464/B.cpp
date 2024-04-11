#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

constexpr ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    ll x, y;
    cin >> x >> y;
    if (x > y) {
        swap(x, y);
        rep(i, n) if (s[i] != '?') {
            s[i] = 1 - (s[i] - '0') + '0';
        }
    }
    ll score = 0;
    int cnt0 = 0, cnt1 = 0;
    rep(i, n) {
        if (s[i] == '0') {
            score += cnt1 * y;
            cnt0++;
        } else {
            score += cnt0 * x;
            cnt1++;
        }
    }
    ll ans = score;
    int cl0 = 0, cl1 = 0;
    rep(i, n) {
        if (s[i] == '0') {
            cl0++;
            cnt0--;
        } else if (s[i] == '1') {
            cl1++;
            cnt1--;
        } else {
            cnt1--;
            score -= cl0 * x + cnt0 * y;
            score += cl1 * y + cnt1 * x;
            chmin(ans, score);
            cl0++;
        }
    }
    cout << ans << endl;
}