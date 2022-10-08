
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
        int a, b, c;
        cin >> a >> b >> c;
        int n = 2 * abs(a - b);
        if(c > n || (a - 1 + n / 2) % n + 1 != b || (b - 1 + n / 2) % n + 1 != a) {
            cout << -1 << '\n';
        }else {
            cout << (c - 1 + n / 2) % n + 1 << '\n';
        }
    }
}