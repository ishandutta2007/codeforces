
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

ll n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    cout << k * (5 + (n - 1) * 6) << '\n';
    for(ll i = 1; i < 1 + 6 * n; i += 6) {
        cout << i*k << ' ' << (i+1)*k << ' ' << (i+2)*k << ' ' << (i+4)*k << '\n';
    }
}