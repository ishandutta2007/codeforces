
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
    int n, m, k;
    cin >> n >> m >> k;
    int extraTable = n % m;
    int extra = extraTable * ((n + m - 1) / m);
    assert(extra <= n);
    vector<bool> ve(n, false);
    rep(i, 0, extra) ve[i] = 1;
    rep(game, 0, k) {
        rotate(ve.begin(), ve.begin() + extra, ve.end());
        int person = 0;
        rep(i, 0, extraTable) {
            cout << ((n + m - 1) / m) << ' ';
            rep(j, 0, (n + m - 1) / m) {
                while(!ve[person]) {
                    person++;
                }
                cout << person + 1 << ' ';
                person++;
            }
            cout << '\n';
        }
        person = 0;
        rep(i, 0, m - extraTable) {
            cout << n / m << ' ';
            rep(j, 0, n / m) {
                while(ve[person]) {
                    person++;
                }
                cout << person + 1 << ' ';
                person++;
            }
            cout << '\n';
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}