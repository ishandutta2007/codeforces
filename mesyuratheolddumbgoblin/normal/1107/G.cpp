#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define MOD 1000000007
#define pii pair<ll, ll>
#define INF ((ll)1e+18)
typedef long long ll;
int Abs(int x) {
    return x>0?x:-x;
}

ll n, k,a[300500], b[300500];

struct hyu {
    ll maxim;
    ll minim;
    ll sum;
};
bool operator<(const hyu& x, const hyu& y) {
    return mp(x.maxim, mp(x.minim, x.sum)) < mp(y.maxim, mp(y.minim, y.sum));
}
set<pair<pii, pii> > f;
vector<pii> g;
int main() {
    //freopen("input.txt", "r", stdin);
    /*ll sum = 0;
    for (int i = 0; i < 100; i++)
    for (int j = i; j < 100; j++) {
        for (int k = 0; k < (j-i+1); k++)
            sum += (j-i+1)*(j-i)/2;
    }
    cout << sum << endl;*/
    ll ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[i] = x;
        b[i] = k-y;
        ans = max(ans, b[i]);
        f.insert(mp(mp(i, b[i]), mp(min(0LL, b[i]), max(0LL, b[i]))));
        if (i > 0) {
            g.push_back(mp(a[i]-a[i-1], i-1));
        }
    }

    sort(g.begin(), g.end());
    for (int i = 0; i < g.size(); i++) {
        ll bad = g[i].X * g[i].X;
        ll pos = g[i].Y;
        auto it = f.upper_bound(mp(mp(pos, INF), mp(INF, INF)));
        auto y = (*it);
        auto x = *(prev(it));
        pair<pii, pii> new_magic;
        new_magic.X.X = x.X.X;
        new_magic.X.Y = x.X.Y + y.X.Y;
        new_magic.Y.X = min(x.Y.X, y.Y.X + x.X.Y);
        new_magic.Y.Y = max(x.Y.Y, y.Y.Y + x.X.Y);
        ans = max(ans, y.Y.Y + x.X.Y - x.Y.X - bad);
        f.erase(x);
        f.erase(y);
        f.insert(new_magic);
    }
    cout << ans << endl;

    return 0;
}