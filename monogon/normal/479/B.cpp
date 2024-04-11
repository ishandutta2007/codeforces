
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

int n, k, a;
set<pii> s;
vector<pii> ops;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 0, n) {
        cin >> a;
        s.emplace(a, i);
    }
    while(sz(ops) < k && s.begin()->first < prev(s.end())->first) {
        ops.emplace_back(prev(s.end())->second, s.begin()->second);
        pii p = *s.begin();
        pii p2 = *prev(s.end());
        s.erase(s.begin());
        s.erase(prev(s.end()));
        s.emplace(p.first + 1, p.second);
        s.emplace(p2.first - 1, p2.second);
    }
    cout << prev(s.end())->first - s.begin()->first << ' ' << sz(ops) << '\n';
    for(auto &p : ops) {
        cout << p.fi + 1 << ' ' << p.se + 1 << '\n';
    }
}