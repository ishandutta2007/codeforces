#include <bits/stdc++.h>
using namespace std;

const int Maxk = 17;
const int Maxn = 1 << Maxk;

int mem[Maxk][1 << Maxk];
int seq[1 << Maxk];
int cur[1 << Maxk];
bool done;
int T;
int n;
bool tk[1 << Maxk];
int val[1 << Maxk];
int got[1 << Maxk];
int perm[1 << Maxk];
vector <int> neigh[1 << Maxk];

void Gen(int lvl, int k)
{
    if (lvl >= 1 << k) {
        for (int i = 0; i < 1 << k; i++)
            mem[k][i] = seq[i];
        done = true;
    } else {
        for (seq[lvl] = 0; seq[lvl] < k && !done; seq[lvl]++) {
            bool ok = true;
            cur[lvl] = 0;
            for (int i = 0; i < k && ok; i++) {
                int j = (lvl ^ 1 << i);
                if (j < lvl)
                    if (cur[j] & 1 << seq[lvl]) { ok = false; break; }
                    else if (cur[lvl] & 1 << seq[j]) { ok = false; break; }
                    else cur[lvl] ^= 1 << seq[j];
            }
            if (ok) {
                for (int i = 0; i < k; i++) {
                    int j = (lvl ^ 1 << i);
                    if (j < lvl) cur[j] ^= 1 << seq[lvl];
                }
                Gen(lvl + 1, k);
                for (int i = 0; i < k; i++) {
                    int j = (lvl ^ 1 << i);
                    if (j < lvl) cur[j] ^= 1 << seq[lvl];
                }
            }
        }
    }
}

int main()
{
    for (int i = 1; i < Maxk; i <<= 1) {
        fill(seq, seq + (1 << i), 0);
        fill(cur, cur + (1 << i), 0);
        Gen(0, i);
        done = false;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < 1 << n; i++) {
            tk[i] = false;
            val[i] = 0;
            neigh[i].clear();
        }
        for (int i = 0; i < n * (1 << n - 1); i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        vector <int> lst;
        tk[0] = true;
        for (int i = 0; i < neigh[0].size(); i++) {
            int v = neigh[0][i];
            tk[v] = true;
            val[v] = 1 << i;
            lst.push_back(v);
        }
        for (int i = 0; i < n; i++) {
            fill(got, got + (1 << n), 0);
            vector <int> nlst;
            for (int j = 0; j < lst.size(); j++) {
                int v = lst[j];
                for (int z = 0; z < neigh[v].size(); z++) {
                    int u = neigh[v][z];
                    if (!tk[u])
                        if (got[u] == 0) got[u] = val[v];
                        else {
                            tk[u] = true;
                            val[u] = got[u] | val[v];
                            nlst.push_back(u);
                        }
                }
            }
            lst = nlst;
        }
        for (int i = 0; i < 1 << n; i++)
            perm[val[i]] = i;
        for (int i = 0; i < 1 << n; i++)
            printf("%d%c", perm[i], i + 1 < 1 << n? ' ': '\n');
        if (n == 1 || n == 2 || n == 4 || n == 8 || n == 16)
            for (int i = 0; i < 1 << n; i++)
                printf("%d%c", mem[n][val[i]], i + 1 < 1 << n? ' ': '\n');
        else printf("-1\n");
    }
    return 0;
}