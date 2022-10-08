
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

const int N = 55, X = 1e5 + 5;
int n, x, l, r;
int b[2 * X];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    int mx = 0;
    rep(i, 0, n) {
        cin >> l >> r;
        rep(j, l, r + 1) {
            b[j] = 1;
        }
        mx = max(mx, r);
    }
    int i = 1;
    int cost = mx;
    while(i <= mx) {
        int j = i;
        while(j <= mx && b[j] == 0) j++;
        cost -= ((j - i) / x) * x;
        i = j + 1;
    }
    cout << cost << '\n';
}