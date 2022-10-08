
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

const int N = 1005;
int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    vector<pii> inv;
    rep(i, 0, n) rep(j, i + 1, n) {
        if(a[i] > a[j]) {
            inv.emplace_back(i, j);
        }
    }
    sort(inv.begin(), inv.end(), [&](pii p, pii q) {
        return make_tuple(-p.second, a[p.first], p.first) < make_tuple(-q.second, a[q.first], q.first);
    });
    cout << sz(inv) << '\n';
    for(auto &p : inv) {
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }
}