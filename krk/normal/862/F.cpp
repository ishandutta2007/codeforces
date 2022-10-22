#include <bits/stdc++.h>
using namespace std;

typedef pair <string, int> si;
typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxk = 20;
const int Maxm = 524288;

struct node {
    vector <ii> lef, rig;
    int en;
    ll best;
};

char tmp[Maxn];
int n, q;
si seq[Maxn];
int slen;
int inseq[Maxn];
int len[Maxn];
int mn[Maxn][Maxk];
int cur[Maxn];
int qtyp[Maxn], qa[Maxn], qb[Maxn];
int my[Maxm];
node st[Maxm];

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

int getMin(int a, int b)
{
    int l = inseq[a], r = inseq[b];
    if (l > r) swap(l, r);
    int res = seq[l].first.length();
    for (int i = Maxk - 1; i >= 0; i--) if (l + (1 << i) <= r) {
        res = min(res, mn[l][i]);
        l += 1 << i;
    }
    return res;
}

node Union(const node &a, const node &b)
{
    node c;
    c.lef = a.lef;
    int pntb = 0, cntb = 0;
    while (pntb < b.lef.size() && b.lef[pntb].first >= a.en)
        cntb += b.lef[pntb++].second;
    int mpntb = pntb, mcntb = cntb;
    int val = min(a.en, a.lef.back().first);
    while (pntb < b.lef.size() && b.lef[pntb].first >= val)
        cntb += b.lef[pntb++].second;
    if (a.lef.back().first == val) c.lef.back().second += cntb;
    else c.lef.push_back(ii(val, cntb));
    c.lef.insert(c.lef.end(), b.lef.begin() + pntb, b.lef.end());
    c.rig = b.rig;
    int pnta = 0, cnta = 0;
    while (pnta < a.rig.size() && a.rig[pnta].first >= a.en)
        cnta += a.rig[pnta++].second;
    int mpnta = pnta, mcnta = cnta;
    val = min(a.en, b.rig.back().first);
    while (pnta < a.rig.size() && a.rig[pnta].first >= val)
        cnta += a.rig[pnta++].second;
    if (b.rig.back().first == val) c.rig.back().second += cnta;
    else c.rig.push_back(ii(val, cnta));
    c.rig.insert(c.rig.end(), a.rig.begin() + pnta, a.rig.end());
    c.best = max(a.best, b.best);
    c.en = b.en;
    pnta = mpnta, pntb = mpntb;
    int all = mcnta + mcntb;
    c.best = max(c.best, ll(all) * a.en);
    while (pnta < a.rig.size() || pntb < b.lef.size())
        if (pnta < a.rig.size() && (pntb >= b.lef.size() || a.rig[pnta].first >= b.lef[pntb].first)) {
            all += a.rig[pnta].second;
            c.best = max(c.best, ll(all) * a.rig[pnta].first);
            pnta++;
        } else {
            all += b.lef[pntb].second;
            c.best = max(c.best, ll(all) * b.lef[pntb].first);
            pntb++;
        }
    return c;
}

void Create(int v, int l, int r)
{
    if (l == r) {
        st[v].lef = {ii(len[my[l]], 1)};
        st[v].rig = {ii(len[my[l]], 1)};
        st[v].en = cur[l];
        st[v].best = len[my[l]];
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

void Update(int v, int l, int r, int a, int b)
{
    if (l == r) {
        st[v].lef = {ii(len[my[l]], 1)};
        st[v].rig = {ii(len[my[l]], 1)};
        st[v].en = cur[l];
        st[v].best = len[my[l]];
    } else {
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

node Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, b);
        if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
        else return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        Read(seq[slen].first);
        len[slen] = seq[slen].first.length();
        seq[slen].second = slen;
        slen++;
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &qtyp[i], &qa[i]);
        qa[i]--;
        if (qtyp[i] == 1) {
            scanf("%d", &qb[i]);
            qb[i]--;
        } else {
            Read(seq[slen].first);
            len[slen] = seq[slen].first.length();
            seq[slen].second = slen;
            slen++;
        }
    }
    sort(seq, seq + slen);
    for (int i = 0; i < slen; i++) {
        inseq[seq[i].second] = i;
        if (i + 1 < slen) {
            int to = min(seq[i].first.length(), seq[i + 1].first.length());
            while (mn[i][0] < to && seq[i].first[mn[i][0]] == seq[i + 1].first[mn[i][0]])
                mn[i][0]++;
        }
    }
    for (int j = 1; j < Maxk; j++)
        for (int i = 0; i + (1 << j) < slen; i++)
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
    for (int i = 0; i + 1 < n; i++)
        cur[i] = getMin(i, i + 1);
    for (int i = 0; i < n; i++)
        my[i] = i;
    Create(1, 0, n - 1);
    int pnt = n;
    for (int i = 0; i < q; i++)
        if (qtyp[i] == 1)
            printf("%I64d\n", Get(1, 0, n - 1, qa[i], qb[i]).best);
        else {
            if (qa[i] > 0) cur[qa[i] - 1] = getMin(my[qa[i] - 1], pnt);
            if (qa[i] + 1 < n) cur[qa[i]] = getMin(my[qa[i] + 1], pnt);
            my[qa[i]] = pnt;
            pnt++;
            Update(1, 0, n - 1, max(0, qa[i] - 1), qa[i]);
        }
    return 0;
}