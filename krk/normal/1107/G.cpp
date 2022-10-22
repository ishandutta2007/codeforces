#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 300005;

int n, a;
int d[Maxn], c[Maxn];
ll S[Maxn];
vector <ii> seq;
int par[Maxn], siz[Maxn];
ll mx[Maxn], mn[Maxn];
ll res;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    mx[a] = max(mx[a], mx[b]);
    mn[a] = min(mn[a], mn[b]);
}

int main()
{
    scanf("%d %d", &n, &a);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &d[i], &c[i]);
        c[i] = a - c[i];
        S[i] = S[i - 1] + c[i];
        if (i > 1) seq.push_back(ii(d[i] - d[i - 1], i));
        par[i] = i; siz[i] = 1;
        mx[i] = S[i]; mn[i] = S[i - 1];
        res = max(res, ll(c[i]));
    }
    sort(seq.begin(), seq.end());
    for (int i = 0; i < seq.size(); i++) {
        ll cost = ll(seq[i].first) * seq[i].first;
        int ind = seq[i].second;
        res = max(res, mx[getPar(ind)] - mn[getPar(ind - 1)] - cost);
        unionSet(ind - 1, ind);
    }
    cout << res << endl;
    return 0;
}