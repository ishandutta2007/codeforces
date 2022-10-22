#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int T;
int n;
vector <ii> neigh[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(ii(b, i));
            neigh[b].push_back(ii(a, i));
        }
        bool fall = false;
        for (int i = 1; i <= n && !fall; i++)
            fall = neigh[i].size() >= 3;
        if (fall) { printf("-1\n"); continue; }
        int r = 1;
        while (neigh[r].size() > 1) r++;
        int A = 2, B = 3;
        int p = 0;
        do {
            int pnt = 0;
            while (neigh[r][pnt].first == p) pnt++;
            res[neigh[r][pnt].second] = A;
            swap(A, B);
            p = r; r = neigh[r][pnt].first;
        } while (neigh[r].size() > 1);
        for (int i = 0; i < n - 1; i++)
            printf("%d%c", res[i], i + 1 < n - 1? ' ': '\n');
    }
    return 0;
}