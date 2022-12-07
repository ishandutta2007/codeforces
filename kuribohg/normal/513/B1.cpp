#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int n,cur;
LL m;
int ans[110],s1,s2;
int main()
{
    scanf("%d%I64d",&n,&m);
    s2=n+1;
    m--;
    for(int i=n-2;i>=0;i--)
    {
        cur++;
        if(m&(1LL<<i)) ans[--s2]=cur;
        else ans[++s1]=cur;
    }
    cur++;
    ans[++s1]=cur;
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}