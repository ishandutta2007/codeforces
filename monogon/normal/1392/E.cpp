
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
    int n;
    cin >> n;
    rep(i, 0, n) {
        rep(j, 0, n) {
            if(j % 2 == 0) cout << "0 ";
            else cout << (1LL << (i + j - 1)) << ' ';
        }
        cout << endl;
    }
    int q;
    cin >> q;
    rep(i, 0, q) {
        ll k;
        cin >> k;
        int x = 0, y = 0;
        cout << "1 1" << '\n';
        rep(i, 0, 2 * n - 2) {
            if(((k >> i) & 1) ^ (x % 2 == 1)) {
                x++;
            }else {
                y++;
            }
            cout << y+1 << ' ' << x+1 << '\n';
        }
        cout << flush;
    }
}