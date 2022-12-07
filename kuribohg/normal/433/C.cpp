#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,m;
long long a[100010],p[100010],n0[100010],s,ans;
vector<long long> v[100010];
int main()
{
    scanf("%d%d",&n,&m);
    if(m==1) {puts("0");return 0;}
    for(int i=1;i<=m;i++)
        scanf("%I64d",&a[i]);
    for(int i=1;i<m;i++)
        s+=abs(a[i]-a[i+1]);
    p[a[1]]+=abs(a[1]-a[2]);
    for(int i=2;i<m;i++)
        p[a[i]]+=abs(a[i]-a[i-1])+abs(a[i]-a[i+1]);
    p[a[m]]+=abs(a[m]-a[m-1]);
    if(a[2]!=a[1]) v[a[1]].push_back(a[2]);
    for(int i=2;i<m;i++)
    {
        if(a[i-1]!=a[i]) v[a[i]].push_back(a[i-1]);
        if(a[i+1]!=a[i]) v[a[i]].push_back(a[i+1]);
    }
    if(a[m]!=a[m-1]) v[a[m]].push_back(a[m-1]);
    for(int i=1;i<=n;i++)
        sort(v[i].begin(),v[i].end());
    for(int i=1;i<=n;i++)
    {
        int len=v[i].size();
        for(int j=1;j<=(len>>1);j++)
            n0[i]+=v[i][len-j]-v[i][j-1];
    }
    ans=s;
    for(int i=1;i<=n;i++)
        ans=min(ans,s-p[i]+n0[i]);
    printf("%I64d\n",ans);
    return 0;
}