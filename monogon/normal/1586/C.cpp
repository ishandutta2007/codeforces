
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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n) {
        cin >> s[i];
    }
    vector<int> ve(m);
    rep(j, 1, m) {
        rep(i, 1, n) {
            if(s[i - 1][j] == 'X' && s[i][j - 1] == 'X') {
                ve[j] = 1;
            }
        }
        ve[j] += ve[j - 1];
    }
    int q; cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << (ve[r - 1] == ve[l - 1] ? "YES" : "NO") << '\n';
    }
}