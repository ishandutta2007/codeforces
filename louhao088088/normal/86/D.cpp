#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
struct node{int l,r,id;}q[maxn];
int n,m,s[1000005],a[maxn],id[maxn],b,sum,l,r,ans[maxn];
bool cmp(node a,node b){if(id[a.l]==id[b.l])return a.r<b.r;return a.l<b.l;}
void add(int x){sum-=a[x]*s[a[x]]*s[a[x]],s[a[x]]++,sum+=s[a[x]]*s[a[x]]*a[x];}
void cut(int x){sum-=a[x]*s[a[x]]*s[a[x]],s[a[x]]--,sum+=s[a[x]]*s[a[x]]*a[x];}
signed main()
{
	n=read(),m=read();b=sqrt(n);
	for(int i=1;i<=n;i++)
		a[i]=read(),id[i]=i/b+1;
	for(int i=1;i<=m;i++)
		q[i].l=read(),q[i].r=read(),q[i].id=i;
	sort(q+1,q+m+1,cmp);l=q[1].l,r=q[1].r;
	for(int i=l;i<=r;i++)add(i);ans[q[1].id]=sum;
	for(int i=2;i<=m;i++)
	{
		while(l>q[i].l)l--,add(l);
		while(l<q[i].l)cut(l),l++;
		while(r>q[i].r)cut(r),r--;
		while(r<q[i].r)r++,add(r);
		ans[q[i].id]=sum;
	}
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}