
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

// (a, 0) (0, b) pair if the sum of t is better than (a, b) pair

int n, k, a, b;
ll t;
vector<ll> ve[2][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 0, n) {
        cin >> t >> a >> b;
        ve[a][b].push_back(t);
    }
    sort(all(ve[0][1]));
    sort(all(ve[1][0]));
    vector<ll> sums;
    for(ll x : ve[1][1]) sums.push_back(x);
    for(int i = 0; i < min(sz(ve[0][1]), sz(ve[1][0])); i++) {
        sums.push_back(ve[0][1][i] + ve[1][0][i]);
    }
    sort(all(sums));
    if(sz(sums) < k) {
        cout << "-1\n";
        return 0;
    }
    cout << accumulate(sums.begin(), sums.begin() + k, 0LL) << '\n';
}