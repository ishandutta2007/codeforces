#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1<<20;
int n,m,a[MAXN],c[MAXN];
struct Seg
{
    int l,r;
    int val;
}T[MAXN<<2];
void MakeTree(int x,int l,int r)
{
    T[x].l=l,T[x].r=r;
    if(l==r) {T[x].val=c[l-1];return;}
    int mid=(l+r)>>1;
    MakeTree(x<<1,l,mid);
    MakeTree(x<<1|1,mid+1,r);
    T[x].val=T[x<<1].val&T[x<<1|1].val;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) c[a[i]]++;
    for(int i=0;i<(1<<20);i++) if(c[i]!=0) c[i]=1;
    MakeTree(1,1,1<<20);
    int K=0;
    while(m--)
    {
        int kk;
        scanf("%d",&kk);
        K^=kk;
        int now=1,ans=0;
        for(int i=19;i>=0;i--)
        {
            if(K&(1<<i))
            {
                if(T[now<<1|1].val==0) now=now<<1|1;
                else now=now<<1,ans+=(1<<i);
            }
            else
            {
                if(T[now<<1].val==0) now=now<<1;
                else now=now<<1|1,ans+=(1<<i);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}