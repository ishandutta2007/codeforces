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
        int n;
        cin >> n;
        ll sum = 0;
        rep(i, 0, n) {
            ll a;
            cin >> a;
            if(a <= 2048) {
                sum += a;
            }
        }
        cout << (sum >= 2048 ? "YES" : "NO") << '\n';
    }
}