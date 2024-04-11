#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int c[100000];
int GCD(int a,int b)
{
    if (a % b == 0)
        return b;
    return GCD(b , a % b);
}
int main()
{
    int a,b;
    int num = 0;
    scanf ("%d %d",&a,&b);
    int g = GCD (a,b);
    int l = sqrt ((double)g);
    for (int i = 1 ; i <= l ; i++)
    {
        if (g % i == 0)
        {
            c[num++] = i;
            c[num++] = g / i;
        }
    }
    sort (c , c + num);
    int m;      //
    scanf ("%d",&m);
    while (m--)
    {
        int l,r;
        scanf ("%d %d",&l,&r);
        int t = upper_bound(c , c + num , r) - c - 1;
        //
        if (c[t] < l)
            printf ("-1\n");
        else
            printf ("%d\n",c[t]);
    }
    return 0;
}