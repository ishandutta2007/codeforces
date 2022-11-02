#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#define N 500005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define int long long
int n;
map<int,int> mp;
int sa[N],ea[N],sb[N],eb[N];
struct zgz
{
    int l,r;
    int bl,br;
}g[N],h[N];
bool cmpl(const zgz &a,const zgz &b)
{
    return a.l<b.l;
}
bool cmpr(const zgz &a,const zgz &b)
{
    return a.r<b.r;
}
int c[N];
int laz[N<<2],sum[N<<2];
void pushdown(int x,int l,int r)
{
	if(laz[x])
	{
		int mid=(l+r)>>1;
		laz[x<<1]+=laz[x];
		laz[x<<1|1]+=laz[x];
		sum[x<<1]+=(mid-l+1)*laz[x];
		sum[x<<1]+=(r-mid)*laz[x];
		laz[x]=0;
	}
}
void pushup(int x)
{
	sum[x]=sum[x<<1]+sum[x<<1|1];
	//mn[x]=min(mn[x<<1],mn[x<<1|1]);
}
void update(int x,int l,int r,int L,int R,int val)
{
	if(l>R||L>r)return ;
	if(l>=L&&r<=R)
	{
		sum[x]+=(r-l+1)*val;
		laz[x]+=val;
		return ;
	}
	pushdown(x,l,r);
	int mid=(l+r)>>1;
	if(L<=mid)
	update(x<<1,l,mid,L,R,val);
	if(r>mid)
	update(x<<1|1,mid+1,r,L,R,val);
	pushup(x);
}
int query(int x,int l,int r,int L,int R)
{
	if(l>=L&&r<=R)
	{
		return sum[x];
		//return mx[x];
		//return mn[x];
	}
	pushdown(x,l,r);
	int ans=0;
	int mid=(l+r)>>1;
	if(L<=mid)
	{
		ans+=query(x<<1,l,mid,L,R);
		//Max=max(Max,query(x<<1,l,mid,L,R));
		//Min=min(Min,query(x<<1,l,mid,L,R));
	}
	if(R>mid)
	{
		ans+=query(x<<1|1,mid+1,r,L,R);
		//Max=max(Max,query(x<<1|1,mid+1,r,L,R));
		//Min=min(Min,query(x<<1|1,mid+1,r,L,R));
	}
	return ans;
	//return Max;
	//return Min;
}


int stk[N],top;
void work()
{
    for(int i=1;i<=n;i++)
    {
        stk[++top]=sa[i];
        stk[++top]=ea[i];
        stk[++top]=sb[i];
        stk[++top]=eb[i];
    }
    sort(stk+1,stk+top+1);
    int scnt=1;
    for(int i=1;i<=top;i++)
    if(!mp[stk[i]]) mp[stk[i]]=++scnt;
    for(int i=1;i<=n;i++)
    sa[i]=mp[sa[i]],ea[i]=mp[ea[i]],sb[i]=mp[sb[i]],eb[i]=mp[eb[i]];

    for(int i=1;i<=n;i++)
    {
        g[i].l=sa[i],g[i].r=ea[i];
        g[i].bl=sb[i],g[i].br=eb[i];
        h[i]=g[i];
    }
    sort(g+1,g+n+1,cmpl);
    sort(h+1,h+n+1,cmpr);

    int j=1;
    for(int i=1;i<=n;i++)
    {
    //    cerr<<i<<' '<<g[i].l<<' '<<g[i].r<<endl;
        while(j<=n&&h[j].r<g[i].l)
        {
            //cerr<<h[j].bl<<' '<<h[j].br<<endl;
            update(1,1,scnt,h[j].bl,h[j].br,1);
            j++;
        }
    //    cerr<<i<<' '<<j<<endl;
        int k=query(1,1,scnt,g[i].bl,g[i].br);;
//;        ask(g[i].br)-ask(g[i].bl-1);
        //cerr<<k<<' '<<g[i].bl<<' '<<g[i].br<<endl;
        if(k>0)
        {
            puts("NO");
            exit(0);
        }
    }

     mp.clear();
     top=0;
     memset(laz,0,sizeof(laz));
     memset(sum,0,sizeof(sum));
}
main()
{
    n=read();
    for(int i=1;i<=n;i++)sa[i]=read(),ea[i]=read(),sb[i]=read(),eb[i]=read();
   work();
    for(int i=1;i<=n;i++)swap(sa[i],sb[i]),swap(ea[i],eb[i]);
    work();
    puts("YES");
}