
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

int n;
set<pii> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    s.emplace(-1, -1);
    rep(i, 0, n) {
        s.emplace(i, i);
        s.emplace(i + 1, i);
        s.emplace(i - 1, i);
        s.emplace(i, i + 1);
        s.emplace(i, i - 1);
    }
    s.emplace(n, n);
    cout << sz(s) << '\n';
    for(auto &p : s) {
        cout << p.first << ' ' << p.second << '\n';
    }
}