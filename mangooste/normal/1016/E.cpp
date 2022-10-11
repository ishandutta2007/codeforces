#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cout << fixed << setprecision(10);

    int sy, a, b;
    cin >> sy >> a >> b;
    sy = -sy;
    int n;
    cin >> n;
    vec<pr<int>> segs(n);
    for (auto &[x, y] : segs)
        cin >> y >> x;
    sort(all(segs));
    vec<ll> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + segs[i].first - segs[i].second;
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        auto get = [&](int k) {
            return (k - x) * double(y) / (sy + y);
        };
        double x1 = x + get(a);
        double x2 = x + get(b);
        auto find = [&](double x) {
            return int(upper_bound(all(segs), pr<int>{ceil(x + 1e-6), -1}) - segs.begin());
        };
        int i1 = find(x1);
        int i2 = find(x2);
        double sum = 0;
        if (i2 != i1) {
            sum += pref[i2] - pref[i1 + 1];
            if (i1 != -1)
                sum += min<double>(segs[i1].first - segs[i1].second, segs[i1].first - x1);
            if (i2 != n)
                sum += max<double>(0, x2 - segs[i2].second);
        } else {
            int i = i2;
            if (i != -1 && i != n)
                sum += max<double>(0, min<double>(segs[i].first, x2) - max<double>(segs[i].second, x1));
        }
        cout << sum * (sy + y) / y << '\n';
    }
}