#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define rank rank2
using namespace std;
const int MAXN=410010;
const int INF=1000000000;
char str[MAXN],str_tmp[MAXN];
int n,Q,str_size;
int st[MAXN],en[MAXN],Len[MAXN];
int sa[MAXN],c[MAXN],t1[MAXN],t2[MAXN],rank[MAXN],height[MAXN];
int ST[MAXN][22],Log[MAXN];
void BuildSA(int m)
{
    int *x=t1,*y=t2,n=str_size;
    for(int i=0;i<m;i++) c[i]=0;
    for(int i=0;i<n;i++) c[x[i]=str[i]]++;
    for(int i=1;i<m;i++) c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for(int k=1;;k<<=1)
    {
        int p=0;
        for(int i=n-k;i<n;i++) y[p++]=i;
        for(int i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
        for(int i=0;i<m;i++) c[i]=0;
        for(int i=0;i<n;i++) c[x[y[i]]]++;
        for(int i=1;i<m;i++) c[i]+=c[i-1];
        for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1,x[sa[0]]=0;
        for(int i=1;i<n;i++)
            x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?p-1:p++;
        m=p;
        if(p>=n) break;
    }
}
void GetHeight()
{
    int k=0,n=str_size;
    for(int i=0;i<n;i++) rank[sa[i]]=i;
    for(int i=0;i<n-1;i++)
    {
        int j=sa[rank[i]-1];
        if(k>0) k--;
        while(str[i+k]==str[j+k]) k++;
        height[rank[i]]=k;
    }
}
void initRMQ()
{
    int n=str_size;
    for(int i=1;i<n;i++) ST[i][0]=height[i];
    for(int i=1;i<=Log[n-1];i++)
        for(int j=1;j<n-(1<<(i-1));j++)
            ST[j][i]=min(ST[j][i-1],ST[j+(1<<(i-1))][i-1]);
}
int RMQ(int l,int r)
{
    if(l>r) return INF;
    int x=Log[r-l+1];
    return min(ST[l][x],ST[r-(1<<x)+1][x]);
}
struct Functional_Seg
{
    int lch,rch;
    int l,r;
    int size;
}T[MAXN*21];
int root[MAXN],tot;
int Build(int l,int r)
{
    int o=++tot;
    T[o].l=l,T[o].r=r;
    if(l==r) return o;
    int mid=(l+r)>>1;
    T[o].lch=Build(l,mid);
    T[o].rch=Build(mid+1,r);
    return o;
}
int Change(int x,int tar)
{
    int o=++tot;
    T[o]=T[x],T[o].size++;
    if(T[o].l==T[o].r) return o;
    int mid=(T[o].l+T[o].r)>>1;
    if(tar<=mid) T[o].lch=Change(T[x].lch,tar);
    else T[o].rch=Change(T[x].rch,tar);
    return o;
}
int Query(int x,int y,int l,int r)
{
    if(T[x].l==l&&T[x].r==r) return T[y].size-T[x].size;
    int mid=(T[x].l+T[x].r)>>1;
    if(r<=mid) return Query(T[x].lch,T[y].lch,l,r);
    else if(l>mid) return Query(T[x].rch,T[y].rch,l,r);
    else return Query(T[x].lch,T[y].lch,l,mid)+Query(T[x].rch,T[y].rch,mid+1,r);
}
int main()
{
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str_tmp);
        int len=strlen(str_tmp);
        st[i]=str_size;
        for(int j=0;j<len;j++) str[str_size++]=str_tmp[j];
        en[i]=str_size,Len[i]=en[i]-st[i];
        str[str_size++]='#';
    }
    str_size++;
    Log[0]=-1;
    for(int i=1;i<=str_size;i++) Log[i]=Log[i>>1]+1;
    BuildSA(256);
    GetHeight();
    initRMQ();
    root[0]=Build(1,n);
    st[n+1]=INF;
    for(int i=1;i<str_size;i++)
    {
        int sub=upper_bound(st+1,st+n+2,sa[i])-st-1;
        if(str[sa[i]]=='#'||str[sa[i]]==0) sub=-1;
        if(sub==-1) root[i]=root[i-1];
        else root[i]=Change(root[i-1],sub);
    }
    while(Q--)
    {
        int qL,qR,K,LL,RR;
        scanf("%d%d%d",&qL,&qR,&K);
        int L,R,mid;
        L=1,R=rank[st[K]]+1;
        while(L<R)
        {
            mid=(L+R)>>1;
            if(RMQ(mid,rank[st[K]])>=Len[K]) R=mid;
            else L=mid+1;
        }
        LL=L-1;
        L=rank[st[K]],R=str_size-1;
        while(L<R)
        {
            mid=(L+R+1)>>1;
            if(RMQ(rank[st[K]]+1,mid)>=Len[K]) L=mid;
            else R=mid-1;
        }
        RR=L;
        int ans=Query(root[LL-1],root[RR],qL,qR);
        printf("%d\n",ans);
    }
    return 0;
}