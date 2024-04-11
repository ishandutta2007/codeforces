
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    ll k;
    cin >> n >> q >> k;
    vector<ll> a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    while(q--) {
        int l, r;
        cin >> l >> r;
        ll sad = a[l] - 1 + k - a[r], pensive = k - sad - (r - l + 1);
        cout << sad + 2 * pensive << '\n';
    }
}