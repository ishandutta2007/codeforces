
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

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    bool flag = false;
    pii p = {1e9, 1e9};
    rep(i, 0, n / 4 + 5) {
        // 4 * i + 7 * j
        int j = max(0, (n - 4 * i) / 7);
        if(n == 4 * i + 7 * j) {
            flag = true;
            if(i + j < p.first + p.second || (i + j == p.first + p.second && i > p.first)) {
                p = {i, j};
            }
        }
    }
    if(flag) {
        rep(i, 0, p.first) cout << '4';
        rep(i, 0, p.second) cout << '7';
        cout << '\n';
    }else {
        cout << "-1\n";
    }
}