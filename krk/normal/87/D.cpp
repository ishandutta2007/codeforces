#include <cstdio>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn], b[Maxn], c[Maxn];
int p[Maxn], siz[Maxn];
int seq[Maxn];
vector <int> neigh[Maxn];
int tot[Maxn], col[Maxn], ans[Maxn];
ll res;
vector <int> V;

bool Less(const int &v, const int &u)
{
     return c[v] < c[u];
}

void Calc(int v, int c)
{
     if (ans[v]) return;
     ans[v] = siz[v]; col[v] = c; tot[c] += siz[v];
     for (int i = 0; i < neigh[v].size(); i++) {
         int u = neigh[v][i]; 
         if (!ans[u]) { Calc(u, c); ans[v] += ans[u]; }
     }
}

int getPar(int x)
{
    if (x == p[x]) return x;
    return p[x] = getPar(p[x]);
}

void Join(int a, int b)
{
     a = getPar(a), b = getPar(b);
     if (siz[a] > siz[b]) {
                siz[a] += siz[b];
                p[b] = a;
     } else {
            siz[b] += siz[a];
            p[a] = b;
     }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]); seq[i] = i;
    }
    for (int i = 1; i <= n; i++) { p[i] = i; siz[i] = 1; }
    sort(seq, seq + n - 1, Less);
    for (int i = 0; i < n - 1; ) {
        int j = i;
        while (j < n - 1 && c[seq[j]] == c[seq[i]]) {
              int para = getPar(a[seq[j]]), parb = getPar(b[seq[j]]);
              neigh[para].push_back(parb); neigh[parb].push_back(para);
              j++;
        }
        for (int l = i; l < j; l++) {
            int para = getPar(a[seq[l]]), parb = getPar(b[seq[l]]);
            Calc(para, para); Calc(parb, parb);
            ll cand;
            if (ans[para] > ans[parb]) cand = 2LL * ll(tot[col[parb]] - ans[parb]) * ll(ans[parb]);
            else cand = 2LL * ll(tot[col[parb]] - ans[para]) * ll(ans[para]);
            if (cand > res) { res = cand; V.clear(); }
            if (cand == res) V.push_back(seq[l] + 1);   
        }
        for (int l = i; l < j; l++) {
            int para = getPar(a[seq[l]]), parb = getPar(b[seq[l]]);
            neigh[para].clear(); neigh[parb].clear();
            ans[para] = ans[parb] = 0;
            tot[col[para]] = tot[col[parb]] = 0;
            col[para] = col[parb] = 0;
        }
        for (int l = i; l < j; l++) Join(getPar(a[seq[l]]), getPar(b[seq[l]]));
        i = j;
    }
    printf("%I64d %d\n", res, V.size());
    sort(V.begin(), V.end());
    for (int i = 0; i < V.size(); i++) printf("%d%c", V[i], i + 1 < V.size()? ' ': '\n');
    return 0;
}