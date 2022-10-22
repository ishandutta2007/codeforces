#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int p[400005];
int anti_p[400005];
const int modo=1000000007;
int power(int x,int y)
{
    if (y==0)
    {
        return 1;
    }
    int t=power(x,y/2);
    t=(long long)t*t%modo;
    if (y%2==1)
    {
        t=(long long)t*x%modo; 
    }
    return t;
}
int c(int x,int y)
{
    if (y>x)
    {
        return 0;
    }
    return (long long)p[x]*anti_p[y]%modo*anti_p[x-y]%modo;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    p[0]=1;
    for (i=1;i<=400003;i++)
    {
        p[i]=(long long)p[i-1]*i%modo;
    }
    anti_p[400003]=power(p[400003],modo-2);
    for (i=400002;i>=0;i--)
    {
        anti_p[i]=(long long)anti_p[i+1]*(i+1)%modo;
    }
    int ans=0;
    for (i=0;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        ans=(ans+c(x+i,i+1))%modo;
    }
    printf("%d\n",ans);
    return 0;
}