#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=1000010;
long long n,d,ans,in1,in2,a,b,now,c[MAXN];
pair<long long,long long> p[MAXN];
int main()
{
    scanf("%I64d%I64d",&n,&d);
    scanf("%I64d%I64d",&a,&b);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&in1,&in2);
        p[i].first=in1*a+in2*b;
        p[i].second=i;
    }
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)
        if(now+p[i].first<=d) now+=p[i].first,c[++ans]=p[i].second;
    printf("%I64d\n",ans);
    for(int i=1;i<ans;i++)
        printf("%I64d ",c[i]);
    if(ans) printf("%I64d\n",c[ans]);
    else puts("");
    return 0;
}