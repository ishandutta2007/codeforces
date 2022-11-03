#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300005;
int n,h[maxn],sta[maxn],top;
ll f[maxn],b[maxn],tr[maxn<<2],sminf[maxn];
map<ll,int> maxx;
void update(int rt,int l,int r,int x)
{
    if(l==r) { tr[rt]=f[x]; return; }
    int mid=(l+r)>>1;
    if(x<=mid) update(rt<<1,l,mid,x);
    else update((rt<<1)|1,mid+1,r,x);
    tr[rt]=max(tr[rt<<1],tr[(rt<<1)|1]);
}
ll query(int rt,int l,int r,int x,int y)
{
    if(x<=l && r<=y) return tr[rt];
    int mid=(l+r)>>1;
    ll res=0x8000000000000000ll;
    if(x<=mid) res=max(res,query(rt<<1,l,mid,x,y));
    if(mid<y) res=max(res,query((rt<<1)|1,mid+1,r,x,y));
    return res;
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&h[i]);
    for(i=1;i<=n;i++) scanf("%lld",&b[i]);
    top=0,sta[0]=0,f[0]=0,update(1,0,n,0),maxx.clear();
    for(i=1;i<=n;i++)
    {
        while(top>=0 && h[sta[top]]>h[i])
        {
            if(!(maxx[sminf[top]]-=1)) maxx.erase(sminf[top]);
            top--;
        }
        sta[++top]=i,sminf[top]=b[i]+query(1,0,n,sta[top-1],i-1);
        if(!maxx.count(sminf[top])) maxx[sminf[top]]=1;
        else maxx[sminf[top]]+=1;
        f[i]=(--maxx.end())->first,update(1,0,n,i);
    }
    printf("%lld\n",f[n]);
    return 0;
}