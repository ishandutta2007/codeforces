#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        VI a(n), b(n), c(n), p(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        rep(i, n) cin >> c[i];
        p[0] = a[0];
        for(int i = 1; i < n-1; i++) {
            if (a[i] != p[i-1]) p[i] = a[i];
            else if (b[i] != p[i-1]) p[i] = b[i];
            else p[i] = c[i];
        }
        if (a[n-1] != p[0] && a[n-1] != p[n-2]) p[n-1] = a[n-1];
        else if (b[n-1] != p[0] && b[n-1] != p[n-2]) p[n-1] = b[n-1];
        else p[n-1] = c[n-1];
        rep(i, n) cout << p[i] << " \n"[i == n-1];
    }
}