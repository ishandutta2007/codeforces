#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 3005;
const int Maxc = 10005;

int n;
vector <ii> bycost[Maxc];
int x[Maxn];
int par[Maxn], siz[Maxn], has[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; has[a] += has[b]; par[b] = a;
}

bool Check(int mx)
{
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        siz[i] = 1;
        has[i] = x[i];
    }
    for (int i = 0; i < mx; i++)
        for (int j = 0; j < bycost[i].size(); j++) {
            auto p = bycost[i][j];
            unionSet(p.first, p.second);
        }
    int sumf = 0, sums = 0;
    vector <ii> seq;
    for (int i = 1; i <= n; i++) if (getPar(i) == i) {
        seq.push_back(ii(siz[i], has[i]));
        sumf += siz[i]; sums += has[i];
    }
    for (int i = 0; i < seq.size(); i++) {
        int f = sumf - seq[i].first, s = sums - seq[i].second;
        if (seq[i].first + max(0, f - seq[i].second) > s)
            return false;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        bycost[c].push_back(ii(a, b));
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &x[i]);
    int lef = 1, rig = Maxc - 1;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Check(mid)) lef = mid + 1;
        else rig = mid - 1;
    }
    printf("%d\n", rig);
    return 0;
}