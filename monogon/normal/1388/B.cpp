
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
        int k = (n + 3) / 4;
        rep(i, 0, n - k) {
            cout << 9;
        }
        // if(n % 4 != 0) {
        //     cout << 8;
        //     k--;
        // }
        rep(i, 0, k) cout << 8;
        cout << '\n';
    }
}