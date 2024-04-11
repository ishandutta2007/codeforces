#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
int q;
const int maxN = (int)1e5 + 100;
ll ans[maxN];
ll len[maxN];
ll d[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    vector < ll > s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    n = s.size();
    cin >> q;
    vector < pair < ll, int > > que(q);
    for (int i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        que[i].first = r - l + 1;
        que[i].second = i + 1;
    }
    sort(que.begin(), que.end());
    que.push_back({2 * (ll)1e18, -1});
    s.push_back(2 * (ll)1e18);
    n = s.size();
    for (int i = 0; i + 1 < n; i++) {
        ll x = s[i];
        ll y = s[i + 1];
        int ind = lower_bound(que.begin(), que.end(), make_pair(y - x, -1)) - que.begin();
       // cout << x << " " << y << " " << ind;
        if (ind < q) {
            d[ind] += y - x;
        }
        len[0] += 1;
        len[ind] -= 1;
    }
    ll cur_len = 0;
    ll cur_ans = 0;
    ll cur_add = 0;
    for (int i = 0; i < q; i++) {
        cur_add += d[i];
        cur_len += len[i];
        cur_ans = cur_len * que[i].first + cur_add;
        ans[que[i].second] = cur_ans;
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}