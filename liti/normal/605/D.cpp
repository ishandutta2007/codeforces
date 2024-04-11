#include<bits/stdc++.h>

#define SZ(x) ((int(x.size())))

typedef long long ll;

using namespace std;

const int maxn = 100*1000+10, SQ = 317;
int spell[maxn][4], n, p[maxn], pnt[SQ], c[maxn], d[maxn], cur, ja[maxn], st, fi, kmk;
vector <int> ans;
bool mark[maxn], flg;
queue <int> q;

inline bool in1 (const int &x, const int &y)
{
    return spell[x][2] < spell[y][2];
}

inline bool in2 (const int &x, const int &y)
{
    return spell[x][3] > spell[y][3];
}

inline bool cmp (const int &x, const int &y)
{
    return spell[x][2] < y;
}

inline void bfs ()
{
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (spell[cur][0] == 0 && spell[cur][1] == 0)
        {
            while (cur >= 0)
            {
                ans.push_back (cur + 1);
                cur = p[cur];
            }
            printf("%d\n", SZ(ans));
            for (int i = 0; i < SZ(ans); i++)
                printf("%d ", ans[i]);
            flg = 1;
        }
        if (flg)
            break;
        st = lower_bound (c, c + n, spell[cur][0], cmp) - c;
        fi = min (n, (st / SQ + 1) * SQ);
        for (int i = st; i < fi; i++)
        {
            if (spell[c[i]][3] >= spell[cur][1] && !mark[ja[c[i]]])
            {
                mark[ja[c[i]]] = 1;
                p[c[i]] = cur;
                q.push (c[i]);
            }
        }
        fi = (n + SQ - 1) / SQ;
        for (int i = st / SQ + 1; i < fi; i++)
        {
            kmk = min (n, (i + 1) * SQ);
            while (pnt[i] < kmk)
            {
                if (mark[pnt[i]])
                    pnt[i]++;
                else
                {
                    if (spell[d[pnt[i]]][3] >= spell[cur][1])
                    {
                        p[d[pnt[i]]] = cur;
                        mark[pnt[i]] = 1;
                        q.push (d[pnt[i]]);
                        pnt[i]++;
                    }
                    else
                        break;
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &spell[i][0], &spell[i][1], &spell[i][2], &spell[i][3]);
        p[i] = -1;
        c[i] = i;
    }
    sort (c, c + n, in1);
    for (int i = 0; i < n; i++)
        d[i] = c[i];
    for (int i = 0; i < n; i += SQ)
    {
        sort (d + i, d + min (n, i +  SQ), in2);
        

        pnt[i / SQ] = i;
    }
    for (int i = 0; i < n; i++)
        ja[d[i]] = i;
    q.push(n - 1);
    mark[ja[n - 1]] = 1;
    bfs ();
    if (!flg)
        printf("-1");
    return 0;
}