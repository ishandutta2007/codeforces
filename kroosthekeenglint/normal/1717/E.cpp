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
int gcd(int x,int y)
{
    if (y==0)
    {
        return x;
    }
    else
    {
        return gcd(y,x%y);
    }
}
int prime[100005];
vector<int> p[100005];
int calc(int n,int p,int s,int l=1)
{
    if (n == 0)
    {
        return 0;
    }
    return ((long long)max(s,l) * (n - n/p) + calc(n/p, p, s, l*p))%modo;
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
    for (i=2;i<=n;i++)
    {
        prime[i] = 1;
    }
    for (i=2;i<=n;i++)
    {
        if (prime[i])
        {
            int j;
            p[i].push_back(i);
            for (j=i+i;j<=n;j+=i)
            {
                prime[j] = false;
                p[j].push_back(i); 
            }
        }
    }
    int sum = 0;
    for (i=1;i<n;i++)
    {
        int x = gcd(i, n);
        int ans = 1;
        int j;
        for (j=0;j<p[n-i].size();j++)
        {
            int the_p = p[n-i][j];
            int t1 = 1;
            int temp;
            for (temp=n-i ; temp % the_p == 0; temp=temp/the_p)
            {
                t1 *= the_p;
            }
            int t2 = 1;
            for (temp=i ; temp % the_p == 0; temp=temp/the_p)
            {
                t2 *= the_p;
            }
            t2 = min(t2, t1);
            ans = (long long)ans * calc(t1, the_p, t2) % modo;
        }
        ans = (ans - (n-i) + modo) % modo;
        ans = (long long)ans * (i/x) % modo;
        sum = (sum + ans)%modo;
    }
    printf("%d\n",sum);
    return 0;
}