#include <bits/stdc++.h>

#define prev AZAZA

using namespace std;

const int max_n = 1001;

char field[max_n][11][11];

int dist[max_n][max_n]; //    

vector<pair<int, int> > ans;

int mn[max_n], dist2[max_n];
int prev[max_n]; // ,      i,  dist2[i]

int main()
{
    int n, m, k, w;
    scanf("%d %d %d %d", &n, &m, &k, &w);
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%s", field[i][j]);
        }
    }

    //   
    for (int i = 0; i < k; ++i)
    {
        for (int j = i + 1; j < k; ++j)
        {
            int d = 0;
            for (int o = 0; o < n; o++)
            {
                for (int p = 0; p < m; p++)
                {
                    if (field[i][o][p] != field[j][o][p])
                    {
                        d++;
                    }
                }
            }
            dist[i][j] = min(m * n, d * w);
            dist[j][i] = dist[i][j];
        }
    }

    int SUM = n * m;

    ans.push_back(make_pair(0, -1));
    mn[0] = 1;
    for (int i = 1; i < k; i++)
    {
        mn[i] = 2;
        dist2[i] = dist[0][i];
        prev[i] = 0;
    }

    for (int i = 1; i < k; i++)
    {
        int v = -1;
        for (int j = 0; j < k; j++)
        {
            if (mn[j] == 2 && (v == -1 || dist2[j] < dist2[v]))
            {
                v = j;
            }
        }
        if (dist2[v] == m * n)
        {
            ans.push_back(make_pair(v, -1));
        }
        else
        {
            ans.push_back(make_pair(v, prev[v]));
        }

        SUM += dist2[v];

        mn[v] = 1;
        for (int j = 0; j < k; j++)
        {
            if (dist2[j] > dist[v][j])
            {
                dist2[j] = dist[v][j];
                prev[j] = v;
            }
        }
    }

    printf("%d\n", SUM);

    for(int i = 0; i < k; ++i)
    {
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    }
    return 0;
}