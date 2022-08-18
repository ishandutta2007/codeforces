#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
 
 
long long min(long long a, long long b)
{
    if (a < b)
        return a;
    else 
        return b;
}
 
long long max(long long a, long long b)
{
    if (a < b)
        return b;
    else 
        return a;
}
 
 
int main ( int argc, char * argv[] )
{
    long long n, k;
    scanf("%lld%lld", &n, &k);
    long long a[510];
    long long cntAns[510];
    for (int i = 0; i < 510; i++)
        cntAns[i] = 0;
    long long ans;
    long long curNotTaken, pos;
    for (int i = 1; i <= k + 1;i++)
    {
        curNotTaken = i;
        printf("? ");
        for (int j = 1; j <= k + 1; j++)
        {
            if (j != curNotTaken)
                printf("%d ", j);
        }
        printf("\n");
        fflush(stdout);
        scanf("%lld %lld", &pos, &ans);
        a[pos] = ans;
        cntAns[pos]++;
    }
    long long posMax, valMax = -1;
    for (int i = 0; i < 510; i++)
    {
        if (cntAns[i] != 0 && a[i] > valMax)
        {
            valMax = a[i];
            posMax = i;
        }
    }
    printf("! %lld\n", cntAns[posMax]);
    return 0;
}