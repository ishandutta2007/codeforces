#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n, m;
set <int> neigh[Maxn];
bool tk[Maxn];
vector <int> seq[2];
int res[Maxn];
int cur = 1;

void Traverse(int v, int col)
{
    if (tk[v]) return;
    tk[v] = true;
    seq[col].push_back(v);
    for (set <int>::iterator it = neigh[v].begin(); it != neigh[v].end(); it++)
        Traverse(*it, 1 - col);
}

vector <int> Get(int v, const vector <int> &oth)
{
    vector <int> res;
    for (int i = 0; i < oth.size() && res.size() < 2; i++) {
        int u = oth[i];
        if (!neigh[v].count(u)) res.push_back(u);
    }
    return res;
}

void End()
{
    int wh = 0;
    while (!seq[0].empty()) {
        int v = seq[0].back(); seq[0].pop_back();
        if (res[v]) continue;
        res[v] = cur;
        if (++wh % 3 == 0) cur++;
    }
    while (!seq[1].empty()) {
        int v = seq[1].back(); seq[1].pop_back();
        if (res[v]) continue;
        res[v] = cur;
        if (++wh % 3 == 0) cur++;
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].insert(b);
        neigh[b].insert(a);
    }
    for (int i = 1; i <= n; i++)
        Traverse(i, 0);
    if (seq[0].size() % 3 == 2)
        swap(seq[0], seq[1]);
    if (seq[0].size() % 3 == 1) {
        for (int i = 0; i < seq[0].size(); i++) {
            int v = seq[0][i];
            auto oth = Get(v, seq[1]);
            if (oth.size() >= 2) {
                res[v] = res[oth[0]] = res[oth[1]] = cur; cur++;
                End();
                return 0;
            }
        }
        vector <int> valid;
        for (int i = 0; i < seq[1].size() && valid.size() < 2; i++) {
            int v = seq[1][i];
            auto oth = Get(v, seq[0]);
            if (oth.size() >= 2) valid.push_back(v);
        }
        if (valid.size() >= 2) {
            int v = valid[0];
            auto oth = Get(v, seq[0]);
            res[v] = res[oth[0]] = res[oth[1]] = cur; cur++;
            v = valid[1];
            oth = Get(v, seq[0]);
            res[v] = res[oth[0]] = res[oth[1]] = cur; cur++;
            End();
            return 0;
        }
        printf("NO\n");
        return 0;
    }
    End();
    return 0;
}