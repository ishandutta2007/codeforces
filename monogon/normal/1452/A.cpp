
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
        int x, y;
        cin >> x >> y;
        // if(x < y) swap(x, y);
        // x -= y;
        // int ops = 2 * y;
        // if(x % 2 == 0) {
        //     ops += 2 * x;
        // }else {
        //     ops += 2 * (x - 1) + 1;
        // }
        // cout << ops << '\n';
        cout << max({2 * x - 1, 2 * y - 1, x + y}) << '\n';
    }
}