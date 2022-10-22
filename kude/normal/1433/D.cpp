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
        VI a(n);
        rep(i, n) cin >> a[i];
        bool ok = false;
        int s, t;
        rep(i, n-1) if (a[i] != a[i+1]) {
            ok = true;
            s = i;
            t = i + 1;
            break;
        }
        if (!ok) cout << "NO\n";
        else {
            cout << "YES\n";
            printf("%d %d\n", s + 1, t + 1);
            rep(i, n) {
                if (i == s || i == t) continue;
                if (a[i] != a[s]) printf("%d %d\n", i + 1, s + 1);
                else printf("%d %d\n", i + 1, t + 1);
            }
        }
    }
}