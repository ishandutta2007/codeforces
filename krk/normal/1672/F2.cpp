#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
int b[Maxn];
vector <int> neigh[Maxn];
int tk[Maxn];
int cnt[Maxn];
int mx;

bool Cycle(int v)
{
    if (tk[v] == 2) return false;
    if (tk[v] == 1) return true;
    tk[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (Cycle(u)) return true;
    }
    tk[v] = 2;
    return false;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            cnt[i] = 0;
            neigh[i].clear();
            tk[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            cnt[a[i]]++;
        }
        mx = 1;
        for (int i = 2; i <= n; i++)
            if (cnt[i] > cnt[mx]) mx = i;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
            if (a[i] != mx && b[i] != mx)
                neigh[a[i]].push_back(b[i]);
        }
        bool cycl = false;
        for (int i = 1; i <= n && !cycl; i++)
            cycl = Cycle(i);
        printf("%s\n", !cycl? "AC": "WA");
    }
    return 0;
}