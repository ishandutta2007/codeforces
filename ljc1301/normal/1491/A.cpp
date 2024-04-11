#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,q,a[maxn],cnt;
int main()
{
    int i;
    scanf("%d%d",&n,&q);
    cnt=0;
    for(i=1;i<=n;i++) scanf("%d",&a[i]),cnt+=a[i];
    while(q--)
    {
        scanf("%d",&i);
        if(i==1) scanf("%d",&i),cnt-=a[i],a[i]^=1,cnt+=a[i];
        else scanf("%d",&i),printf("%d\n",(i<=cnt)?1:0);
    }
    return 0;
}