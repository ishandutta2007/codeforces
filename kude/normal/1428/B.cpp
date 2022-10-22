#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool cok = true, acok = true;
        rep(i, n) if (s[i] == '<') cok = false;
        rep(i, n) if (s[i] == '>') acok = false;
        if (cok || acok) {
            cout << n << '\n';
            continue;
        }
        int ans = 0;
        rep(i, n) {
            int u = (n + i - 1) % n, v = i;
            ans += s[u] == '-' || s[v] == '-';
        }
        cout << ans << '\n';
    }
}