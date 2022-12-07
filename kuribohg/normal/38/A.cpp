#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,d[110],l,r,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++) scanf("%d",&d[i]);
    scanf("%d%d",&l,&r);
    for(int i=l;i<r;i++) ans+=d[i];
    printf("%d\n",ans);
    return 0;
}