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
const int modo = 1000000007;
int power(int x,int y)
{
    if (y==0)
    {
        return 1;
    }
    int t = power(x,y/2);
    t=(long long)t*t%modo;
    if (y%2==1)
    {
        t=(long long)t*x%modo;
    }
    return t;
}
int fact[100005];
int anti_fact[100005];
int c(int x,int y)
{
    return (long long)fact[x] * anti_fact[y] % modo * anti_fact[x-y] % modo; 
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,k;
    scanf("%d%d",&n,&k);
    if (k>=n)
    {
        k=n;
    }
    int i;
    fact[0] = 1;
    anti_fact[0] = 1;
    for (i=1;i<=n;i++)
    {
        fact[i] = (long long)fact[i-1] * i%modo;
        anti_fact[i] = power(fact[i], modo-2);
    }
    int sum = 0;
    for (i=0;i<=k;i++)
    {
        sum = (sum + c(n,i))%modo;
    }
    printf("%d\n",sum);
    return 0;
}