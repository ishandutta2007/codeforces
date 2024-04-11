
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
    vector<pii> ve;
    rep(i, 0, n) {
        int a;
        cin >> a;
        ve.push_back({a, i});
    }
    sort(all(ve));
    if(ve[0].first != ve[1].first) {
        cout << ve[0].second + 1 << '\n';
    }else {
        cout << ve.back().second + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}