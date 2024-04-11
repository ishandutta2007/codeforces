#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define lowbit(x) (x&(-x))
const int maxn=1e6+5;
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
struct node 
{
	int l,r,id;
}q[maxn];
int n,m,sum[maxn],a[maxn],b[maxn],ans[maxn],res,l,r,t,c[maxn],f[maxn];
bool cmp(node a,node b){return a.r<b.r;}
inline void add(int x,int num){if(!x)return;for(int i=x;i<=n;i+=lowbit(i))c[i]^=num;}
inline int query(int x){int res=0;for(int i=x;i;i-=lowbit(i))res^=c[i];return res;}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)b[i]=a[i]=read(),sum[i]=sum[i-1]^a[i];
	sort(b+1,b+n+1);m=read();
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	for(int i=1;i<=m;i++)q[i].l=read(),q[i].r=read(),q[i].id=i;
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		while(r<q[i].r)r++,add(f[a[r]],b[a[r]]),f[a[r]]=r,add(f[a[r]],b[a[r]]);
		ans[q[i].id]=query(q[i].l-1)^query(q[i].r)^sum[q[i].r]^sum[q[i].l-1];
	//	cout<<(query(q[i].l-1)^query(q[i].r))<<' '<<(sum[q[i].r]^sum[q[i].l-1])<<" "<<q[i].id<<" "<<query(r)<<endl;
	}
	for(int i=1;i<=m;i++)print(ans[i]),puts("");
 	return 0;
}