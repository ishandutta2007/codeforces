#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef long long ll;

const int Maxn = 52;
const int Maxm = 305;

int n, m;
vector <iii> E;
int par[Maxn], siz[Maxn];
vector <int> X;
vector <int> deltX;
vector <ll> addX;
ll res;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    return true;
}

ll Solve(ll x)
{
    x *= 2;
    int ind = upper_bound(X.begin(), X.end(), x) - X.begin() - 1;
    return (addX[ind] + ll(deltX[ind]) * x) / 2;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u, w;
        scanf("%d %d %d", &v, &u, &w);
        w *= 2;
        E.push_back(iii(w, ii(v, u)));
    }
    sort(E.begin(), E.end());
    X.push_back(0);
    for (int i = 0; i < E.size(); i++)
        for (int j = i; j < E.size(); j++)
            X.push_back((E[i].first + E[j].first) / 2);
    sort(X.begin(), X.end()); X.erase(unique(X.begin(), X.end()), X.end());
    deltX.resize(X.size(), 0);
    addX.resize(X.size(), 0ll);
    int pnt = 0;
    for (int i = 0; i < X.size(); i++) {
        while (pnt < E.size() && E[pnt].first <= X[i]) pnt++;
        for (int j = 1; j <= n; j++) {
            par[j] = j;
            siz[j] = 1;
        }
        int lef = pnt - 1, rig = pnt;
        while (lef >= 0 || rig < E.size())
            if (rig < E.size() && (lef < 0 || E[rig].first - X[i] <= X[i] - E[lef].first)) {
                if (unionSet(E[rig].second.first, E[rig].second.second)) {
                    deltX[i]--; addX[i] += E[rig].first;
                }
                rig++;
            } else {
                if (unionSet(E[lef].second.first, E[lef].second.second)) {
                    deltX[i]++; addX[i] -= E[lef].first;
                }
                lef--;
            }
        //printf("X = %d, deltX = %d, addX = %lld\n", X[i], deltX[i], addX[i]);
    }
    int p, k, a, b, c; scanf("%d %d %d %d %d", &p, &k, &a, &b, &c);
    int q;
    for (int i = 0; i < p; i++) {
        scanf("%d", &q);
    //    cout << q << ": " << Solve(q) << endl;
        res ^= Solve(q);
    }
    for (int i = p; i < k; i++) {
        q = (ll(q) * a + ll(b)) % c;
      //  cout << q << ": " << Solve(q) << endl;
        res ^= Solve(q);
    }
    cout << res << endl;
    return 0;
}