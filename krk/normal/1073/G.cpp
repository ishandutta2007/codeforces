#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxk = 20;

int n, q;
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

int mn[Maxn][Maxk];
vector <ii> seq;
vector <ii> A, B;
ll sumA, sumB;

int getMin(int a, int b)
{
    int res = Maxn;
    if (a == b) return res;
    a++;
    for (int i = Maxk - 1; i >= 0; i--)
        if (a + (1 << i) <= b + 1) {
            res = min(res, mn[a][i]);
            a += 1 << i;
        }
    return res;
}

void Clear()
{
    seq.clear();
    A.clear(); B.clear();
    sumA = sumB = 0;
}

void Add(vector <ii> &A, ll &sumA, int ind)
{
    int val = slen - cur[ind];
    A.push_back(ii(val, 1));
    sumA += val;
}

void Limit(vector <ii> &A, ll &sumA, int lim)
{
    int cnt = 0;
    while (!A.empty() && A.back().first > lim) {
        sumA -= ll(A.back().first - lim) * A.back().second;
        cnt += A.back().second;
        A.pop_back();
    }
    if (cnt)
        A.push_back(ii(lim, cnt));
}

int main()
{
    scanf("%d %d", &n, &q);
    scanf("%s", s); slen = n;
    buildSA();
    for (int i = 0; i < n; i++)
        rnk[cur[i]] = i;
    calcLCP();
    for (int i = 0; i < n; i++)
        mn[i][0] = lcp[i];
    for (int j = 1; j < Maxk; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
    while (q--) {
        Clear();
        ll res = 0;
        int n, m; scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            int ind; scanf("%d", &ind);
            seq.push_back(ii(rnk[ind - 1], 0));
        }
        for (int i = 0; i < m; i++) {
            int ind; scanf("%d", &ind);
            seq.push_back(ii(rnk[ind - 1], 1));
        }
        sort(seq.begin(), seq.end());
        for (int i = 0; i < seq.size(); i++) {
            if (i) {
                int lim = getMin(seq[i - 1].first, seq[i].first);
                Limit(A, sumA, lim);
                Limit(B, sumB, lim);
            }
            if (seq[i].second == 0) {
                res += sumB;
                Add(A, sumA, seq[i].first);
            } else {
                res += sumA;
                Add(B, sumB, seq[i].first);
            }
        }
        printf("%I64d\n", res);
    }
    return 0;
}