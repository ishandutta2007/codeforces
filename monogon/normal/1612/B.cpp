
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

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vi A, B;
    A.push_back(a);
    B.push_back(b);
    // everything < a => in second half
    // everything > b => in first half
    // is there something b < x < a?
    if(a - b >= 2) {
        cout << -1 << '\n';
        return;
    }
    rep(i, 1, n + 1) {
        if(i == a || i == b) continue;
        if(i < a) B.push_back(i);
        if(i > b) A.push_back(i);
    }
    rep(i, 1, n + 1) {
        if(i > a && i < b) {
            (sz(A) < n / 2 ? A : B).push_back(i);
        }
    }
    if(sz(A) != n / 2) {
        cout << -1 << '\n';
    }else {
        for(int x : A) cout << x << ' ';
        for(int x : B) cout << x << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}