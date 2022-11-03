#include<iostream>
#include<cstdio>
using namespace std;
long long n,q;

int main()
{
    scanf("%I64d%I64d",&n,&q);
    long long t,ans;
    for(int i=1;i<=q;i++)
    {
        scanf("%I64d",&t);
        ans=0;
        while(t!=1)
        {
            ans+=(t-1)/2;
            t=t%2;
            if(t==0) t=n-ans-1,ans++;
        }
        printf("%I64d\n",ans+1);
    }
    return 0;
}