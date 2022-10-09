
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

using ftype = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r;
    cin >> n >> r;
    vector<ftype> y(n);
    vector<ll> x(n);
    cout << fixed << setprecision(8);
    rep(i, 0, n) {
        y[i] = r;
        cin >> x[i];
        rep(j, 0, i) {
            ll dx = x[i] - x[j];
            if(abs(dx) <= 2 * r) {
                y[i] = max(y[i], y[j] + sqrtl(4 * r * r - dx * dx));
            }
        }
        cout << y[i] << " ";
    }
    cout << "\n";
}