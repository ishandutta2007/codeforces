#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 200005, INF = 1E9 + 7;
const long double EPS = 1E-10;

int n, b, k;
long long cur = 0;
int ans = 0;

struct fraction : pair<int, int> {
    fraction(int _x, int _y) {
        int g = __gcd(_x, _y);
        fi = _x / g; se = _y / g;
        if (se < 0) {
            fi = -fi;
            se = -se;
        }
    }
};
vector<pair<fraction, int>> ve;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k >> b;
        if (k == 0) {
            continue;
        }
        fraction tmp = fraction(-b, k);
        if (k < 0) {
            ve.push_back({fraction(-b, k), -k});
        } else {
            ve.push_back({fraction(-b, k), k});
        }
    }
    sort(ve.begin(), ve.end());
    ve.push_back({fraction(INF, 1), 0});
    for (int i = 0; i < ve.size() - 1; i++) {
        cur += ve[i].se;
        if (ve[i].fi != ve[i + 1].fi) {
            ans += (cur != 0);
            cur = 0;
        }
    }
    cout << ans;
}