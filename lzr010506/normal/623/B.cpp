#include <bits/stdc++.h>
using namespace std;
int p1[50], p2[50], c1, c2, w[1010000], n;
long long A, B, Res, D1[1010000], D2[1010000];
int main()
{
    int i, t, j, x;
    long long s;
    scanf("%d%lld%lld",&n,&A,&B);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &w[i]);
    for(int j = -1; j <= 1; j ++)
    {
        t = w[1] + j;
        for(int i = 2; i * i <= t; i ++)
            if(t % i == 0)
            {
                while(t % i == 0)t /= i;
                p1[c1 ++] = i;
            }
        
        if(t != 1)p1[c1 ++] = t;
    }
    for(int j = -1; j <= 1; j ++)
    {
        t = w[n] + j;
        for(int i = 2; i * i <= t; i ++)
            if(t % i == 0)
            {
                while(t % i == 0) t /= i;
                p2[c2 ++] = i;
            }
        if(t != 1) p2[c2 ++] = t;
    }
    Res = n * B;
    for(int i = 0; i < c1; i ++)
    {
        x = p1[i];
        s = 0;
        D1[n + 1] = 0;
        for(int j = n; j >= 1; j --)
        {
            t = w[j] % x;
            if(t)
                if(t == 1 || t == x - 1) s += B;
                else s = Res + 1;
            D1[j] = min(s,D1[j+1]+A);
        }
        s = 0;
        for(int j = 1; j <= n; j ++)
        {
            t = w[j] % x;
            if(t)
                if(t == 1 || t == x - 1) s += B;
                else break;
            Res = min(Res, s + D1[j + 1]);
        }
    }
    for(int i = 0; i < c2; i ++)
    {
        x = p2[i];
        s = 0;
        D1[0] = 0;
        for(int j = 1; j <= n; j ++)
        {
            t = w[j] % x;
            if(t)
            {
                if(t==1||t==x-1)s+=B;
                else s = Res + 1;
            }
            D1[j] = min(s,D1[j-1]+A);
        }
        s = 0;
        for(int j = n; j >= 1; j --)
        {
            t = w[j] % x;
            if(t)
            {
                if(t == 1 || t == x - 1) s += B;
                else break;
            }
            Res = min(Res, s + D1[j-1]);
        }
    }
    printf("%lld\n",Res);
}