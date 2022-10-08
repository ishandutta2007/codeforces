
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

const int N = 105;
int t, n, m;
string s[N];
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        rep(i, 0, n) {
            cin >> s[i];
            a[i] = 0;
            rep(j, 0, m) {
                a[i] = 2 * a[i] + (s[i][j] - '0');
            }
        }
        sort(a, a + n);
        ll k = ((1LL << m) - n - 1) / 2;
        ll L = 0, R = (1LL << m) - 1;
        while(L < R) {
            ll m = L + (R - L) / 2;
            ll idx = m - (lower_bound(a, a + n, m) - a);
            if(idx >= k) {
                R = m;
            }else {
                L = m + 1;
            }
        }
        while(binary_search(a, a + n, L)) L++;
        string ans = "";
        rep(i, 0, m) {
            ans.push_back('0' + ((L >> i) & 1));
        }
        reverse(all(ans));
        cout << ans << '\n';
    }
}