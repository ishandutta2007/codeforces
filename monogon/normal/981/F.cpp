
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
    int n;
    ll L;
    cin >> n >> L;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    rep(i, 0, n) {
        a.push_back(a[i] + L);
    }
    rep(i, 0, n) {
        b.push_back(b[i] - L);
        b.push_back(b[i] + L);
        b.push_back(b[i] + 2 * L);
    }
    sort(all(a));
    sort(all(b));
    ll le = 0, ri = (L + 1) / 2;
    while(le < ri) {
        int mid = (le + ri) / 2;
        int mx = INT_MIN;
        bool flag = false;
        rep(i, 0, 2 * n) {
            int f1 = lower_bound(all(b), a[i] - mid) - b.begin();
            int f2 = lower_bound(all(b), a[i] + mid + 1) - b.begin();
            mx = max(mx, f1 - i + 1);
            if(f2 - i < mx) {
                flag = true;
                break;
            }
        }

        if(flag) {
            le = mid + 1;
        }else {
            ri = mid;
        }
    }
    cout << le << '\n';
}