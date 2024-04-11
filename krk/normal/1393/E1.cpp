#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int mod = 1000000007;
const int Maxn = 500005;
const int Maxk = 22;

char s[Maxn];
int slen;
int rnk[Maxn];
int cur[Maxn];
int cnt[Maxn], nxt[Maxn];
bool dif1[Maxn], dif2[Maxn];

int bef[Maxn], plcp[Maxn];
int lcp[Maxn];

bool Less(const int &a, const int &b) { return s[a] < s[b]; }

void buildSA()
{
    for (int i = 0; i < slen; i++)
        cur[i] = i;
    sort(cur, cur + slen, Less);
    for (int i = 0; i < slen; i++) {
        dif1[i] = i == 0 || s[cur[i - 1]] != s[cur[i]];
        dif2[i] = false;
    }
    for (int h = 1; h < slen; h <<= 1) {
        int buck = 0;
        for (int i = 0, j; i < slen; i = j) {
            j = i + 1;
            while (j < slen && !dif1[j]) j++;
            nxt[i] = j;
            buck++;
        }
        if (buck == slen) break;
        for (int i = 0; i < slen; i = nxt[i]) {
            cnt[i] = 0;
            for (int j = i; j < nxt[i]; j++)
                rnk[cur[j]] = i;
        }
        cnt[rnk[slen - h]]++; dif2[rnk[slen - h]] = true;
        for (int i = 0; i < slen; i = nxt[i]) {
            for (int j = i; j < nxt[i]; j++) {
                int s = cur[j] - h;
                if (s >= 0) {
                    int head = rnk[s];
                    rnk[s] = head + cnt[head]++;
                    dif2[rnk[s]] = true;
                }
            }
            for (int j = i; j < nxt[i]; j++) {
                int s = cur[j] - h;
                if (s >= 0 && dif2[rnk[s]])
                    for (int k = rnk[s] + 1; !dif1[k] && dif2[k]; k++) dif2[k] = false;
            }
        }
        for (int i = 0; i < slen; i++) {
            cur[rnk[i]] = i;
            dif1[i] |= dif2[i];
        }
    }
}

void calcLCP()
{
    bef[cur[0]] = -1;
    for (int i = 1; i < slen; i++) bef[cur[i]] = cur[i - 1];
    int l = 0;
    for (int i = 0; i < slen; i++) if (bef[i] != -1) {
        while (bef[i] + l < slen && i + l < slen && s[bef[i] + l] == s[i + l]) l++;
        plcp[i] = l;
        l = max(l - 1, 0);
    }
    for (int i = 0; i < slen; i++)
        lcp[i] = plcp[cur[i]];
}

char tmp[Maxn];
int n;
string A[Maxn];
ii wh[Maxn];
vector <int> id[Maxn];
int mn[Maxn][Maxk];
int lg2[Maxn];
ii all[Maxn];
int alen;
bool upd[Maxn];
int BIT[Maxn];
int col[Maxn];
int vals[Maxn];

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

int getCommon(int a, int aind, int b, int bind)
{
    int lef = id[a][aind], rig = id[b][bind];
    if (lef == rig) return Maxn;
    if (lef > rig) swap(lef, rig);
    int k = lg2[rig - lef];
    return min(mn[lef + 1][k], mn[rig - (1 << k) + 1][k]);
}

int getStatus(int a, int inda, int b, int indb)
{
    int froma = 0, fromb = 0;
    while (true)
        if (froma == inda) { inda = A[a].length(); froma++; }
        else if (fromb == indb) { indb = A[b].length(); fromb++; }
        else if (froma >= A[a].length()) return fromb < A[b].length()? -1: 0;
        else if (fromb >= A[b].length()) return 1;
        else {
            int sam = getCommon(a, froma, b, fromb);
            sam = min(sam, min(inda - froma, indb - fromb));
            if (sam == 0)
                if (A[a][froma] < A[b][fromb]) return -1;
                else if (A[a][froma] == A[b][fromb]) return 0;
                else return 1;
            froma += sam; fromb += sam;
        }
}

bool LessPair(const ii &a, const ii &b)
{
    return getStatus(a.first, a.second, b.first, b.second) < 0;
}

void Add(int ind, int c, int val)
{
    for (int i = ind + 1; i < Maxn; i += i & -i)
        if (col[i] != c) {
            col[i] = c;
            BIT[i] = val;
        } else BIT[i] = (BIT[i] + val) % mod;
}

int Get(int ind, int c)
{
    int res = 0;
    for (int i = ind + 1; i > 0; i -= i & -i)
        if (col[i] == c)
            res = (res + BIT[i]) % mod;
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Read(A[i]);
        for (int j = 0; j < A[i].length(); j++) {
            s[slen] = A[i][j];
            wh[slen] = ii(i, j);
            slen++;
        }
        s[slen++] = '#';
    }
    buildSA();
    calcLCP();
    for (int i = 0; i < Maxk; i++)
        for (int j = 1 << i; j < Maxn && j < (1 << i + 1); j++)
            lg2[j] = i;
    for (int i = 0; i < slen; i++)
        mn[i][0] = lcp[i];
    for (int j = 1; j < Maxk; j++)
        for (int i = 0; i + (1 << j) <= slen; i++)
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
    for (int i = 0; i < n; i++)
        id[i].resize(A[i].length() + 1);
    for (int i = 0; i < slen; i++) {
        int ind = cur[i];
        if (s[ind] != '#') {
            ii p = wh[ind];
            id[p.first][p.second] = i;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= A[i].length(); j++)
            all[alen++] = ii(i, j);
    sort(all, all + alen, LessPair);
    int comp = 0;
    for (int i = 0; i < alen; i++)
        if (i && LessPair(all[i - 1], all[i])) upd[i] = true;
    for (int i = 0; i < alen; i++) {
        if (upd[i]) comp++;
        id[all[i].first][all[i].second] = comp;
    }
    Add(0, 0, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= A[i].length(); j++)
            vals[j] = Get(id[i][j], i);
        for (int j = 0; j <= A[i].length(); j++)
            Add(id[i][j], i + 1, vals[j]);
    }
    int res = Get(Maxn - 2, n);
    printf("%d\n", res);
    return 0;
}