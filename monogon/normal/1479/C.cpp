
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
    int L, R;
    cin >> L >> R;
    cout << "YES\n";
    const int N = 32;

    vector<array<ll, 3>> ar;

    if(L == R) {
        ar.push_back({1, N, L});
    }else {
        rep(i, 3, N) {
            ar.push_back({i, N, 1});
            ll p2 = 1;
            for(int j = N - 1; j > i; j--) {
                ar.push_back({i, j, p2});
                p2 <<= 1;
            }
        }
        int x = 2;
        if(L == 1) {
            x = 1;
        }else {
            ar.push_back({1, 2, L - 1});
        }
        ll val = R - L + 1;
        rep(i, 3, N) {
            ll y = (1LL << (N - i - 1));
            if(y < val) {
                ar.push_back({x, i, val - y});
                val -= y;
            }
        }
        ar.push_back({x, N, 1});
    }

    cout << N << ' ' << sz(ar) << '\n';
    for(auto &a : ar) {
        cout << a[0] << ' ' << a[1] << ' ' << min(a[2], (ll) 1e6) << '\n';
    }
}