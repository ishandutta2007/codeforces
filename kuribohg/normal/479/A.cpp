#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int a,b,c,ans[10],tot,ans1;
int main()
{
    ans1=-2e9;
    scanf("%d%d%d",&a,&b,&c);
    ans[++tot]=a+b+c;
    ans[++tot]=a*b+c;
    ans[++tot]=a+b*c;
    ans[++tot]=a*b*c;
    ans[++tot]=(b+c)*a;
    ans[++tot]=(a+b)*c;
    for(int i=1;i<=tot;i++) ans1=max(ans1,ans[i]);
    printf("%d\n",ans1);
    return 0;
}