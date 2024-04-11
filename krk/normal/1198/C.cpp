#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

int T;
int n, m;
vector <ii> neigh[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= 3 * n; i++)
            neigh[i].clear();
        set <int> S;
        for (int i = 1; i <= m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(ii(b, i));
            neigh[b].push_back(ii(a, i));
        }
        vector <int> E;
        for (int i = 1; i <= 3 * n && S.size() < n && E.size() < n; i++) {
            int found = -1;
            for (int j = 0; j < neigh[i].size() && found == -1; j++) {
                ii u = neigh[i][j];
                if (S.find(u.first) != S.end()) {
                    E.push_back(u.second);
                    found = u.first;
                }
            }
            if (found != -1) S.erase(found);
            else S.insert(i);
        }
        if (S.size() == n) {
            vector <int> res;
            for (set <int>::iterator it = S.begin(); it != S.end(); it++)
                res.push_back(*it);
            printf("IndSet\n");
            for (int i = 0; i < res.size(); i++)
                printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
        } else {
            printf("Matching\n");
            for (int i = 0; i < E.size(); i++)
                printf("%d%c", E[i], i + 1 < E.size()? ' ': '\n');
        }
    }
    return 0;
}