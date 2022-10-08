
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

// k = 0 0000 11111
// y = 0 0000 11001
// x = 0 0001 11000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, k;
    cin >> a >> b >> k;
    int n = a + b;
    if(k == n) {
        cout << "No\n";
        return 0;
    }
    string x(n, '0'), y(n, '0');
    x[0] = '1';
    y[0] = '1';
    if(b == 1 || a == 0) {
        if(k == 0) {
            if(a == 0) {
                fill(all(x), '1');
                fill(all(y), '1');
            }
            cout << "Yes\n" << x << '\n' << y << '\n';
        }else {
            cout << "No\n";
        }
        return 0;
    }
    if(k == n - 1) {
        cout << "No\n";
        return 0;
    }
    b -= 2;
    x[n - k - 1] = '1';
    y[n - 1] = '1';
    rep(i, 1, n - 1) {
        if(b > 0 && i != n - k - 1) {
            x[i] = '1';
            y[i] = '1';
            b--;
        }
    }
    cout << "Yes\n" << x << '\n' << y << '\n';
}