#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,q,op,in1,in2;
long long a[100010],s[100010][3];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    for(int i=1;i<=n;i++) s[i][1]=s[i-1][1]+a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i][2]=s[i-1][2]+a[i];
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d%d",&op,&in1,&in2);
        printf("%I64d\n",s[in2][op]-s[in1-1][op]);
    }
    return 0;
}