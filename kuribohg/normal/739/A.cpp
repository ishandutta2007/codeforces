#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
int n,m,ans=1000000000;
int L[MAXN],R[MAXN],a[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&L[i],&R[i]);
    for(int i=1;i<=m;i++) ans=min(ans,R[i]-L[i]+1);
    for(int i=0;i<n;i++) a[i]=i%ans;
    printf("%d\n",ans);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}