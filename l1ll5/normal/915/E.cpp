#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 600010
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,q;
int sum[N*30],ch[N*30][2],tot;
void pushdown(int x,int l,int r)
{
    if(sum[x]==(r-l+1))
    {
        int mid=(l+r)>>1;
        if(!ch[x][0])ch[x][0]=++tot;
        if(!ch[x][1])ch[x][1]=++tot;
        sum[ch[x][0]]=mid-l+1;
        sum[ch[x][1]]=r-mid;
    }
    if(sum[x]==0)
    {
        if(!ch[x][0])ch[x][0]=++tot;
        if(!ch[x][1])ch[x][1]=++tot;
        sum[ch[x][0]]=0;
        sum[ch[x][1]]=0;
    }
}
void update(int &x,int l,int r,int L,int R,int v)
{
	if(!x)x=++tot;
	if(l>=L&&r<=R)
	{
		sum[x]=(r-l+1)*v;
		return ;
	}
	int mid=(l+r)>>1;
    pushdown(x,l,r);
	if(L<=mid)update(ch[x][0],l,mid,L,R,v);
	if(R>mid) update(ch[x][1],mid+1,r,L,R,v);
    sum[x]=sum[ch[x][0]]+sum[ch[x][1]];
}
int rt;
int main()
{
//    freopen("lessons1.in","r",stdin);
//    freopen("lessons1")
    n=read(),q=read();
    update(rt,1,n,1,n,1);
    while(q--)
    {
        int l=read(),r=read(),v=read();
        update(rt,1,n,l,r,v-1);
        printf("%d\n",sum[rt]);
    }
}