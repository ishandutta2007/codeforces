#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<ctime>
#include<queue>
#include<utility>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,m,in1,in2;
long long w[100010],ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&w[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&in1,&in2);
        ans+=min(w[in1],w[in2]);
    }
    printf("%I64d\n",ans);
    return 0;
}