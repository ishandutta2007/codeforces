#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

vector<int> l, r;
ll n, len, wmax;

ld maxx(int i, int j) {
    return 0.5 * ((len + l[i]) * (wmax + 1) - r[j] * (wmax - 1));
}

ll solve() {
    ll ans = 0;
    for (int i = 0; i < l.size(); ++i) {
        if (l[i] + len > 0) {
            int maxr = min(l[i], 0);
            ans += lower_bound(r.begin(), r.end(), maxr) - r.begin();
            /*for (int j = 0; j < r.size(); ++j) {
                if (r[j] >= maxr) break;
                ++ans;
            }*/
        }
    }
    //cout << ans << endl;
    for (int i = 0; i < l.size(); ++i) {
        if (l[i] + len <= 0) {
            if (r[0] > l[i] || maxx(i, 0) <= 0) continue;
            int lb = 0, rb = r.size();
            while (lb + 1 < rb) {
                int mid = (lb + rb) / 2;
                if (r[mid] > l[i] || maxx(i, mid) <= 0) rb = mid;
                else lb = mid;
            }
            ans += lb + 1;
            /*for (int j = 0; j < r.size(); ++j) {
                ld maxx = 0.5 * ((len + l[i]) * (wmax + 1) - r[j] * (wmax - 1));
                if (maxx <= 0) break;
                ++ans;
            }*/
        }
    }
    vector<int> l1, r1;
    for (int i = 0; i < l.size(); ++i) {
        r1.PB(-l[i] - len);
    }
    for (int i = 0; i < r.size(); ++i) {
        l1.PB(-r[i] - len);
    }
    l = l1;
    r = r1;
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    for (int i = 0; i < l.size(); ++i) {
        if (l[i] + len <= 0) {
            if (r[0] > l[i] || maxx(i, 0) <= 0) continue;
            int lb = 0, rb = r.size();
            while (lb + 1 < rb) {
                int mid = (lb + rb) / 2;
                if (r[mid] > l[i] || maxx(i, mid) <= 0) rb = mid;
                else lb = mid;
            }
            ans += lb + 1;
            /*for (int j = 0; j < r.size(); ++j) {
                ld maxx = 0.5 * ((len + l[i]) * (wmax + 1) - r[j] * (wmax - 1));
                if (maxx <= 0) break;
                ++ans;
            }*/
        }
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> len >> wmax;
    for (int i = 0; i < n; ++i) {
        int x, d;
        cin >> x >> d;
        if (d == -1) {
            l.PB(x);
        } else {
            r.PB(x);
        }
    }
    if (l.size() == 0 || r.size() == 0) {
        cout << 0;
        return 0;
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    ll cnt = solve();
    cout << cnt << endl;

    return 0;
}