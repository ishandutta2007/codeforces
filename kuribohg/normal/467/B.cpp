#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,m,k,d[2000010],a[1010],ans;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m+1;i++) scanf("%d",&a[i]);
    for(int i=1;i<(1<<n);i++) d[i]=d[i>>1]+(i&1);
    for(int i=1;i<=m;i++) if(d[a[i]^a[m+1]]<=k) ans++;
    printf("%d\n",ans);
    return 0;
}