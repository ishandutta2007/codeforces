#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=300010;
LL ans;
int n,m,k,x;
int a[MAXN],pos[MAXN];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) pos[a[i]]=i;
    for(int T=1;T<=m;T++)
    {
        scanf("%d",&x);
        int p=pos[x];
        ans+=(LL)((p-1)/k+1);
        if(p>1)
        {
            swap(a[p],a[p-1]);
            pos[a[p-1]]=p-1;
            pos[a[p]]=p;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}