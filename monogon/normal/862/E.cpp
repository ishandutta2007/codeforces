
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// because of alternating nature, adding x will have most of the a's cancel out.
// only changes if r - l + 1 is odd.
// let's say f(j) doesn't have absolute value, and we wish to minimize | f(j) |
// we either add or subtract x to all f values (or do nothing).
// so we're actually interested in the f value closest to this accumulation.
// precompute all f(j) using prefix sums. Binary search to find closest value.

const int N = 1e5 + 5;
int n, m, q, l, r;
ll a[N], b[N], f[N], x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    rep(i, 1, n + 1) {
        cin >> a[i];
        if(i % 2 == 0) a[i] = -a[i];
        a[i] += a[i - 1];
    }
    rep(i, 1, m + 1) {
        cin >> b[i];
        if(i % 2 == 0) b[i] = -b[i];
        b[i] += b[i - 1];
    }
    rep(j, 0, m - n + 1) {
        f[j] = a[n] - (j % 2 == 0 ? b[n + j] - b[j] : b[j] - b[n + j]);
    }
    sort(f, f + m - n + 1);
    ll y = 0;
    auto getdif = [&]() {
        int idx = lower_bound(f, f + m - n + 1, y) - f;
        ll dif = (idx == m - n + 1 ? LLONG_MAX : abs(y - f[idx]));
        if(idx > 0) dif = min(dif, abs(y - f[idx - 1]));
        cout << dif << '\n';
    };
    getdif();
    while(q--) {
        cin >> l >> r >> x;
        if((r - l + 1) % 2 == 1) {
            if(l % 2 == 1) y -= x;
            else y += x;
        }
        getdif();
    }
}