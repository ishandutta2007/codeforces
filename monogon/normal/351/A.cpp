
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

const int N = 2005;
int n;
double a;
vector<double> v;

// difference when rounding
// a[i] when floor
// - (1 - a[i]) when ceil
// always 0 when integer

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int ints = 0;
    double dif = 0;
    rep(i, 0, 2 * n) {
        cin >> a;
        a -= floor(a);
        if(a < 1e-6) {
            ints++;
        }else {
            v.push_back(a);
            dif += a;
        }
    }
    dif -= n;
    double ans = abs(dif);
    sort(all(v));
    rep(i, 0, min(ints, n)) {
        dif++;
        ans = min(ans, abs(dif));
    }
    cout << fixed << setprecision(3);
    cout << ans << endl;
}