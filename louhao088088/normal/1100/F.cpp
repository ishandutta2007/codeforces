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
void print(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,m,l,r=0,a[maxn],p[25],b[25],ans[maxn];
struct node 
{
	int l,r,id;
}q[maxn];
void ins(int x,int id)
{
	for(int i=22;i>=0;i--)
	{
		if(x&(1<<i))
		{
			if(!b[i]){b[i]=x,p[i]=id;return ;}
			if(p[i]<id) swap(p[i],id),swap(x,b[i]);
			x^=b[i];
		}
	}
}
int getans(int l)
{
	int res=0;
	for(int i=22;i>=0;i--)
	{
		if((res^b[i])>res&&p[i]>=l)
			res=res^b[i];
	} 
	return res;
}
bool cmp(node a,node b){return a.r<b.r;}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	m=read();
	for(int i=1;i<=m;i++)q[i].l=read(),q[i].r=read(),q[i].id=i;
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		while(r<q[i].r)r++,ins(a[r],r);
		ans[q[i].id]=getans(q[i].l);
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]); 
	return 0;
}