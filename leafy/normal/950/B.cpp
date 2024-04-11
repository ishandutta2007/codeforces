#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100005
int n,m;
int x[N],y[N];
int sum[N];
int j=1;
inline bool finded(int x)
{
    int l=j,r=m;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(sum[mid]-sum[j-1]==x) {j=mid+1;return 1;}
        else if(sum[mid]-sum[j-1]<x) l=mid+1;
        else r=mid-1;
    }
    return 0;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    for(int i=1;i<=m;i++) scanf("%d",&y[i]),sum[i]=sum[i-1]+y[i];
    int i=1,ans=0;long long sum=0;
    while(i<=n)
    {
        sum+=x[i];
        if(finded(sum)) sum=0,ans++;
        i++;
    }
    cout<<ans;
    return 0;
}