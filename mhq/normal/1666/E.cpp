#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
int n;
ll l;
const int maxN = 1e5 + 10;
ll a[maxN];
void solve()
{
//    l = rand() % 1000000;
//    n = rand() % 10 + 1;
    cin >> l >> n;
//    set<int> ss;
    set<int> ss;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
//        a[i] = rand() % (l - 1) + 1;
//        ss.insert(a[i]);
    }
//    sort(a + 1, a + n + 1);
//    n = unique(a + 1, a + n + 1) - a;
//    n = ss.size();
//    int sz = 0;
//    for (auto& it : ss) {
//        a[++sz] = it;
//    }
//    assert(sz == n);
//    assert(a[1] > 0);
//    cout << n << " " << l << " " << a[n] << endl;
//    for (int i = 1; i <= n; i++) {
//        assert(a[i] > a[i - 1] && a[i] < l);
//    }
    a[n + 1] = l;
    ll at_most = l + 5;
    ll le = 1;
    ll ri = l + 5;
    while (ri - le > 1) {
        ll mid = (ri + le) / 2;
        ll cur = 0;
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            cur += mid;
            if (cur > a[i + 1]) {
                ok = false;
                break;
            }
            cur = max(cur, a[i]);
        }
        if (ok) {
            le = mid;
        }
        else {
            ri = mid;
        }
    }
    ll A = le;
    le = 1;
    ri = l + 5;
    while (ri - le > 1) {
        ll mid = (ri + le) / 2;
        ll cur = 0;
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            cur += mid;
            if (cur < a[i]) {
                ok = false;
                break;
            }
            cur = min(cur, a[i + 1]);
        }
        if (cur != l) ok = false;
        if (ok) {
            ri = mid;
        }
        else {
            le = mid;
        }
    }
    ll B = ri;
    ll L = l;
    ll R = l;
    assert(A >= 1 && A <= B);
    vector<pair<ll,ll>> good_segs;
    good_segs.emplace_back(L, R);
    for (int i = n; i >= 1; i--) {
        L -= B;
        R -= A;
        L = max(L, a[i - 1]);
        R = min(R, a[i]);
        assert(L <= R);
        if (i == 1) {
            assert(L == 0);
            R = 0;
        }
        good_segs.emplace_back(L, R);
    }
    reverse(good_segs.begin(), good_segs.end());

    vector<ll> ans;
    ll cur = 0;
    ans.emplace_back(0);
    for (int i = 1; i <= n; i++) {
        ll nxt = max(cur + A, good_segs[i].first);
        assert(nxt - cur <= B && nxt <= good_segs[i].second);
        ans.emplace_back(nxt);
        cur = nxt;
    }
    assert(ans[0] == 0 && ans[n] == l);
    for (int i = 1; i <= n; i++) {
        assert(ans[i] - ans[i - 1] >= A && ans[i] - ans[i - 1] <= B);
        assert(ans[i - 1] <= a[i] && a[i] <= ans[i]);
    }
    for (int z = 0; z < n; z++) {
        cout << ans[z] << " " << ans[z + 1] << '\n';
    }


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int t = 1;
    // scanf ("%d", &t);
//    cin >> t;
    while (t--)
        solve();
}