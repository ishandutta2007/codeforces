#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...)
#endif


const int SZ = (int) 1e6 + 100;
char f[SZ];
bool usedS[SZ], usedT[SZ];

pair <int, int> qu[SZ];
int n, m;

char F(int i, int j)
{
    return f[i * m + j];
}
void setUsedS(int i, int j)
{
    usedS[i * m + j] = true;
}
bool UsedS(int i, int j)
{
    return usedS[i * m + j];
}
void setUsedT(int i, int j)
{
    usedT[i * m + j] = true;
}
bool UsedT(int i, int j)
{
    return usedT[i * m + j];
}
bool inF(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

const int DX[4] = {0, 1, 0, -1};
const int DY[4] = {1, 0, -1, 0};


int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", f + i * m);

    int qul = 0, qur = 0;
    qu[qur++] = make_pair(0, 0);
    setUsedS(0, 0);

    while (qul < qur)
    {
        int x = qu[qul].first, y = qu[qul].second;
        qul++;

        for (int d = 0; d < 2; d++)
        {
            int nx = x + DX[d], ny = y + DY[d];
            if (!inF(nx, ny)) continue;
            if (UsedS(nx, ny)) continue;
            if (F(nx, ny) == '#') continue;
            setUsedS(nx, ny);
            qu[qur++] = make_pair(nx, ny);
        }
    }
    qul = 0, qur = 0;
    qu[qur++] = make_pair(n - 1, m - 1);
    setUsedT(n - 1, m - 1);

    while (qul < qur)
    {
        int x = qu[qul].first, y = qu[qul].second;
        qul++;

        for (int d = 2; d < 4; d++)
        {
            int nx = x + DX[d], ny = y + DY[d];
            if (!inF(nx, ny)) continue;
            if (UsedT(nx, ny)) continue;
            if (F(nx, ny) == '#') continue;
            setUsedT(nx, ny);
            qu[qur++] = make_pair(nx, ny);
        }
    }

    map <int, int> cnt;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (UsedS(i, j) && UsedT(i, j))
                cnt[i + j]++;
        }
    int mn = 2;
    for (int i = 1; i < n + m - 2; i++)
        mn = min(mn, cnt[i]);
    printf("%d\n", mn);
    

    return 0;
}