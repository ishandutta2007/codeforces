#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

long long best[150001];
long long st[18][150001];
int maxpow[150001];
int n;

void build()
{
    for(int i = 1; i <= n; i++) 
        st[0][i] = best[i];
    for(int power = 1; power <= 17; power++)
        for(int i = 1; i <= n; i++)
            st[power][i] = max(st[power - 1][i], st[power - 1][min(n, i + (1 << power - 1))]);
}

long long getbest(int a, int b)
{
    if(a == b)
        return st[0][a];
    int dist = b - a + 1;
    return max(st[maxpow[dist]][a], st[maxpow[dist]][b - (1 << maxpow[dist]) + 1]);
}

int main()
{
    int m,d;
    int tlast = 0;
    scanf("%d%d%d", &n, &m, &d);
    for(int i = 1; i <= n; i++)
        best[i] = 0;
    maxpow[1] = 0;
    for(int i = 1; i <= n; i++)
    {
        maxpow[i] = maxpow[i - 1];
        while(1 << maxpow[i] + 1 <= i)
            maxpow[i]++;
    }

    for(int launch = 1; launch <= m; launch++)
    {
        int a,b,t;
        scanf("%d%d%d", &a, &b, &t);
        long long s = (t - tlast) * (long long)d;
        tlast = t;

        build();
        for(int i = 1; i <= n; i++)
            best[i] = getbest(max(1ll, i - s), min((long long)n, i + s)) - abs(i - a) + b;
    }   

    long long ans = -1000000000;
    for(int i = 1; i <= n; i++)
        ans = max(ans, best[i]);

    printf("%I64d\n", ans);

    return 0;
}