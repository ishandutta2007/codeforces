#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;

const int N = 1e5 + 5;

set<int> s;

int n, p, hh, tt;

LL ans[N];

PII t[N], q[N];

int main() {
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++) scanf("%lld", &t[i].fi), t[i].se = i;
    sort(t + 1, t + 1 + n);
    LL T = t[1].fi;
    q[0] = mp(t[1].fi, t[1].se);
    for (int i = 1, j = 2; i <= n; i++) {
        while (j <= n && t[j].fi <= T + p) {
            if (t[j].fi < T + p && t[j].se < q[tt].se) q[++tt] = t[j];
            else s.insert(t[j].se);
            j++;
        }
        //cout << q[hh].se << " " << q[hh].fi << " qwq\n";
        ans[q[hh].se] = T + p;
        T += p;
        hh++;
        
        if (!s.size() && hh > tt) {
            T = t[j].fi;
            q[++tt] = t[j];
            j++;
        }
        
        if (s.size() && (hh > tt || *s.begin() < q[tt].se)) {
            int k = *s.begin();
            s.erase(k);
            //cout << " ins " << k << " " << T << endl;
            q[++tt] = mp(T, k);
        }
    }
    for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
    return 0;
}