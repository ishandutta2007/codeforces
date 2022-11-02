#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define lowbit(i) (i&(-i))
const int maxn=8e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
void print(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,m,a[maxn],b[maxn],c[maxn],c2[maxn],d[maxn],g[maxn],f[maxn],h[maxn],s[maxn];
struct node
{
	int x,num,l,r,id;
}q[maxn];
void add(int x,int num){for(int i=x;i<=n+m;i+=lowbit(i))c[i]=max(c[i],num);}
int query(int x){int res=0;for(int i=x;i>0;i-=lowbit(i))res=max(res,c[i]);
return res;}
bool cmp(node a,node b){return a.x<b.x;}
bool cmp1(node a,node b){return a.id<b.id;}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)d[i]=a[i]=read();
	for(int i=1;i<=m;i++)q[i].x=read(),d[n+i]=q[i].num=read(),q[i].id=i;
	sort(d+1,d+n+m+1);for(int i=1;i<=n;i++)a[i]=lower_bound(d+1,d+n+m+1,a[i])-d;
	for(int i=1;i<=m;i++)q[i].num=lower_bound(d+1,d+n+m+1,q[i].num)-d;
	sort(q+1,q+m+1,cmp);int l=1;
	for(int i=1;i<=n;i++)
	{
		
		while(q[l].x==i&&l<=m){q[l].l=query(q[l].num-1);l++;}
		f[i]=query(a[i]-1),add(a[i],f[i]+1);//cout<<a[i]<<" "<<f[i]+1<<endl;
		
	}memset(c,0,sizeof c);l=m;
	for(int i=n;i>=1;i--)
	{
		while(q[l].x==i&&l>=0){q[l].r=query(n+m+2-q[l].num-1);l--;}
		g[i]=query(n+m+2-a[i]-1),add(n+m+2-a[i],g[i]+1);
		//cout<<a[i]<<" "<<n+m+2-a[i]<<" "<<g[i]<<endl;
	}int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(f[i]+g[i]+1,ans);
	for(int i=1;i<=n;i++)
		if(f[i]+g[i]+1==ans)
			s[f[i]]++;
	sort(q+1,q+m+1,cmp1);
	for(int i=1;i<=m;i++)
	{
		int x=q[i].x;//cout<<x<<" "<<f[x]<<" "<<g[x]<<" "<<ans<<" "<<s[f[x]]<<" "<<q[i].l<<" "<<q[i].r<<endl;
		if(f[x]+g[x]+1==ans&&s[f[x]]==1)printf("%d\n",max(ans-1,q[i].l+q[i].r+1));
		else printf("%d\n",max(ans,q[i].l+q[i].r+1));
	}
	return 0;
}