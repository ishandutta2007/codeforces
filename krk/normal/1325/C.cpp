#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
vector <ii> neigh[Maxn];
int in[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(ii(b, i));
        neigh[b].push_back(ii(a, i));
        in[a]++; in[b]++;
        res[i] = -1;
    }
    int cur = 0;
    vector <int> seq;
    for (int i = 1; i <= n; i++)
        if (in[i] == 1) seq.push_back(i);
    for (int i = 0; i < seq.size(); i++) {
        int v = seq[i];
        for (int j = 0; j < neigh[v].size(); j++) {
            int u = neigh[v][j].first;
            int ind = neigh[v][j].second;
            if (res[ind] == -1) res[ind] = cur;
            if (--in[u] == 1) seq.push_back(u);
        }
        cur++;
    }
    for (int i = 0; i < n - 1; i++)
        printf("%d\n", res[i]);
    return 0;
}