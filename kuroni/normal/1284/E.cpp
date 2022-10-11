#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 2505;

int n;
long long ans;

struct point {
    int x, y;

    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    bool upper() const {
        return y > 0 || (y == 0 && x > 0);
    }

    bool operator<(const point &oth) const {
        if (upper() != oth.upper()) {
            return upper();
        } else {
            return 1LL * x * oth.y - 1LL * y * oth.x > 0;
        }
    }
} a[N];
vector<pair<point, int>> ve;

long long solve(int u) {
    ve.clear();
    long long ans = 1LL * (n - 1) * (n - 2) * (n - 3) / 6;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (u != i) {
            int x = a[i].x - a[u].x, y = a[i].y - a[u].y;
            ve.push_back({point(x, y), 1});
            ve.push_back({point(-x, -y), 0});
            cnt += point(x, y).upper();
        }
    }
    sort(ve.begin(), ve.end());
    for (pair<point, int> &v : ve) {
        if (v.se == 1) {
            cnt--;
            ans -= 1LL * cnt * (cnt - 1) / 2;
        } else {
            cnt++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    // solve(1);
    for (int i = 1; i <= n; i++) {
        ans += solve(i);
    }
    cout << ans * (n - 4) / 2 << '\n';
}