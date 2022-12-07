#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,m,w[100010],in1,in2,in3;
double ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&in1,&in2,&in3);
        ans=max(ans,(w[in1]+w[in2])*1.0/in3);
    }
    printf("%.15lf\n",ans);
    return 0;
}