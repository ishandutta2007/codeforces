#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

typedef long long ll;
typedef long double ld;

const int maxn = 100100;
const ld PI = acos(-1.0);

int _x0, _y0, v, T, n;
ll D;
int px[maxn], py[maxn], pr[maxn];
pair<ld, int> ar[2 * maxn]; int sze;
int cnt;

ld dist(int i) {
    return sqrt(ll(px[i]) * px[i] + ll(py[i]) * py[i]);
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> _x0 >> _y0 >> v >> T;
    D = ld(T) * v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> px[i] >> py[i] >> pr[i];
        px[i] -= _x0, py[i] -= _y0;
        if (ll(pr[i]) * pr[i] >= ll(px[i]) * px[i] + ll(py[i]) * py[i]) {
            cout << "1\n";
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        ld theta = atan2(py[i], px[i]);
        ld d = dist(i);
        if (pr[i] + D < d) continue;
        ld dtheta;
        if (D >= d) dtheta = asin(ld(pr[i]) / d);
        else {
            dtheta = acos((d * d + D * D - ll(pr[i]) * pr[i]) / (2 * d * D));
            if (sqrt(d * d - ll(pr[i]) * pr[i]) <= D) {
                ld x = asin(ld(pr[i]) / d);
                if (dtheta < x) dtheta = x;
            }
        }

        //cout << acos((d * d + D * D - ll(pr[i]) * pr[i]) / (2 * d * D)) << endl;
        ld l = theta - dtheta, r = theta + dtheta;
        if (l < 0) l += 2 * PI, r += 2 * PI;
        assert(l >= -1e-9);

        //cout << l << ' ' << r << endl;

        if (r <= 2 * PI) {
            ar[sze++] = MP(l, 1);
            ar[sze++] = MP(r, -1);
        } else {
            ar[sze++] = MP(l, 1);
            ar[sze++] = MP(r - 2 * PI, -1);
            cnt++;
        }
    }

    sort(ar, ar + sze);
    ld ans = 0;
    for (int i = 0; i < sze; i++) {
        if (cnt > 0) ans += i ? ar[i].A - ar[i - 1].A : ar[i].A;
        cnt += ar[i].B;
    }

    if (cnt > 0) ans += 2 * PI - ar[sze - 1].A;

    cout << fixed << setprecision(10) << ans / (2 * PI) << '\n';
}