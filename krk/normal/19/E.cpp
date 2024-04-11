#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 10005;
const int Maxm = 40005;

int n, m;
int A[Maxm], B[Maxm];
int oth[Maxm];
bool res[Maxm];
ii par[Maxn];
int siz[Maxn];
bool forb;
vector <ii> S;

ii getPar(int x)
{
    if (par[x].first == x) return par[x];
    ii got = getPar(par[x].first);
    got.second ^= par[x].second;
    return got;
}

void unionSet(int a, int b)
{
    ii para = getPar(a), parb = getPar(b);
    if (para.first == parb.first) {
        if (para.second == parb.second) forb = true;
        return;
    }
    if (siz[para.first] < siz[parb.first]) swap(para, parb);
    siz[para.first] += siz[parb.first];
    par[parb.first] = ii(para.first, (para.second ^ parb.second ^ 1));
    S.push_back(ii(para.first, parb.first));
}

void Undo(int sz)
{
    while (S.size() > sz) {
        int a = S.back().first, b = S.back().second; S.pop_back();
        siz[a] -= siz[b]; par[b] = ii(b, 0);
    }
}

void Solve(int l, int r)
{
    if (forb) return;
    if (l == r) { res[l] = true; return; }
    int mem = S.size();
    int m = l + r >> 1;
    for (int i = m + 1; i <= r; i++) if (oth[i] < i && oth[i] <= l)
        unionSet(A[i], B[i]);
    Solve(l, m);
    Undo(mem); forb = false;
    for (int i = l; i <= m; i++) if (oth[i] > i && oth[i] > r)
        unionSet(A[i], B[i]);
    Solve(m + 1, r);
    Undo(mem); forb = false;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        par[i] = ii(i, 0);
        siz[i] = 1;
    }
    for (int a = 0; a < m; a++) {
        scanf("%d %d", &A[a], &B[a]);
        int b = m + 2 * a;
        int c = m + 2 * a + 1;
        int d = 3 * m + a;
        oth[a] = b; oth[b] = a;
        oth[c] = d; oth[d] = c;
        A[b] = A[c] = A[d] = A[a];
        B[b] = B[c] = B[d] = B[a];
    }
    if (m != 0) Solve(0, 4 * m - 1);
    vector <int> ans;
    for (int i = 0; i < m; i++) if (res[m + 2 * i])
        ans.push_back(i);
    printf("%d\n", int(ans.size()));
    for (int i = 0; i < ans.size(); i++)
        printf("%d%c", ans[i] + 1, i + 1 < ans.size()? ' ': '\n');
    return 0;
}