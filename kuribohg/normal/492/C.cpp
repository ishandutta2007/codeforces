#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=1000010;
struct Node{LL a,b;}c[MAXN];
int n;
LL r,avg,p,ans;
bool cmp(const Node &i,const Node &j)
{
    return i.b<j.b;
}
int main()
{
    scanf("%d%I64d%I64d",&n,&r,&avg);
    for(int i=1;i<=n;i++) scanf("%I64d%I64d",&c[i].a,&c[i].b);
    sort(c+1,c+n+1,cmp);
    p=avg*n;
    for(int i=1;i<=n;i++) p-=c[i].a;
    if(p<0) p=0;
    for(int i=1;i<=n;i++)
    {
        LL x=min(p,r-c[i].a);
        ans+=x*c[i].b;
        p-=x;
    }
    printf("%I64d\n",ans);
    return 0;
}