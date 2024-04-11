#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int const nax = 1024;
int n;
int a[nax][nax];
int cst[nax];
int k;
int bar[nax];
int memo_change[512 * 512];
vector <pair <int, int>> ans;
vector <pair <int, int>> prep[nax * 4];
int used;

int construct(vector < pair <int, int>> &x) {
    int rt_cost = 0;
    for (const auto &[u, v] : x)
        rt_cost = max(rt_cost, a[u][v]);
    int top = 0;
    int top_memo = 0;

    if (x.size() == 1) {
        auto &[i, j] = x[0];
        cst[i] = a[i][j];
        return i;
    }

    for (auto &[i, j] : x) {
        int cost = a[i][j];
        if (cost != rt_cost) {
            if (bar[i] == -1 && bar[j] == -1) {
                ++ top;
                bar[i] = bar[j] = top;
            } else {
                int s = max(bar[i], bar[j]);
                bar[i] = bar[j] = s;
            }
            memo_change[top_memo ++] = i;
            memo_change[top_memo ++] = j;
        }
    }

    for (auto &[i, j] : x) {
        int cost = a[i][j];
        if (bar[i] == -1) continue;
        if (cost != rt_cost && (bar[i] == bar[j])) {
            prep[used + bar[j]].emplace_back(i, j);
        }
    }
    int old_used = used + 1;
    used = used + top + 1;
    int run_to = used;


    for (int i = 0 ; i < top_memo ; ++ i) bar[memo_change[i]] = -1;
    int now = ++ k;


    for (int i = old_used ; i < run_to ; ++ i) {
        if (!prep[i].empty()) ans.emplace_back(now, construct(prep[i]));
    }

    cst[now] = rt_cost;

    return now;
}


vector <pair <int, int>> x;

int main() {
    scanf("%d", &n);
    x.reserve(n * n);

    memset(bar, -1, sizeof(bar));

    for (int i = 1 ; i <= n ; ++ i)
    for (int j = 1 ; j <= n ; ++ j) {
        scanf("%d", &a[i][j]);
        if (i > j) continue;
        x.emplace_back(i, j);
    }

    sort(x.begin(), x.end(), [&] (const pair <int, int> &u, const pair <int, int> &v) {
        return a[u.first][u.second] > a[v.first][v.second];
    });

    k = n;

    int root = construct(x);

    printf("%d\n", k);

    for (int i = 1 ; i <= k;  ++ i) {
        printf("%d ", cst[i]);
    }
    puts("");
    printf("%d\n", root);

    for (auto &[i, j] : ans)
        printf("%d %d\n", j, i);
}
/*
15
37 39 39 40 39 39 39 39 39 39 39 39 40 40 39
39 38 39 40 39 39 39 39 39 39 39 39 40 40 39
39 39 38 40 39 39 39 39 39 39 39 39 40 40 39
40 40 40 39 40 40 40 40 40 40 40 40 40 40 40
39 39 39 40 36 37 37 39 37 37 37 37 40 40 37
39 39 39 40 37 33 37 39 35 34 37 34 40 40 37
39 39 39 40 37 37 36 39 37 37 37 37 40 40 37
39 39 39 40 39 39 39 38 39 39 39 39 40 40 39
39 39 39 40 37 35 37 39 33 35 37 35 40 40 37
39 39 39 40 37 34 37 39 35 33 37 34 40 40 37
39 39 39 40 37 37 37 39 37 37 36 37 40 40 37
39 39 39 40 37 34 37 39 35 34 37 33 40 40 37
40 40 40 40 40 40 40 40 40 40 40 40 39 40 40
40 40 40 40 40 40 40 40 40 40 40 40 40 39 40
39 39 39 40 37 37 37 39 37 37 37 37 40 40 36


*/