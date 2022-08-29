#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

long long q[100500];
long long a[100500];
long long d[100500];
long long cnt[100500];
long long l[100500], r[100500], x[100500];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i] );
    for (int i = 0; i < m; i++)
	{
        scanf("%I64d%I64d%I64d", &l[i], &r[i], &x[i] );
        l[i]--;
        r[i]--;
	}
    for (int i = 0; i < k; i++)
	{
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        cnt[a]++;
        cnt[b + 1]--;
	}
    long long curcnt = 0;
    for (int i = 0; i < m; i++)
	{
        curcnt += cnt[i];
        long long X = x[i] * curcnt;
        q[l[i] ] += X;
        q[r[i] + 1] -= X;
	}

    long long curans = 0;
    for (int i = 0; i < n; i++)
	{
        curans += q[i];
        printf("%I64d ", curans + a[i] );
	}



    return 0;
}