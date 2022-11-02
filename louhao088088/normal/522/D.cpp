#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=5e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,m,a[maxn],b[maxn],lx[maxn],rx[maxn],Max,ly[maxn],t,ans[maxn],res,sum,id[maxn];
struct qry
{
	int l,r,id;
}q[maxn];
bool cmp(qry x,qry y){if(id[x.l]==id[y.l])return x.r<y.r;return x.l<y.l;} 
void add(int x){if(!lx[a[x]])lx[a[x]]=x,rx[a[x]]=x;else sum=min(x-rx[a[x]],sum),rx[a[x]]=x;}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();m=read();t=sqrt(n);
	for(int i=1;i<=n;i++)b[i]=a[i]=read(),id[i]=(i-1)/t+1;
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	for(int i=1;i<=m;i++)q[i].l=read(),q[i].r=read(),q[i].id=i;sort(q+1,q+m+1,cmp);
	int l,r;
	for(int i=1;i<=m;i++)
	{
		if(id[q[i].l]!=id[q[i-1].l])
			memset(lx,0,sizeof lx),memset(rx,0,sizeof rx),r=id[q[i].l]*t,sum=1e9;
		if(id[q[i].l]==id[q[i].r])
		{
			res=1e9;
			for(int j=q[i].r;j>=q[i].l;j--)
			{
				if(ly[a[j]])
				res=min(res,ly[a[j]]-j);ly[a[j]]=j;
			}
			if(res==1e9)ans[q[i].id]=-1;
			else ans[q[i].id]=res;
			for(int j=q[i].r;j>=q[i].l;j--)ly[a[j]]=0;continue;
		}
		while(r<q[i].r)add(++r);
		res=sum,l=id[q[i].l]*t+1;
		while(l>q[i].l)
		{l--;if(ly[a[l]])res=min(res,ly[a[l]]-l);else if(lx[a[l]])res=min(res,lx[a[l]]-l);ly[a[l]]=l;}
		if(res==1e9)ans[q[i].id]=-1;
		else ans[q[i].id]=res;
		while(l<id[q[i].l]*t+1){ly[a[l]]=0;l++;}		
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}