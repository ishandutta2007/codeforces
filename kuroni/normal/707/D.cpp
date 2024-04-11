#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

struct question
{
    int type, u, v;
} query[100005];
vector <int> adj[100005];
int n, m, q, i, j, row_sum[1005], sum = 0, ans[100005];
bool invert[1005], check[1005][1005];

void DFS(int i)
{
    bool work = 0;
    if (i != 0 && query[i].type != 4)
    {
        if (query[i].type == 1 && !(check[query[i].u][query[i].v] ^ invert[query[i].u]))
        {
            work = 1;
            check[query[i].u][query[i].v] = !check[query[i].u][query[i].v];
            sum++;
            row_sum[query[i].u]++;
        }
        else if (query[i].type == 2 && (check[query[i].u][query[i].v] ^ invert[query[i].u]))
        {
            work = 1;
            check[query[i].u][query[i].v] = !check[query[i].u][query[i].v];
            sum--;
            row_sum[query[i].u]--;
        }
        else if (query[i].type == 3)
        {
            work = 1;
            invert[query[i].u] = !invert[query[i].u];
            sum -= 2 * row_sum[query[i].u] - m;
            row_sum[query[i].u] = m - row_sum[query[i].u];
        }
    }
    ans[i] = sum;
    for (int j = 0; j < adj[i].size(); j++)
        DFS(adj[i][j]);
    if (work)
    {
        if (query[i].type == 1)
        {
            check[query[i].u][query[i].v] = !check[query[i].u][query[i].v];
            sum--;
            row_sum[query[i].u]--;
        }
        else if (query[i].type == 2)
        {
            check[query[i].u][query[i].v] = !check[query[i].u][query[i].v];
            sum++;
            row_sum[query[i].u]++;
        }
        else if (query[i].type == 3)
        {
            invert[query[i].u] = !invert[query[i].u];
            sum -= 2 * row_sum[query[i].u] - m;
            row_sum[query[i].u] = m - row_sum[query[i].u];
        }
    }
}

int main()
{
    memset(check, 0, sizeof(check));
    memset(row_sum, 0, sizeof(row_sum));
    scanf("%d%d%d", &n, &m, &q);
    for (i = 1; i <= q; i++)
    {
        scanf("%d%d", &query[i].type, &query[i].u);
        if (query[i].type == 1 || query[i].type == 2)
            scanf("%d", &query[i].v);
        if (query[i].type == 4)
            adj[query[i].u].push_back(i);
        else adj[i - 1].push_back(i);
    }
    DFS(0);
    for (i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
}