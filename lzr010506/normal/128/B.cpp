#include <bits/stdc++.h>
using namespace std;
const double eps(1e-8);
typedef long long ll;

#define N 100010

int wa[N], wb[N], wv[N], Ws[N];

int cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int *r, int *sa, int n, int m)
{
    int *x = wa, *y = wb, *t, i, j, p;
    for(i = 0; i < m; i++) Ws[i] = 0;
    for(i = 0; i < n; i++) Ws[x[i] = r[i]]++;
    for(i = 1; i < m; i++) Ws[i] += Ws[i - 1];
    for(i = n - 1; i >= 0; i--) sa[--Ws[x[i]]] = i;
    for(j = 1, p = 1; p < n; j *= 2, m = p)
    {
        for(p = 0, i = n - j; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;	
        for(i = 0; i < n; i++) wv[i] = x[y[i]];
        for(i = 0; i < m; i++) Ws[i] = 0;
        for(i = 0; i < n; i++) Ws[wv[i]]++;
        for(i = 1; i < m; i++) Ws[i] += Ws[i - 1];
        for(i = n - 1; i >= 0; i--) sa[--Ws[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
    return;
}

int Rk[N], Hk[N];
void calHk(int *r, int *sa, int n)
{
    int i, j, k = 0;
    for(i = 1; i <= n; i++) Rk[sa[i]] = i;
    for(i = 0; i < n; Hk[Rk[i++]] = k)
        for(k ? k-- : 0, j = sa[Rk[i] - 1]; r[i + k] == r[j + k]; k++);
    return;
}

char in[N];
int s[N], sa[N], K, a[N];

void findK(int n)
{
    memset(a, 0, sizeof(a));
    int r = 1;
    while(K)
    {
        a[r]++;
        if(a[r] > n - sa[r])
        {
            r++;
            continue;
        }
        K--;
        for(int j = r + 1; j <= n && Hk[j] >= a[r] && K; j++)
            a[j]++, K--;
    }
    for(int i = 0; i < a[r]; i++)
        printf("%c", in[sa[r] + i]);
    printf("\n");
    return;
}

int main()
{
    scanf("%s%d", in, &K);
    int n = strlen(in);
    ll kinds = (ll)n*((ll)n + 1LL)/2LL;
    if(kinds < K)
    {
        printf("No such line.\n");
        return 0;
    }
    for(int i = 0; i < n; i++)
        s[i] = in[i] - 'a' + 1;
    s[n] = 0;
    da(s, sa, n + 1, 27);
    calHk(s, sa, n);
    findK(n);
    return 0;
}