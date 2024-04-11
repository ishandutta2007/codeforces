#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, k;
int r[Maxn];
ii srt[Maxn];
vector <int> neigh[Maxn];
set <int> S;
int res[Maxn];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
        srt[i] = ii(r[i], i);
    }
    for (int i = 0; i < k; i++) {
        int a, b; scanf("%d %d", &a, &b); a--; b--;
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    sort(srt, srt + n);
    for (int i = 0, j; i < n; i = j) {
        j = i;
        while (j < n && srt[i].first == srt[j].first) j++;
        for (int z = i; z < j; z++) {
            int v = srt[z].second;
            int ans = int(S.size());
            for (int c = 0; c < neigh[v].size(); c++)
                if (S.find(neigh[v][c]) != S.end()) ans--;
            res[v] = ans;
        }
        for (int z = i; z < j; z++)
            S.insert(srt[z].second);
    }
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}