
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

int t, n, m, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m >> a >> b;
        if(a * n != b * m) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int d = 0;
        rep(i, 0, n) {
            string s(m, '0');
            rep(j, 0, a) {
                s[(d + j) % m] = '1';
            }
            cout << s << '\n';
            d = (d + a) % m;
        }
    }
}