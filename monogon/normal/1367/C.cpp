
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

const int N = 2e5 + 5;
int t, n, k, d[N];
bool f[N];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k >> s;
        fill(f, f + n, true);
        int j = -N;
        rep(i, 0, n) {
            if(s[i] == '1') {
                j = i;
            }
            if(j >= i - k) f[i] = false;
        }
        j = 2 * N;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '1') {
                j = i;
            }
            if(j <= i + k) f[i] = false;
        }
        int ans = 0;
        rep(i, 0, n) {
            if(f[i]) {
                i += k;
                ans++;
            }
        }
        cout << ans << '\n';
    }
}