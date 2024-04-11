#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define mid (l+r>>1)
#define lowbit(x) (x&-x)
const int maxn=2e5+5,M=34005;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,x,u[maxn],v[maxn],w[maxn],op[maxn],c[maxn],sz,rt[maxn],a[maxn];
int sum[maxn<<5],ls[maxn<<5],rs[maxn<<5];
set<int>s;
void updata(int &rt,int rt1,int l,int r,int L,int R)
{
	if(l>R||r<L)return;if(sum[rt]==r-l+1)return;
	rt=++sz;ls[rt]=ls[rt1],rs[rt]=rs[rt1];sum[rt]=sum[rt1];
	if(l>=L&&r<=R){sum[rt]=r-l+1;return;}
	updata(ls[rt],ls[rt1],l,mid,L,R),updata(rs[rt],rs[rt1],mid+1,r,L,R);
	sum[rt]=sum[ls[rt]]+sum[rs[rt]];
}
int query(int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return 0;if(!rt)return 0;
	if(sum[rt]==r-l+1)return min(R,r)-max(L,l)+1;
	if(l>=L&&r<=R){return sum[rt];}
	return query(ls[rt],l,mid,L,R)+query(rs[rt],mid+1,r,L,R);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();memset(a,0x3f,sizeof a);
	for(int i=1;i<=m;i++)
	{
		op[i]=read();
		if(op[i]==0)u[i]=read(),v[i]=read(),w[i]=read();
		else w[i]=read();
	}
	for(int i=1;i<=m;i++)
	{
		rt[i]=rt[i-1];
		if(op[i]==0&&w[i]==0)updata(rt[i],rt[i],1,n,u[i],v[i]);
	}//return 0;
	for(int i=1;i<=n;i++)
		if(!query(rt[m],1,n,i,i))s.insert(i);
	for(int i=1;i<=m;i++)
	{
		if(op[i]==0&&w[i]==1)
		{
			//cout<<"A"<<query(rt[m],1,n,u[i],v[i])<<" "<<u[i]<<" "<<v[i]<<endl;
			if(query(rt[m],1,n,u[i],v[i])!=v[i]-u[i])continue;
			int l=i,r=m,ans=m;//cout<<l<<" "<<r<<" "<<i<<endl;
			while(l<=r)
			{
				if(query(rt[mid],1,n,u[i],v[i])==v[i]-u[i])ans=mid,r=mid-1;
				else l=mid+1;
			}
			int id=*s.lower_bound(u[i]);
		//	cout<<i<<" "<<id<<endl;
			a[id]=min(a[id],ans);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(op[i]==1)
		{
			//cout<<query(rt[i],1,n,w[i],w[i])<<endl;
			if(query(rt[i],1,n,w[i],w[i]))puts("NO");
			else if(a[w[i]]<i)puts("YES");
			else puts("N/A");
		}
	}
 	return 0;
}


/*********************************************************************
    :louhao088
    : 2022-02-23 18:52
*********************************************************************/