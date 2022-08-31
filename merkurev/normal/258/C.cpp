#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


long long mod = (long long) 1e9 + 7;

int ld[100500];
int divisor[100500][130];
int a[100500];
int n;

int getCountLess(int x)
{
    int l = -1, r = n;
    while (r - l > 1)
    {
        int m = (r + l) / 2;
        if (a[m] >= x)
            r = m;
        else
            l = m;
    }
    return l + 1;
}


long long getPow(long long x, int n)
{
    if (!n)
        return 1LL;
    long long a = getPow(x, n / 2);
    a *= a;
    a %= mod;
    if (n & 1)
    {
        a *= x;
        a %= mod;
    }
    return a;
}

int main()
{

    int cnt = 0;
    int N = 1e5;
    for (int i = 1; i <= N; i++)
    {
        int j = i;
        while (j <= N)
        {
            cnt++;
            divisor[j][ld[j]++] = i;
            j += i;
        }
    }

    

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i] );
    sort(a, a + n);
    long long ans = 0;

    for (int i = 1; i <= N; i++)
    {
        long long curans = 1;
        int len = ld[i];
        int pCount = 0;
        vector <int> C;
        for (int j = 0; j < len; j++)
        {
            int cur = divisor[i][j];
            int numGood = n - getCountLess(cur);

            int curNum = pCount - numGood;
            pCount = numGood;
            if (j)
                C.push_back(curNum);
            else if (numGood != n)
                curans = 0;
        }
        C.push_back(pCount);
        
        for (int i = 0; i < len - 1; i++)
        {
            curans *= getPow(i + 1, C[i] );
            curans %= mod;
        }
        curans = curans * ( (getPow(len, C[len - 1] ) - getPow(len - 1, C[len - 1] )  + mod) % mod);
        curans %= mod;
        ans += curans;
        ans %= mod;     
    }
    printf("%I64d", ans);



    return 0;
}