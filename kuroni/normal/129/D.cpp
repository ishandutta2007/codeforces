#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int N = 100005;

int q, n, u, pre[N], suf[N], cnt[N];
long long pw[N], hsh[N];
char s[N];

long long get_hash(int l, int r)
{
    return hsh[r] - hsh[l - 1] * pw[r - l + 1];
}

bool cmp(int u, int v)
{
    int mx = min(n - u, n - v);
    int le = 0, ri = mx;
    while (le <= ri)
    {
        int mi = (le + ri) / 2;
        if (get_hash(u, u + mi) == get_hash(v, v + mi))
            le = mi + 1;
        else
            ri = mi - 1;
    }
    if (le > mx)
        return u > v;
    else
        return s[u + le] < s[v + le];
}

int find_prefix(int u, int v)
{
    if (u == 0)
        return 0;
    int mx = min(n - u, n - v);
    int le = 0, ri = mx;
    while (le <= ri)
    {
        int mi = (le + ri) / 2;
        if (get_hash(u, u + mi) == get_hash(v, v + mi))
            le = mi + 1;
        else
            ri = mi - 1;
    }
    return le;
}

void DFS(int u, int pr)
{
    if (--q == 0)
    {
        for (int i = 0; i < pr; i++)
            putchar(s[suf[u] + i]);
        exit(0);
    }
    cnt[u] = pr;
    if (pre[u + 1] >= pr)
        DFS(u + 1, pr);
}

int main()
{
    scanf("%s%d", s + 1, &q);
    n = strlen(s + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pw[i] = pw[i - 1] * 31;
        hsh[i] = hsh[i - 1] * 31 + s[i] - 'a' + 1;
        suf[i] = i;
    }
    sort(suf + 1, suf + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        pre[i] = find_prefix(suf[i - 1], suf[i]);
    for (int i = 1; i <= n; i++)
        for (++cnt[i]; cnt[i] <= n - suf[i] + 1; ++cnt[i])
            DFS(i, cnt[i]);
    printf("No such line.");
}