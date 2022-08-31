#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

vector<int> x, y, z;

void clr() {
    x.clear();
    y.clear();
    z.clear();
}

inline ll sqr(ll a) {
    return a * a;
}

ll dif(ll a, ll b, ll c) {
    return sqr(b - a) + sqr(c - b) + sqr(c - a);
}

ll solve(const vector<int>& x, const vector<int>& y, const vector<int>& z) {
    ll ans = dif(x[0], y[0], z[0]);
    int px = 0, pz = 0;
    for (int i = 0; i < y.size(); ++i) {
        while(px + 1 < x.size() && x[px + 1] <= y[i]) {
            ++px;
        }
        while(pz + 1 < z.size() && z[pz] < y[i]) {
            ++pz;
        }
        ans = min(ans, dif(x[px], y[i], z[pz]));
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int cx, cy, cz;
        clr();
        scanf("%d%d%d", &cx, &cy, &cz);
        for (int i = 0; i < cx; ++i) {
            int a;
            scanf("%d", &a);
            x.PB(a);
        }
        for (int i = 0; i < cy; ++i) {
            int a;
            scanf("%d", &a);
            y.PB(a);
        }
        for (int i = 0; i < cz; ++i) {
            int a;
            scanf("%d", &a);
            z.PB(a);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        sort(z.begin(), z.end());
        ll ans =       solve(y, x, z);
        ans = min(ans, solve(z, x, y));
        ans = min(ans, solve(x, y, z));
        ans = min(ans, solve(z, y, x));
        ans = min(ans, solve(x, z, y));
        ans = min(ans, solve(y, z, x));
        cout << ans << endl;
    }
    return 0;
}