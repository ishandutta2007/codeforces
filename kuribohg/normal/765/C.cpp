#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int k,a,b,ans;
int main()
{
    scanf("%d%d%d",&k,&a,&b);
    ans=a/k+b/k;
    if((a/k==0&&b%k!=0)||(b/k==0&&a%k!=0)) puts("-1");
    else printf("%d\n",ans);
    return 0;
}