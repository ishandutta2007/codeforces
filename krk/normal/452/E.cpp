#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 300015;
const int mod = 1000000007;

char s[Maxn];
int slen;
int ran[Maxn];
int cur[Maxn];
int cnt[Maxn], nxt[Maxn];
bool dif1[Maxn], dif2[Maxn];
int bef[Maxn], plcp[Maxn];
int lcp[Maxn];
vector <int> has[Maxn];
int siz[Maxn], par[Maxn];
int A[Maxn], B[Maxn], C[Maxn];
int curways;
int res[Maxn];

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
                ran[cur[j]] = i;
        }
        cnt[ran[slen - h]]++; dif2[ran[slen - h]] = true;
        for (int i = 0; i < slen; i = nxt[i]) {
            for (int j = i; j < nxt[i]; j++) {
                int s = cur[j] - h;
                if (s >= 0) {
                    int head = ran[s];
                    ran[s] = head + cnt[head]++;
                    dif2[ran[s]] = true;
                }
            }
            for (int j = i; j < nxt[i]; j++) {
                int s = cur[j] - h;
                if (s >= 0 && dif2[ran[s]])
                    for (int k = ran[s] + 1; !dif1[k] && dif2[k]; k++)
                        dif2[k] = false;
            }
        }
        for (int i = 0; i < slen; i++) {
            cur[ran[i]] = i;
            dif1[i] |= dif2[i];
        }
    }
}

void calcLCP()
{
    bef[cur[0]] = -1;
    for (int i = 1; i < slen; i++)
        bef[cur[i]] = cur[i - 1];
    int l = 0;
    for (int i = 0; i < slen; i++) if (bef[i] != -1) {
        while (bef[i] + l < slen && i + l < slen && s[bef[i] + l] == s[i + l] && s[bef[i] + l] != '#' && s[i + l] != '#')
            l++;
        plcp[i] = l;
        l = max(l - 1, 0);
    }
    for (int i = 0; i < slen; i++) {
        lcp[i] = plcp[cur[i]];
        if (lcp[i]) has[lcp[i]].push_back(i);
    }
}

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void Subtract(int x)
{
    curways -= ll(A[x]) * B[x] * C[x] % mod;
    if (curways < 0) curways += mod;
}

void Merge(int a, int b)
{
    siz[a] += siz[b]; par[b] = a;
    A[a] += A[b]; B[a] += B[b]; C[a] += C[b];
    curways = (curways + ll(A[a]) * B[a] * C[a] % mod) % mod;
}

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    Subtract(a); Subtract(b);
    if (siz[a] >= siz[b]) Merge(a, b);
    else Merge(b, a);
}

void Insert(int x, int val)
{
    if (x > 0) unionSet(x - 1, x);
    if (x + 1 < slen && lcp[x + 1] >= val) unionSet(x, x + 1);
}

int main()
{
    scanf("%s", s); slen = strlen(s);
    s[slen++] = '#';
    int alen = slen;
    scanf("%s", s + slen); slen += strlen(s + slen);
    s[slen++] = '#';
    int blen = slen;
    scanf("%s", s + slen); slen += strlen(s + slen);
    int clen = slen;
    buildSA();
    calcLCP();
    for (int i = 0; i < slen; i++) { 
        siz[i] = 1; par[i] = i; 
        if (cur[i] < alen) A[i]++;
        else if (cur[i] < blen) B[i]++;
        else C[i]++;
    }
    int got = min(min(alen - 1, blen - alen - 1), clen - blen);
    for (int i = got; i > 0; i--) {
        for (int j = 0; j < has[i].size(); j++)
            Insert(has[i][j], i);
        res[i] = curways;
    }
    for (int i = 1; i <= got; i++)
        printf("%d%c", res[i], i + 1 <= got? ' ': '\n');
}