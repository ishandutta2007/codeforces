#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
int len[Maxn];
vector <ii> lens[Maxn];
int nxt[Maxn];
vector <int> seq;

void Traverse(int v)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        Traverse(u);
        lens[v].push_back(ii(len[u], u));
        len[v] = max(len[v], len[u] + 1);
    }
    sort(lens[v].rbegin(), lens[v].rend());
}

void Add(int v, int u)
{
    if (u != -1) seq.push_back(u);
    for (int i = 0; i < lens[v].size(); i++) {
        Add(lens[v][i].second, u);
        u = lens[v][i].second;
    }
    nxt[v] = u;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int p; scanf("%d", &p);
        neigh[p].push_back(i);
    }
    Traverse(0);
    Add(0, -1);
    int v = 0;
    while (v != -1) {
        printf("%d%c", v, nxt[v] != -1? ' ': '\n');
        v = nxt[v];
    }
    printf("%d\n", int(seq.size()));
    reverse(seq.begin(), seq.end());
    for (int i = 0; i < seq.size(); i++)
        printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
    return 0;
}