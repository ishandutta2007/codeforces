
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

int n, d, m, x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d >> m;
    rep(i, 0, m) {
        cin >> x >> y;
        if(x + y >= d && x + y <= 2 * n - d && x - y <= d && y - x <= d) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}