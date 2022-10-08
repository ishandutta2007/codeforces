
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

const int N = 55;
int t, n;
string s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        rep(i, 0, n) {
            cin >> s[i];
        }
        bool flag = true;
        rep(i, 0, n - 1) rep(j, 0, n - 1) {
            if(s[i][j] == '1' && s[i + 1][j] == '0' && s[i][j + 1] == '0') {
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
}