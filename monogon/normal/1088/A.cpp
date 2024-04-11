
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
    int x;
    cin >> x;
    rep(a, 1, x + 1) {
        rep(b, 1, x + 1) {
            if(a % b == 0 && a * b > x && a < x * b) {
                cout << a << ' ' << b << '\n';
                return 0;
            }
        }
    }
    cout << -1 << '\n';
}