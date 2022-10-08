
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

const int N = 105;
int t, n, m, x, y;
string s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m >> x >> y;
        y = min(y, 2 * x);
        ll cost = 0;
        rep(i, 0, n) {
            cin >> s[i];
            int j = 0;
            while(j < m) {
                if(s[i][j] == '.') {
                    if(j == m - 1 || s[i][j + 1] == '*') {
                        cost += x;
                    }else {
                        cost += y;
                        j++;
                    }
                }
                j++;
            }
        }
        cout << cost << '\n';
    }
}