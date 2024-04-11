#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=1000010;
int n,MOD,a[MAXN],s[MAXN],cntl[MAXN],cntr[MAXN];
LL ans;
void solve(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)>>1;
    int curl=mid,curr=mid+1,maxl=0,maxr=0,suml=0,sumr=0;
    while(curl>=l||curr<=r)
    {
        if((curr>r)||(curl>=l&&max(a[curl],maxl)<=max(a[curr],maxr)))
        {
            suml=(suml+a[curl])%MOD;
            maxl=max(maxl,a[curl]);
            s[curl]=suml;
            cntl[s[curl]]++;
            curl--;
            int x=(maxl-suml+MOD)%MOD;
            ans+=cntr[x];
        }
        else
        {
            sumr=(sumr+a[curr])%MOD;
            maxr=max(maxr,a[curr]);
            s[curr]=sumr;
            cntr[s[curr]]++;
            curr++;
            int x=(maxr-sumr+MOD)%MOD;
            ans+=cntl[x];
        }
    }
    for(int i=l;i<=mid;i++) cntl[s[i]]--;
    for(int i=mid+1;i<=r;i++) cntr[s[i]]--;
    solve(l,mid);
    solve(mid+1,r);
}
int main()
{
    scanf("%d%d",&n,&MOD);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    solve(1,n);
    printf("%I64d\n",ans);
    return 0;
}