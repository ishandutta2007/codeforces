#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 800005;
const int Maxb = 30;

int n, m;
int q;
int oth[Maxn], sum[Maxn];
int A[Maxn], B[Maxn], D[Maxn];
int cur;
map <ii, int> S;
ii par[Maxn];
int siz[Maxn];
ii seq[Maxn];
int slen;
int mask[Maxb];
int meq[Maxn];
int mlen;
int res[Maxn];

ii getPar(int x)
{
    if (par[x].first == x) return par[x];
    auto res = getPar(par[x].first);
    res.second ^= par[x].second;
    return res;
}

void unionSet(int a, int b, int c)
{
    ii para = getPar(a), parb = getPar(b);
    if (para.first == parb.first) {
        c ^= para.second ^ parb.second;
        for (int i = Maxb - 1; i >= 0; i--) if (c & 1 << i)
            if (mask[i]) c ^= mask[i];
            else {
                mask[i] = c;
                meq[mlen++] = i;
                break;
            }
        return;
    }
    if (siz[para.first] < siz[parb.first]) swap(para, parb);
    siz[para.first] += siz[parb.first]; par[parb.first] = ii(para.first, (para.second ^ c ^ parb.second));
    seq[slen++] = ii(para.first, parb.first);
}

void undoSeq(int lim)
{
    while (slen > lim) {
        slen--;
        int a = seq[slen].first, b = seq[slen].second;
        siz[a] -= siz[b]; par[b] = ii(b, 0);
    }
}

void undoMeq(int lim)
{
    while (mlen > lim) {
        mlen--;
        mask[meq[mlen]] = 0;
    }
}

void Solve(int l, int r)
{
    if (l == r) {
        int ans = (getPar(A[l]).second ^ getPar(B[l]).second);
        for (int i = Maxb - 1; i >= 0; i--) if (ans & 1 << i)
            if (mask[i]) ans ^= mask[i];
        res[l] = ans;
        return;
    }
    int m = l + r >> 1;
    if (sum[r] - sum[m] > 0) {
        int mems = slen, memm = mlen;
        for (int i = l; i <= m; i++) if (oth[i] > i && oth[i] > r)
            unionSet(A[i], B[i], D[i]);
        Solve(m + 1, r);
        undoSeq(mems); undoMeq(memm);
    }
    if (sum[m] - sum[l - 1] > 0) {
        int mems = slen, memm = mlen;
        for (int i = m + 1; i <= r; i++) if (oth[i] < i && oth[i] <= l)
            unionSet(A[oth[i]], B[oth[i]], D[oth[i]]);
        Solve(l, m);
        undoSeq(mems); undoMeq(memm);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        par[i] = ii(i, 0);
        siz[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        cur++;
        sum[cur] += sum[cur - 1];
        S.insert(make_pair(ii(a, b), cur));
        A[cur] = a; B[cur] = b; D[cur] = c;
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int typ, a, b; scanf("%d %d %d", &typ, &a, &b);
        cur++;
        sum[cur] += sum[cur - 1];
        if (typ == 1) {
            int c; scanf("%d", &c);
            S.insert(make_pair(ii(a, b), cur));
            A[cur] = a; B[cur] = b; D[cur] = c;
        } else if (typ == 2) {
            auto it = S.find(ii(a, b));
            oth[cur] = it->second;
            oth[it->second] = cur;
            S.erase(it);
        } else if (typ == 3) {
            oth[cur] = cur;
            A[cur] = a; B[cur] = b;
            sum[cur]++;
        }
    }
    for (auto it: S) {
        cur++;
        sum[cur] += sum[cur - 1];
        oth[cur] = it.second;
        oth[it.second] = cur;
    }
    Solve(1, cur);
    for (int i = 1; i <= cur; i++) if (oth[i] == i)
        printf("%d\n", res[i]);
    return 0;
}