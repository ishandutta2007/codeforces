#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
int n,m;
LL ans1,ans2;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=(n%m);i++)
        ans1+=(LL)(n/m)*(n/m+1)/2;
    for(int i=n%m+1;i<=m;i++)
        ans1+=(LL)(n/m)*(n/m-1)/2;
    ans2=(LL)(n-m+1)*(n-m)/2;
    printf("%I64d %I64d\n",ans1,ans2);
    return 0;
}