
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
    ll hc, dc, hm, dm;
    cin >> hc >> dc >> hm >> dm;
    int k;
    ll w, a;
    cin >> k >> w >> a;
    auto check = [&](ll a, ll da, ll b, ll db) -> bool {
        ll times = min((b - 1) / da, (a - 1) / db);
        a -= times * db;
        b -= times * da;
        return b - da <= 0;
    };
    rep(i, 0, k + 1) {
        if(check(hc + a * i, dc + w * (k - i), hm, dm)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}