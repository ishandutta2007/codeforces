#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
typedef long long LL;
LL l,r,ans;
set<LL> S;
int main()
{
    scanf("%I64d%I64d",&l,&r);
    for(int i=0;i<=62;i++)
    {
        LL x=1LL<<i;
        for(int j=0;j<i-1;j++)
            S.insert(x-((1LL)<<j)-1);
    }
    for(set<LL>::iterator it=S.begin();it!=S.end();++it)
        if(l<=(*it)&&(*it)<=r) ans++;
    printf("%I64d\n",ans);
    return 0;
}