#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    VVI a(n);
    a[0].push_back(0);
    for(int i = 1; i < n; ++i) {
        cout << "XOR " << 0 + 1 << ' ' << i + 1 << endl;
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    VI ans(n);
    bool found = false;
    rep(i, n) {
        if (a[i].size() >= 2) {
            cout << "AND " << a[i][0] + 1 << ' ' << a[i][1] + 1 << endl;
            int x;
            cin >> x;
            ans[0] = x ^ i;
            found = true;
            break;
        }
    }
    if (!found) {
        // all distinct
        int k = a[1][0];
        cout << "AND " << 0 + 1 << ' ' << k + 1 << endl;
        int x;
        cin >> x;
        cout << "AND " << 0 + 1 << ' ' << a[2][0] + 1 << endl;
        int y;
        cin >> y;
        ans[0] = ((n - 1) - 1) & x | y & 1;
    }

    rep(xi, n) for(int j: a[xi]) {
        ans[j] = ans[0] ^ xi;
    }
    cout << "!";
    rep(i, n) cout << " " << ans[i];
    cout << endl;
    return 0;
}