
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

// 2 * 3, 2 * 5, 2 * 7
// 6 + 10 + 14

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        ll n;
        cin >> n;
        if(n < 6 + 10 + 14 + 1) {
            cout << "NO\n";
        }else {
            n -= 6 + 10 + 14;
            if(n == 6 || n == 10 || n == 14) {
                cout << "YES\n6 10 15 " << n-1 << '\n';
            }else {
                cout << "YES\n6 10 14 " << n << '\n';
            }
        }
    }
}