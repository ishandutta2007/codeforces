
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
    int n;
    cin >> n;
    map<ll, int> ma;
    ll sumb = 0;
    rep(i, 0, n + 2) {
        ll b;
        cin >> b;
        ma[b]++;
        sumb += b;
    }
    vector<pair<ll, int>> ve(all(ma));
    for(auto &pa : ve) {
        ll x = pa.first;
        ll suma2 = sumb - x;
        if(suma2 % 2 == 0 && (ma[suma2 / 2] >= 2 || (ma[suma2 / 2] >= 1 && suma2 / 2 != x))) {
            ma[suma2 / 2]--;
            ma[x]--;
            for(auto &pa2 : ma) {
                rep(i, 0, pa2.second) {
                    cout << pa2.first << ' ';
                }
            }
            cout << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // sum(b) = 2 sum(a) + x
    // given x, is (sum(b) - x) / 2 an element of b?
    int te;
    cin >> te;
    while(te--) solve();
}