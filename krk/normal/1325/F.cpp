#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n, m;
int p;
vector <int> neigh[Maxn];
vector <int> seq;
int tk[Maxn], id[Maxn];
bool found;
bool spec[Maxn];
vector <int> st;

void Add(int v)
{
    for (int i = 0; i < neigh[v].size(); i++)
        if (spec[neigh[v][i]]) return;
    spec[v] = true; st.push_back(v);
}

void Traverse(int v)
{
    tk[v] = 1;
    id[v] = seq.size(); seq.push_back(v);
    for (int i = 0; i < neigh[v].size() && !found; i++) {
        int u = neigh[v][i];
        if (tk[u] == 1 && id[v] - id[u] + 1 >= p) {
            found = true;
            printf("2\n");
            printf("%d\n", id[v] - id[u] + 1);
            for (int i = id[u]; i <= id[v]; i++)
                printf("%d%c", seq[i], i + 1 <= id[v]? ' ': '\n');
            return;
        }
        if (tk[u] == 0) Traverse(u);
    }
    Add(v); tk[v] = 2; seq.pop_back();
}

int main()
{
    scanf("%d %d", &n, &m);
    p = 1;
    while (p * p < n) p++;
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1);
    assert(found || st.size() >= p);
    if (!found) {
        printf("1\n");
        for (int i = 0; i < p; i++)
            printf("%d%c", st[i], i + 1 < p? ' ': '\n');
    }
    return 0;
}