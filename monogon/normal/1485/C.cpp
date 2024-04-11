
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
    int te;
    cin >> te;
    while(te--) {
        ll x, y;
        cin >> x >> y;
        ll sad = 0;
        for(ll r = 1; r + 1 <= x / r; r++) {
            ll ugh = max(0LL, min(y, x / r - 1) - (r + 1) + 1);
            sad += ugh;
        }
        cout << sad << '\n';
    }
}