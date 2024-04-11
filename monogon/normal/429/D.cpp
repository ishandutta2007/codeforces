
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

const int N = 1e5 + 5;
int n;
ll a[N];

struct pt {
    ll x, y;
} p[N];

ll solve(int l, int r) {
    if(l == r) return LLONG_MAX;
    int m = (l + r) / 2;
    ll d = min(solve(l, m), solve(m + 1, r));
    inplace_merge(p + l, p + m + 1, p + r + 1, [&](const pt &a, const pt &b) {
        return a.y < b.y;
    });
    vi ve;
    rep(i, l, r + 1) {
        if(abs(p[i].x - m) <= d) ve.push_back(i);
    }
    ll d2 = d;
    rep(i, 0, sz(ve)) {
        int j = i + 1;
        while(j < sz(ve) && (p[ve[j]].y - p[ve[i]].y) * (p[ve[j]].y - p[ve[i]].y) <= d) {
            d2 = min(d2, (p[ve[i]].x - p[ve[j]].x) * (p[ve[i]].x - p[ve[j]].x) + (p[ve[i]].y - p[ve[j]].y) * (p[ve[i]].y - p[ve[j]].y));
            j++;
        }
    }
    return d2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> a[i];
        a[i] += a[i - 1];
        p[i] = {i, a[i]};
    }
    cout << solve(1, n) << '\n';
}