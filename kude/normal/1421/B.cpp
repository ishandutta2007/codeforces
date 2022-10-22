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
        vector<string> s(n);
        rep(i, n) cin >> s[i];
        int a = (s[1][0] - '0') + (s[0][1] - '0');
        int b = (s[n-1][n-2] - '0') + (s[n-2][n-1] - '0');
        vector<P> ans;
        if (a == 0) {
            if (s[n-1][n-2] - '0' == 0) ans.emplace_back(n, n-1);
            if (s[n-2][n-1] - '0' == 0) ans.emplace_back(n-1, n);
        } else if (a == 1) {
            if (b == 0) {
                if (s[0][1] - '0' == 0) ans.emplace_back(1, 2);
                if (s[1][0] - '0' == 0) ans.emplace_back(2, 1);
            } else {
                if (s[0][1] - '0' == 1) ans.emplace_back(1, 2);
                if (s[1][0] - '0' == 1) ans.emplace_back(2, 1);
                if (s[n-1][n-2] - '0' == 0) ans.emplace_back(n, n-1);
                if (s[n-2][n-1] - '0' == 0) ans.emplace_back(n-1, n);
            }
        } else {
            if (s[n-1][n-2] - '0' == 1) ans.emplace_back(n, n-1);
            if (s[n-2][n-1] - '0' == 1) ans.emplace_back(n-1, n);
        }
        cout << ans.size() << endl;
        for(auto p: ans) {
            cout << p.first << ' ' << p.second << '\n';
        }
    }
}