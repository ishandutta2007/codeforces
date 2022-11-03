#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100005;
int n,a,b,f;
int s[N],sum;
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]),sum+=s[i];
    f=s[1];
    if((double)(f*a)/sum>=b){puts("0");return 0;}
    sort(s+2,s+n+1);
    for(int i=n;i>=2;i--)
    {
        sum-=s[i];
        if((double)(f*a)/sum>=b){printf("%d",n-i+1);return 0;}
    }
    printf("%d",n);
    return 0;
}