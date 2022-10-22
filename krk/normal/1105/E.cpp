#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 42;

char tmp[Maxn];
int n, m;
map <string, int> M;
bool was[Maxm];
ll my[Maxm];
int mid, lim;
int dp[1 << 20];
int res;

int getId(const string &s)
{
    map <string, int>::iterator it = M.find(s);
    if (it == M.end()) {
        int id = M.size();
        M[s] = id;
        return id;
    }
    return it->second;
}

void writeOut()
{
    for (int j = 0; j < m; j++) if (was[j]) {
        was[j] = false;
        for (int k = j + 1; k < m; k++) if (was[k]) {
            my[j] |= 1ll << ll(k);
            my[k] |= 1ll << ll(j);
        }
    }
    fill(was, was + m, false);
}

void Gen1(int lvl, int got, ll forb)
{
    if (lvl >= mid) {
        forb >>= ll(mid);
        int ok = (((1 << lim) - 1) ^ forb);
        dp[ok] = max(dp[ok], got);
    } else {
        Gen1(lvl + 1, got, forb);
        if (!(forb & 1ll << ll(lvl)))
            Gen1(lvl + 1, got + 1, (forb | my[lvl]));
    }
}

void Gen2(int lvl, int got, int mask)
{
    if (lvl >= lim)
        res = max(res, got + dp[mask]);
    else {
        Gen2(lvl + 1, got, mask);
        if (!((ll(mask) << mid) & my[lvl + mid]))
            Gen2(lvl + 1, got + 1, (mask | 1 << lvl));
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
        my[i] = 1ll << ll(i);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        if (a == 1)
            writeOut();
        else {
            scanf("%s", tmp);
            was[getId(tmp)] = true;
        }
    }
    writeOut();
    mid = m / 2, lim = m - mid;
    Gen1(0, 0, 0);
    for (int i = 0; i < lim; i++)
        for (int j = 0; j < 1 << lim; j++) if ((j & 1 << i))
            dp[j ^ 1 << i] = max(dp[j ^ 1 << i], dp[j]);
    Gen2(0, 0, 0);
    printf("%d\n", res);
    return 0;
}