
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

ll score(vi a) {
    ll k = accumulate(all(a), 0LL);
    ll d = k / 4;
    rep(i, 0, 101) {
        ll amt = min(1LL * a[i], d);
        d -= amt;
        a[i] -= amt;
    }
    ll s = 0;
    rep(i, 0, 101) {
        s += 1LL * a[i] * i;
    }
    return s;
}

void solve() {
    int n;
    cin >> n;
    vi a(101, 0), b(101, 0);
    rep(i, 0, n) {
        int x;
        cin >> x;
        a[x]++;
    }
    rep(i, 0, n) {
        int x;
        cin >> x;
        b[x]++;
    }
    int L = 0, R = 1e8;
    while(L < R) {
        int m = (L + R) / 2;
        a[100] += m;
        b[0] += m;
        if(score(a) < score(b)) {
            L = m + 1;
        }else {
            R = m;
        }
        a[100] -= m;
        b[0] -= m;
    }
    cout << L << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}