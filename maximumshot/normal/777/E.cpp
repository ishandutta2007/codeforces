#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

struct ring {
    int a, b;
    ll h;
    ring() : a(0), b(0), h(0) { }
    bool operator < (ring const & x) const {
        return make_tuple( -b, a, h ) <
               make_tuple( -x.b, x.a, x.h );
    }
};

int main() {

    int n;

    cin >> n;

    vec< ring > a(n);

    for(int i = 0;i < n;i++) {
        cin >> a[i].a >> a[i].b >> a[i].h;
    }

    sort(ALL(a));

    vec< ring > b;

    for(int i = 0;i < n;i++) {
        int j = i;
        ring x;
        x.a = a[i].a;
        while(j < n && a[i].b == a[j].b) {
            x.a = min(x. a, a[j].a);
            x.h += a[j].h;
            j++;
        }
        j--;
        x.b = a[i].b;
        b.push_back(x);
        i = j;
    }

    sort(ALL(b));
    n = (int)b.size();

    int sz;

    {
        vec< int > crd;
        for(int i = 0;i < n;i++) {
            crd.push_back(b[i].b);
            crd.push_back(b[i].a);
        }
        sort(ALL(crd));
        crd.resize(sz = unique(ALL(crd)) - crd.begin());
        for(int i = 0;i < n;i++) {
            b[i].b = lower_bound(ALL(crd), b[i].b) - crd.begin();
            b[i].a = lower_bound(ALL(crd), b[i].a) - crd.begin();
        }
    }

    vec< ll > fen(sz);

    vec< ll > dp(n);
    ll res = 0;

    for(int i = 0;i < n;i++) {
        dp[i] = 0;
        for(int cur = b[i].b - 1;cur >= 0;cur = (cur & (cur + 1)) - 1) {
            dp[i] = max(dp[i], fen[cur]);
        }
        dp[i] += b[i].h;
        for(int cur = b[i].a;cur < sz;cur |= (cur + 1)) {
            fen[cur] = max(fen[cur], dp[i]);
        }
        res = max(res, dp[i]);
    }

    cout << res << "\n";

    return 0;
}