#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;
const int Maxm = 100005;

int a, b, m;
int mx;
int cnt[Maxn];
ii E[Maxm];
ii my[Maxn][Maxn];
int res[Maxm];

void Traverse(int a, int b, int cola, int colb, int ind)
{
    if (my[a][cola].first) {
        ii p = my[a][cola];
        my[a][cola] = ii(0, 0);
        my[p.first][cola] = ii(0, 0);
        Traverse(p.first, a, colb, cola, p.second);
    }
    my[a][cola] = ii(b, ind);
    my[b][cola] = ii(a, ind);
    res[ind] = cola;
}

void Colour(int ind)
{
    int a = E[ind].first, b = E[ind].second;
    for (int i = 1; i <= mx; i++)
        if (!my[a][i].first && !my[b][i].first) {
            my[a][i] = ii(b, ind);
            my[b][i] = ii(a, ind);
            res[ind] = i;
            return;
        }
    int pnta = 1, pntb = 1;
    while (!my[a][pnta].first || my[b][pnta].first) pnta++;
    while (!my[b][pntb].first || my[a][pntb].first) pntb++;
    Traverse(a, b, pnta, pntb, ind);
}

int main()
{
    scanf("%d %d %d", &a, &b, &m);
    for (int i = 0; i < m; i++) {
        int x, y; scanf("%d %d", &x, &y);
        y += a;
        E[i] = ii(x, y);
        cnt[x]++; cnt[y]++;
    }
    for (int i = 1; i <= a + b; i++)
        mx = max(mx, cnt[i]);
    for (int i = 0; i < m; i++)
        Colour(i);
    printf("%d\n", mx);
    for (int i = 0; i < m; i++)
        printf("%d%c", res[i], i + 1 < m? ' ': '\n');
    return 0;
}