#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=200010;
int n,m;
LL L,R,mid,a[MAXN],b[MAXN];
bool check()
{
    for(int i=1;i<=n;i++) b[i]=a[i];
    int cur=n;
    for(int i=1;i<=m;i++)
    {
        while(cur>=1&&b[cur]<=0) cur--;
        if(cur==0) return true;
        LL x=mid-cur;
        while(true)
        {
            if(b[cur]>=x) {b[cur]-=x;break;}
            else
            {
                x-=b[cur],b[cur]=0;
                while(cur>=1&&b[cur]<=0) cur--;
                if(cur==0) return true;
            }
        }
    }
    for(int i=1;i<=n;i++) if(b[i]>0) return false;
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]),R+=a[i];
    R+=(LL)n;
    while(L<R)
    {
        mid=(L+R)>>1;
        if(check()) R=mid;
        else L=mid+1;
    }
    printf("%I64d\n",L);
    return 0;
}