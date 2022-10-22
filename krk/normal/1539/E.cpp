#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxm = 524288;

int n, m;
int a[Maxn];
int L1[Maxn], R1[Maxn];
int L2[Maxn], R2[Maxn];
vector <int> un;
int st[2][Maxm], er[2][Maxm];
int dp[Maxn][2];
int res[Maxn];

void downOn(int t, int v)
{
    st[t][v] = 0;
    er[t][v] = true;
}

void Down(int t, int v)
{
    if (er[t][v]) {
        downOn(t, 2 * v);
        downOn(t, 2 * v + 1);
        er[t][v] = false;
    }
}

void Union(int t, int v)
{
    st[t][v] = max(st[t][2 * v], st[t][2 * v + 1]);
}

void Clear(int t, int v, int l, int r, int a, int b)
{
    if (l == a && r == b) downOn(t, v);
    else {
        Down(t, v);
        int m = l + r >> 1;
        if (a <= m) Clear(t, 2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) Clear(t, 2 * v + 1, m + 1, r, max(m + 1, a), b);
        Union(t, v);
    }
}

void Set(int t, int v, int l, int r, int x, int val)
{
    if (l == r) st[t][v] = val;
    else {
        Down(t, v);
        int m = l + r >> 1;
        if (x <= m) Set(t, 2 * v, l, m, x, val);
        else Set(t, 2 * v + 1, m + 1, r, x, val);
        Union(t, v);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n + 1; i++) {
        scanf("%d", &a[i]);
        un.push_back(a[i]);
        scanf("%d %d", &L1[i], &R1[i]);
        scanf("%d %d", &L2[i], &R2[i]);
    }
    un.push_back(0);
    sort(un.begin(), un.end());
    un.erase(unique(un.begin(), un.end()), un.end());
    Set(0, 1, 0, int(un.size()) - 1, 0, 1);
    Set(1, 1, 0, int(un.size()) - 1, 0, 1);
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= n + 1; i++) {

        int ind = lower_bound(un.begin(), un.end(), L2[i]) - un.begin();
        if (ind > 0) Clear(0, 1, 0, int(un.size()) - 1, 0, ind - 1);
        ind = upper_bound(un.begin(), un.end(), R2[i]) - un.begin();
        if (ind < un.size()) Clear(0, 1, 0, int(un.size()) - 1, ind, int(un.size()) - 1);

        ind = lower_bound(un.begin(), un.end(), L1[i]) - un.begin();
        if (ind > 0) Clear(1, 1, 0, int(un.size()) - 1, 0, ind - 1);
        ind = upper_bound(un.begin(), un.end(), R1[i]) - un.begin();
        if (ind < un.size()) Clear(1, 1, 0, int(un.size()) - 1, ind, int(un.size()) - 1);

        ind = lower_bound(un.begin(), un.end(), a[i - 1]) - un.begin();

        if (L1[i] <= a[i] && a[i] <= R1[i]) {
            if (L2[i] <= a[i - 1] && a[i - 1] <= R2[i] && dp[i - 1][1])
                Set(0, 1, 0, int(un.size()) - 1, ind, i - 1);
            dp[i][0] = st[0][1];
        } else Clear(0, 1, 0, int(un.size()) - 1, 0, int(un.size()) - 1);

        if (L2[i] <= a[i] && a[i] <= R2[i]) {
            if (L1[i] <= a[i - 1] && a[i - 1] <= R1[i] && dp[i - 1][0])
                Set(1, 1, 0, int(un.size()) - 1, ind, i - 1);
            dp[i][1] = st[1][1];
        } else Clear(1, 1, 0, int(un.size()) - 1, 0, int(un.size()) - 1);
    }
    int i = n + 1, j = 0;
    while (j < 2 && !dp[i][j]) j++;
    if (j >= 2) { printf("No\n"); return 0; }
    printf("Yes\n");
    while (i > 1) {
        int to = dp[i][j];
        while (i > to) { res[i] = j; i--; }
        j = 1 - j;
    }
    for (int i = 2; i <= n + 1; i++)
        printf("%d%c", res[i], i + 1 <= n + 1? ' ': '\n');
    return 0;
}