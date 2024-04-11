
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

const int N = 2e5 + 5;
int n;
ll a[N];
int ind[30], l[N], r[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    ll ans = 1LL * n * (n + 1) / 2;
    rep(i, 1, n + 1) {
        rep(k, 0, 30) {
            if((a[i] >> k) & 1) {
                ind[k] = i;
            }else {
                l[i] = max(l[i], ind[k]);
            }
        }
    }
    fill(ind, ind + 30, n + 1);
    map<ll, int> ma;
    for(int i = n; i >= 1; i--) {
        r[i] = n + 1;
        if(ma.count(a[i])) r[i] = ma[a[i]];
        rep(k, 0, 30) {
            if((a[i] >> k) & 1) {
                ind[k] = i;
            }else {
                r[i] = min(r[i], ind[k]);
            }
        }
        ma[a[i]] = i;
    }
    rep(i, 1, n + 1) {
        ans -= 1LL * (r[i] - i) * (i - l[i]);
    }
    cout << ans << '\n';
}