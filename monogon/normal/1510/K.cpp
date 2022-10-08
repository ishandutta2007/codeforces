
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
    cin >> n;
    vi p(2 * n);
    rep(i, 0, 2 * n) {
        cin >> p[i];
    }
    vi p2(all(p));
    auto op1 = [&]() {
        rep(i, 0, n) swap(p2[2 * i], p2[2 * i + 1]);
    };
    auto op2 = [&]() {
        rep(i, 0, n) swap(p2[i], p2[n + i]);
    };
    auto check = [&]() {
        rep(i, 0, 2 * n) {
            if(p2[i] != i + 1) return false;
        }
        return true;
    };
    int ans = INT_MAX;
    rep(it, 0, 2 * n + 5) {
        if(check()) ans = min(ans, it * 2);
        op1();
        if(check()) ans = min(ans, it * 2 + 1);
        op2();
    }
    p2.assign(all(p));
    rep(it, 0, 2 * n + 5) {
        if(check()) ans = min(ans, it * 2);
        op2();
        if(check()) ans = min(ans, it * 2 + 1);
        op1();
    }
    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}