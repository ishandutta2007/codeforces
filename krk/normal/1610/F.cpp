#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n, m;
int A[Maxn], B[Maxn], C[Maxn];
set <ii> ones[Maxn], twos[Maxn];
ii res[Maxn];
int ans;
char str[Maxn];

void takeOutOne(int v, int u, int ind)
{
    res[ind] = ii(u, v);
    ones[v].erase(ii(u, ind));
    ones[u].erase(ii(v, ind));
}

void takeOutTwo(int v, int u, int ind)
{
    res[ind] = ii(u, v);
    twos[v].erase(ii(u, ind));
    twos[u].erase(ii(v, ind));
}

void Traverse(int v, int pref)
{
    if (ones[v].size() % 2 == 0 && twos[v].size() % 2 == 0) return;
    if (pref == 1) {
        if (ones[v].size() % 2 == 1) {
            int u = ones[v].begin()->first, ind = ones[v].begin()->second;
            takeOutOne(v, u, ind);
            Traverse(u, 1);
        } else {
            int u = twos[v].begin()->first, ind = twos[v].begin()->second;
            takeOutTwo(v, u, ind);
            Traverse(u, 2);
        }
    } else {
        if (twos[v].size() % 2 == 1) {
            int u = twos[v].begin()->first, ind = twos[v].begin()->second;
            takeOutTwo(v, u, ind);
            Traverse(u, 2);
        } else {
            int u = ones[v].begin()->first, ind = ones[v].begin()->second;
            takeOutOne(v, u, ind);
            Traverse(u, 1);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &A[i], &B[i], &C[i]);
        if (C[i] == 1) {
            ones[A[i]].insert(ii(B[i], i));
            ones[B[i]].insert(ii(A[i], i));
        } else {
            twos[A[i]].insert(ii(B[i], i));
            twos[B[i]].insert(ii(A[i], i));
        }
    }
    for (int i = 1; i <= n; i++)
        if (ones[i].size() % 2 == 1) ans++;
    for (int i = 1; i <= n; i++)
        if (ones[i].size() % 2 == 1 && twos[i].size() % 2 == 0) {
            int u = ones[i].begin()->first, ind = ones[i].begin()->second;
            takeOutOne(i, u, ind);
            Traverse(u, 1);
        }
    for (int i = 1; i <= n; i++)
        if (ones[i].size() % 2 == 0 && twos[i].size() % 2 == 1) {
            int u = twos[i].begin()->first, ind = twos[i].begin()->second;
            takeOutTwo(i, u, ind);
            Traverse(u, 2);
        }
    for (int i = 1; i <= n; i++)
        while (!ones[i].empty() || !twos[i].empty())
            if (!ones[i].empty()) {
                int u = ones[i].begin()->first, ind = ones[i].begin()->second;
                takeOutOne(i, u, ind);
                Traverse(u, 1);
            } else {
                int u = twos[i].begin()->first, ind = twos[i].begin()->second;
                takeOutTwo(i, u, ind);
                Traverse(u, 2);
            }
    for (int i = 0; i < m; i++)
        str[i] = A[i] == res[i].first? '1': '2';
    str[m] = '\0';
    printf("%d\n", ans);
    printf("%s\n", str);
    return 0;
}