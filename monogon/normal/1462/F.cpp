
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

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ord;

struct seg {
    ll l, r;
    int val;
    bool operator<(const seg &s) {
        return make_pair(l, r) < make_pair(s.l, s.r);
    }
};

vector<seg> s;

void solve() {
    ord se;
    int n = sz(s);
    rep(i, 0, n) {
        s[i].val += se.order_of_key(s[i].l);
        se.insert(s[i].r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        s.resize(n);
        rep(i, 0, n) {
            cin >> s[i].l >> s[i].r;
            s[i].val = 0;
        }
        sort(all(s));
        solve();
        rep(i, 0, n) {
            swap(s[i].l, s[i].r);
            s[i].l = -s[i].l;
            s[i].r = -s[i].r;
        }
        sort(all(s));
        solve();
        int ans = n;
        rep(i, 0, n) {
            ans = min(ans, s[i].val);
            // cout << s[i].val << ' ';
        }
        // cout << endl;
        cout << ans << '\n';
    }
}