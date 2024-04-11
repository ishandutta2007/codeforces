#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int gcd(int x, int y) {
    return !x ? y : gcd(y % x, x);
}

struct pt {
    int x = 0;
    int y = 0;

    pt operator - (const pt& o) const {
        return {x - o.x, y - o.y};
    }

    pt mod2() const {
        return {(x % 2 + 2) % 2, (y % 2 + 2) % 2};
    }

    int on() const {
//        return gcd(abs(x), abs(y));
        if (x % 4 == 0 && y % 4 == 0)
            return 0;
        else
            return 2;
    }
};

int get_on(int x, int y) {
    return x % 4 == 0 && y % 4 == 0 ? 0 : 2;
}

ll fast(int n, vector<pt> ps) {
    ll res = 0;
    vector<vector<int>> cnt(4, vector<int>(4));
    for (auto& p : ps) {
        p.x = (p.x % 4 + 4) % 4;
        p.y = (p.y % 4 + 4) % 4;
        cnt[p.x][p.y]++;
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < i; j++) {
//            for (int k = 0; k < j; k++) {
//                pt u = (ps[j] - ps[i]);
//                pt v = (ps[j] - ps[k]);
//                int area = ((1ll * u.x * v.y + 1ll * u.x * v.y) % 4);
//                area = (area % 4 + 4) % 4;
//                int on = (ps[i] - ps[j]).on() + (ps[j] - ps[k]).on() + (ps[k] - ps[i]).on();
//                int tmp = (area + 2 - on) % 4;
//                tmp = (tmp % 4 + 4) % 4;
//                if (tmp % 4 == 2)
//                    res++;
//            }
//        }
//    }

    vector<pii> PS;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            PS.emplace_back(x, y);
        }
    }

    for (int i = 0; i < (int) PS.size(); i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= j; k++) {
                auto [x1, y1] = PS[i];
                auto [x2, y2] = PS[j];
                auto [x3, y3] = PS[k];

                ll S1 = cnt[x1][y1];
                ll S2 = cnt[x2][y2];
                ll S3 = cnt[x3][y3];

                if (S1 == 0 || S2 == 0 || S3 == 0)
                    continue;

                int ux = ((x1 - x2) % 4 + 4) % 4;
                int uy = ((y1 - y2) % 4 + 4) % 4;

                int vx = ((x1 - x3) % 4 + 4) % 4;
                int vy = ((y1 - y3) % 4 + 4) % 4;

                int area = (ux * vy - vx * uy) % 4;
                area = (area % 4 + 4) % 4;

                int on = (get_on(x1 - x2, y1 - y2) + get_on(x2 - x3, y2 - y3) + get_on(x3 - x1, y3 - y1)) % 4;
                int tmp = ((area + 2 - on) % 4 + 4) % 4;
                if (tmp % 4 == 2) {
//                    cout << "WOW " << S1 << " " << S2 << " " << S3 << " " << i << " " << j << " " << k << "\n";
                    ll coef = 0;
                    if (i > j && j > k) {
                        coef = 1ll * S1 * S2 * S3;
                    } else if (i > j && j == k) {
                        coef = S1 * S2 * (S2 - 1) / 2;
                    } else if (i == j && j > k) {
                        coef = S1 * (S1 - 1) / 2 * S3;
                    } else if (i == j && j == k) {
                        coef = S1 * (S1 - 1) * (S1 - 2) / 6;
                    }
                    res += coef;
                }
            }
        }
    }

    return res;
}

void work() {
    int n;
    cin >> n;
    vector<pt> ps(n);
    for (int i = 0; i < n; i++)
        cin >> ps[i].x >> ps[i].y;
    ll res = fast(n, ps);
    cout << res << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}