#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long double ld;
typedef pair <ld, ld> ldld;
typedef long long ll;

const int lim = 1000000;

int n, s;
vector <ii> my[2];

ldld Get(const vector <ii> &seq, ld f)
{
    ld mx = -1, mn = lim + 1;
    for (int i = 0; i < seq.size(); i++) {
        ld xi = seq[i].first;
        ld vi = seq[i].second;
        if (xi / vi <= f) return ldld(0.0l, lim);
        ld X = (xi * vi + s * xi - f * vi * (vi + s)) / s;
        if (X > xi) continue;
        ld hastim = (xi - X) / vi;
        ld st = (s - vi) * hastim + xi;
        if (st < xi) continue;
        mn = min(mn, xi);
        if (st >= lim) mx = max(mx, ld(lim));
        else mx = max(mx, st);
    }
    return ldld(mn, mx);
}

int main()
{
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        int x, v, t; scanf("%d %d %d", &x, &v, &t);
        if (t == 1) my[0].push_back(ii(x, v));
        else my[1].push_back(ii(lim - x, v));
    }
    ld lef = 0, rig = lim;
    for (int i = 0; i < 100; i++) {
        ld mid = (lef + rig) / 2.0l;
        ldld fromlef = Get(my[0], mid);
        ldld fromrig = Get(my[1], mid);
        ld L = max(fromlef.first, ld(lim) - fromrig.second);
        ld R = min(fromlef.second, ld(lim) - fromrig.first);
        if (L <= R && L <= ll(R)) rig = mid;
        else lef = mid;
    }
    cout << fixed << setprecision(13) << rig << endl;
    return 0;
}