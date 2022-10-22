#include <bits/stdc++.h>
using namespace std;

typedef pair <bool, int> bi;

const int Maxn = 200005;
const int Maxm = 1048576;

struct node {
    bi seq[4];
    int slen;
    int res;
    node(): slen(0), res(0) {}
};

int n, q;
char str[Maxn];
bool a[Maxn];
vector <int> seq;
node st[Maxm];

void Add(node &nod, bi val);

void Fix(node &nod)
{
    if (nod.slen == 0) return;
    if (!nod.seq[nod.slen - 1].first) {
        int tk = (nod.seq[nod.slen - 1].second - 1) / 2;
        nod.res += tk;
        nod.seq[nod.slen - 1].second -= 2 * tk;
        if (nod.seq[nod.slen - 1].second > 1 && nod.slen >= 2) {
            nod.slen--;
            nod.res++;
        }
        return;
    }
    if (nod.slen >= 2 && nod.seq[nod.slen - 2].second > 1) {
        int add = nod.seq[nod.slen - 1].second; nod.slen--;
        nod.slen--;
        nod.res++;
        Add(nod, bi(true, add));
        return;
    }
    if (nod.slen >= 3) {
        int tk = min(nod.seq[nod.slen - 3].second,nod.seq[nod.slen - 1].second);
        int add = nod.seq[nod.slen - 1].second - tk; nod.seq[nod.slen - 3].second -= tk;
        nod.res += tk;
        nod.slen -= 2;
        if (nod.seq[nod.slen - 1].second == 0) nod.slen--;
        Add(nod, bi(false, 1));
        if (add) Add(nod, bi(true, add));
    }
}

void Add(node &nod, bi val)
{
    if (nod.slen == 0 || nod.seq[nod.slen - 1].first != val.first) nod.seq[nod.slen++] = val;
    else nod.seq[nod.slen - 1].second += val.second;
    Fix(nod);
}

int getRes(const node &nod)
{
    int res = nod.res;
    for (int i = 0; i < nod.slen; i++)
        res += nod.seq[i].second;
    return res;
}

node Union(const node &L, const node &R)
{
    node C = L;
    C.res += R.res;
    for (int i = 0; i < R.slen; i++)
        Add(C, R.seq[i]);
    return C;
}

void Create(int v, int l, int r)
{
    if (l == r)
        Add(st[v], bi(a[l], 1));
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
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
        return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    scanf("%s", str + 1);
    for (int i = 2; i <= n; i += 2)
        str[i] = str[i] == '1'? '0': '1';
    for (int i = 1, j; i <= n; i = j) {
        j = i;
        while (j <= n && str[i] == str[j]) j++;
        a[seq.size()] = (j - i) % 2;
        seq.push_back(i);
    }
    Create(1, 0, int(seq.size()) - 1);
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        int ind = lower_bound(seq.begin(), seq.end(), l) - seq.begin();
        int ind2 = upper_bound(seq.begin(), seq.end(), r) - seq.begin();
        node cur;
        int lef = ind < seq.size()? seq[ind]: r + 1;
        if (l < lef) Add(cur, bi((lef - l) % 2 == 1, 1));
        if (lef <= r) {
            ind2--;
            if (ind < ind2) cur = Union(cur, Get(1, 0, int(seq.size()) - 1, ind, ind2 - 1));
            Add(cur, bi((r + 1 - seq[ind2]) % 2 == 1, 1));
        }
        printf("%d\n", getRes(cur));
    }
    return 0;
}