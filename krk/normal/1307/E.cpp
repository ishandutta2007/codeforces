#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 5005;
const int mod = 1000000007;

int n, m;
int s[Maxn];
vector <int> inds[Maxn];
vector <int> vals[Maxn];
ii res;

ii Solve(int x, int forb)
{
    ii res = ii(0, 1);
    for (int i = 1; i <= n; i++) if (i != forb) {
        int one = 0, both = 0;
        for (int j = 0; j < vals[i].size(); j++) {
            int st = 0;
            if (inds[i][vals[i][j] - 1] <= x) st++;
            if (inds[i][int(inds[i].size()) - vals[i][j]] > x) st++;
            if (st == 1) one++;
            else if (st == 2) both++;
        }
        if (one == 0 && both == 0) continue;
        else if (one == 0)
            if (both == 1) { res.first++; res.second = 2ll * ll(res.second) % mod; }
            else { res.first += 2; res.second = ll(res.second) * both % mod * (both - 1) % mod; }
        else if (both == 0) { res.first++; res.second = ll(res.second) * one % mod; }
        else {
            res.first += 2;
            ll mult = (ll(one) * both + ll(both) * (both - 1)) % mod;
            res.second = ll(res.second) * mult % mod;
        }
    }
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
        inds[s[i]].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        int f, h; scanf("%d %d", &f, &h);
        if (h <= inds[f].size()) vals[f].push_back(h);
    }
    for (int i = 1; i <= n; i++)
        sort(vals[i].begin(), vals[i].end());
    res = Solve(0, -1);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < vals[i].size(); j++) {
            ii got = Solve(inds[i][vals[i][j] - 1], i);
            got.first++;
            int adds = 0;
            for (int k = 0; k < vals[i].size(); k++) if (j != k)
                if (inds[i][int(inds[i].size()) - vals[i][k]] > inds[i][vals[i][j] - 1])
                    adds++;
            if (adds > 0) { got.first++; got.second = ll(got.second) * adds % mod; }
            if (got.first > res.first) { res.first = got.first; res.second = 0; }
            if (got.first == res.first) res.second = (res.second + got.second) % mod;
        }
    printf("%d %d\n", res.first, res.second);
    return 0;
}