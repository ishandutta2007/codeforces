#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int Maxn = 2005;
 
struct vec {
    int x, y;
    vec() {}
    vec(int x, int y): x(x), y(y) {}
    bool Less(const vec &oth) const {
        return ll(x) * oth.y < ll(oth.x) * y;
    }
    bool Equal(const vec &oth) const {
        return ll(x) * oth.y == ll(oth.x) * y;
    }
};
 
struct ev {
    vec v;
    bool st;
    int a, b;
    ev() {}
    ev(vec v, bool st, int a, int b): v(v), st(st), a(a), b(b) {}
    bool operator<(const ev &oth) const {
        if (!v.Equal(oth.v)) return v.Less(oth.v);
        return st < oth.st;
    }
};
 
int n;
int xl[Maxn], xr[Maxn], y[Maxn];
int p[Maxn];
int inp[Maxn];
vector <ev> E;
vec glob;
ld res = 1e100l;
 
bool LessIn(const int &a, const int &b)
{
    if (y[a] != y[b]) return y[a] > y[b];
    return xl[a] < xl[b];
}
 
ld getCur(const vec &V)
{
    int ind1 = p[0];
    ld lef = xl[ind1] + y[ind1] * ld(V.x) / ld(V.y);
    int ind2 = p[n - 1];
    ld rig = xr[ind2] + y[ind2] * ld(V.x) / ld(V.y);
    return rig - lef;
}

bool LessGlob(const int &a, const int &b)
{
    ld A = xl[a] + y[a] * ld(glob.x) / ld(glob.y);
    ld B = xl[b] + y[b] * ld(glob.x) / ld(glob.y);
    return A < B;
}
 
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &xl[i], &xr[i], &y[i]);
        p[i] = i;
    }
    sort(p, p + n, LessIn);
    for (int i = 0; i < n; i++)
        inp[p[i]] = i;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) if (y[i] > y[j]) {
            vec v1 = vec(xl[j] - xr[i], y[i] - y[j]);
            vec v2 = vec(xr[j] - xl[i], y[i] - y[j]);
            E.push_back(ev(v1, true, i, j));
            E.push_back(ev(v2, false, i, j));
        }
    if (E.empty()) {
        printf("%d.0000000000\n", xr[p[n - 1]] - xl[p[0]]);
        return 0;
    }
    sort(E.begin(), E.end());
    vector <int> un;
    int cur = 0;
    for (int i = 0; i < E.size(); i++)
        if (E[i].st) {
            if (cur == 0) res = min(res, getCur(E[i].v));
            cur++;
            un.push_back(inp[E[i].a]);
            un.push_back(inp[E[i].b]);
        } else {
            cur--;
            if (cur == 0) {
                sort(un.begin(), un.end());
                un.erase(unique(un.begin(), un.end()), un.end());
                glob = E[i].v;
                for (int l = 0, r; l < un.size(); l = r) {
                    r = l;
                    while (r < un.size() && un[r] - un[l] == r - l)
                        r++;
                    sort(p + un[l], p + un[r - 1] + 1, LessGlob);
                    for (int z = un[l]; z <= un[r - 1]; z++)
                        inp[p[z]] = z;
                }
                res = min(res, getCur(E[i].v));
                un.clear();
            }
        }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}