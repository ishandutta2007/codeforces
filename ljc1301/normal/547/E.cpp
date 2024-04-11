#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
const int maxl=200005+maxn;
const int maxlog=20;
const int maxnode=maxlog*maxn;
char s[maxl];
int n,l,logn,len[maxn],pos[maxn],sa[maxl],rk[maxl],h[maxlog][maxl],sz[maxl];
int rt[maxn],lc[maxnode],rc[maxnode],val[maxnode],tot;
inline void build(int n)
{
    int i,*x=rk,*y=h[0],m=128,k,p;
    for(i=0;i<m;i++) sz[i]=0;
    for(i=0;i<n;i++) sz[x[i]=s[i]]++;
    for(i=1;i<m;i++) sz[i]+=sz[i-1];
    for(i=n-1;i>=0;i--) sa[--sz[x[i]]]=i;
    for(k=1;;k<<=1)
    {
        for(i=n-k,p=0;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++)
            if(sa[i]>=k)
                y[p++]=sa[i]-k;
        for(i=0;i<m;i++) sz[i]=0;
        for(i=0;i<n;i++) sz[x[i]]++;
        for(i=1;i<m;i++) sz[i]+=sz[i-1];
        for(i=n-1;i>=0;i--) sa[--sz[x[y[i]]]]=y[i];
        swap(x,y);
        for(x[sa[0]]=0,i=1,p=1;i<n;i++)
            x[sa[i]]=(y[sa[i]]==y[sa[i-1]] && (sa[i]<n-k)==(sa[i-1]<n-k) && (sa[i]>=n-k || y[sa[i]+k]==y[sa[i-1]+k]))?p-1:(p++);
        if(p>=n) break;
        m=p;
    }
    for(i=0;i<n;i++) rk[sa[i]]=i;
    for(h[0][0]=p=0,i=0;i<n;i++)
    {
        if(p) p--;
        if(!rk[i]) continue;
        while(s[i+p]==s[sa[rk[i]-1]+p]) p++;
        h[0][rk[i]]=p;
    }
    for(logn=0;(1<<logn)<n;logn++);
    for(p=1;p<=logn;p++)
        for(i=0;i+(1<<p)<=n;i++)
            h[p][i]=min(h[p-1][i],h[p-1][i+(1<<(p-1))]);
}
void insert(int &rt,int l,int r,int x)
{
    int pre=rt; rt=++tot,val[rt]=val[pre]+1,lc[rt]=lc[pre],rc[rt]=rc[pre];
    if(l==r) return;
    int mid=(l+r)>>1;
    if(x<=mid) insert(lc[rt],l,mid,x);
    else insert(rc[rt],mid+1,r,x);
}
int query(int rtr,int rtl,int l,int r,int x,int y)
{
    if(x<=l && r<=y) return val[rtr]-val[rtl];
    int mid=(l+r)>>1,res=0;
    if(x<=mid) res+=query(lc[rtr],lc[rtl],l,mid,x,y);
    if(mid<y) res+=query(rc[rtr],rc[rtl],mid+1,r,x,y);
    return res; 
}
int main()
{
    int q,i,L,R,k,lb,rb;
    l=0;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++)
        pos[i]=l,scanf("%s",s+l),len[i]=strlen(s+l),l+=len[i]+1,s[l-1]='#';
    s[l]='\0',build(l);
    tot=0,rt[0]=0,lc[0]=rc[0]=val[0]=0;
    for(i=1;i<=n;i++)
    {
        rt[i]=rt[i-1];
        for(k=pos[i];k<pos[i]+len[i];k++)
            insert(rt[i],0,l-1,rk[k]);
    }
    while(q--)
    {
        scanf("%d%d%d",&L,&R,&k);
        lb=rb=rk[pos[k]];
        for(i=logn;i>=0;i--)
        {
            if(lb-(1<<i)>=0 && h[i][lb-(1<<i)+1]>=len[k]) lb-=1<<i;
            if(rb+(1<<i)<l && h[i][rb+1]>=len[k]) rb+=1<<i;
        }
        printf("%d\n",query(rt[R],rt[L-1],0,l-1,lb,rb));
    }
    return 0;
}