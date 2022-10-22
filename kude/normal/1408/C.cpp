#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n-1); i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, l;
        cin >> n >> l;
        VI a(n);
        rep(i, n) cin >> a[i];
        double ng = 0, ok = l;
        rrep(_, 200) {
            double mid = (ng + ok) / 2;
            double x = 0;
            int dx = 1;
            double t = mid;
            rep(i, n) {
                double d = (a[i] - x) / dx;
                if (d <= t) {
                    t -= d;
                    x = a[i];
                    ++dx;
                } else break;
            }
            x += t * dx;

            double y = l;
            int dy = 1;
            t = mid;
            rrep(i, n) {
                double d = (y - a[i]) / dy;
                if (d <= t) {
                    t -= d;
                    y = a[i];
                    ++dy;
                } else break;
            }
            y -= t * dy;

            if (y <= x) ok = mid;
            else ng = mid;
        }
        printf("%.8f\n", ok);
    }
}