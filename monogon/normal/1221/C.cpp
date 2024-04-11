
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
    // k teams
    // c >= k, m >= k, c + m + x >= 3k
    int q;
    cin >> q;
    while(q--) {
        ll c, m, k;
        cin >> c >> m >> k;
        cout << min({c, m, (c + m + k) / 3}) << '\n';
    }
}