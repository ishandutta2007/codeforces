#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ii> llii;

const int Maxn = 500005;
const int mod = 1000000007;

int pw2[Maxn];
int n, m;
ll k;
ll enc[Maxn];
llii E[Maxn];
vector <int> neigh[Maxn];
int seq[Maxn], slen;
bool tk[Maxn];
int res;

void Fill(int v)
{
    if (tk[v]) return;
    tk[v] = true;
    for (int i = 0; i < neigh[v].size(); i++)
        Fill(neigh[v][i]);
}

int main()
{
    pw2[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw2[i] = 2ll * pw2[i - 1] % mod;
    scanf("%d %d %I64d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &enc[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &E[i].second.first, &E[i].second.second);
        E[i].first = (enc[E[i].second.first] ^ enc[E[i].second.second]);
    }
    sort(E, E + m);
    ll masks = (1ll << k);
    for (int i = 0, j; i < m; i = j) {
        masks--;
        j = i;
        while (j < m && E[i].first == E[j].first) {
            int a = E[j].second.first, b = E[j].second.second;
            if (neigh[a].empty()) seq[slen++] = a;
            if (neigh[b].empty()) seq[slen++] = b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
            j++;
        }
        int lft = n - slen;
        for (int i = 0; i < slen; i++) if (!tk[seq[i]]) {
            Fill(seq[i]);
            lft++;
        }
        for (int i = 0; i < slen; i++) {
            tk[seq[i]] = false;
            neigh[seq[i]].clear();
        }
        slen = 0;
        res = (res + pw2[lft]) % mod;
    }
    res = (res + masks % mod * ll(pw2[n])) % mod;
    printf("%d\n", res);
    return 0;
}