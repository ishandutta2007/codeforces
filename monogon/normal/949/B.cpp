
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

int brute(int x, ll n) {
    vi a(2 * n, 0);
    rep(i, 0, n) {
        a[2 * i] = i + 1;
    }
    while(true) {
        int idx = 2 * n - 1;
        while(a[idx] == 0) idx--;
        int jdx = idx - 1;
        while(jdx >= 0 && a[jdx] != 0) jdx--;
        if(jdx < 0) break;
        a[jdx] = a[idx];
        a[idx] = 0;
    }
    return a[x - 1];
    // for(int i = 1; i < n; i += 2) {
    //     cout << a[i] - n/2 << ' ';
    // }
    // cout << endl;
}

ll solve(ll x, ll n) {
    if(x % 2 == 1) {
        return x/2 + 1;
    }else if(n % 2 == 0) {
        return n/2 + solve(x/2, n/2);
    }else if(x == 2) {
        return 1 + solve(n-1, n-1);
    }else {
        return 1 + solve(x-2, n-1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    int q;
    cin >> n >> q;
    while(q--) {
        ll x;
        cin >> x;
        cout << solve(x, n) << '\n';
    }
    // ll n;
    // cin >> n;
    // rep(i, 1, n + 1) {
    //     cout << solve(i, n) - brute(i, n) << ' ';
    // }
    // cout << endl;
    // rep(i, 1, n + 1) {
    //     cout << brute(i, n) << ' ';
    // }
    // cout << endl;
}