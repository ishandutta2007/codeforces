#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
typedef long long LL;
LL n;
pair<int,LL> res;
void DFS(LL x,int ans,LL c)
{
    res=max(res,make_pair(ans,c));
    LL o=0;
    while(o*o*o<=x) o++;o--;
    if(o!=0) DFS(x-o*o*o,ans+1,c+o*o*o);
    if(o!=1&&o!=0) DFS(o*o*o-1-(o-1)*(o-1)*(o-1),ans+1,c+(o-1)*(o-1)*(o-1));
}
int main()
{
    scanf("%I64d",&n);
    DFS(n,0,0);
    printf("%d %I64d\n",res.first,res.second);
    return 0;
}