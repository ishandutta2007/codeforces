
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

const int N = 2005;
int n, m, k;
int a[N], b[N];

void thonk(int l, int r, int *a, int x) {
    rep(i, l, r + 1) {
        a[i] += x;
    }
}

ll orz(int *a) {
    ll s = 0, ans = 0;
    int L = 1, R = 0;
    rep(i, 1, n - k + 2) {
        while(R < i + k) {
            s += a[R];
            R++;
        }
        while(L < i) {
            s -= a[L];
            L++;
        }
        ans = max(ans, s);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    vector<pii> ve;
    rep(i, 0, m) {
        int l, r;
        cin >> l >> r;
        ve.emplace_back(l, r);
        thonk(l, r, a, 1);
    }
    sort(all(ve), [&](pii &a, pii &b) {
        return a.first + a.second < b.first + b.second;
    });
    ll ans = orz(a) + orz(b);
    rep(i, 0, sz(ve)) {
        int l, r;
        tie(l, r) = ve[i];
        thonk(l, r, a, -1);
        thonk(l, r, b, 1);
        ans = max(ans, orz(a) + orz(b));
    }
    cout << ans << '\n';
}