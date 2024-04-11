
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
    int n, m, h;
    cin >> n >> m >> h;
    int dom = n * m / 2;
    if((n % 2 == 0 && h % 2 == 0) || (m % 2 == 0 && (dom - h) % 2 == 0)) {
        if((m % 2 == 1 && 2 * h + n > n * m) || (n % 2 == 1 && 2 * (dom - h) + m > n * m)) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}