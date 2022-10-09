
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
    // 2020 x + 2021 y = 2020 k + y, y <= k
    int te;
    cin >> te;
    while(te--) {
        ll n;
        cin >> n;
        bool awesomesauce = false;
        rep(k, 0, n / 2020 + 1) {
            ll y = n - 2020 * k;
            if(0 <= y && y <= k) {
                awesomesauce = true;
            }
        }
        cout << (awesomesauce ? "YES" : "NO") << "\n";
    }
}