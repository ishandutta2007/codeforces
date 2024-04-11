
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
    int n; ftype p;
    cin >> n >> p;
    ftype nc3 = 1.0 * n * (n - 1) * (n - 2) / 6;
    rep(i, 0, n + 1) {
        ftype prob = 0;
        // select 0? impossible to select one he studied
        // select 1? probability 1/2
        prob += 0.5 * (1.0 * i * (n - i) * (n - i - 1) / 2) / nc3;
        // select 2? probability 1
        prob += 1.0 * (1.0 * i * (i - 1) * (n - i) / 2) / nc3;
        // select 3? probability 1
        prob += 1.0 * (1.0 * i * (i - 1) * (i - 2) / 6) / nc3;
        if(prob >= p - 1e-12) {
            cout << i << '\n';
            return 0;
        }
    }
}