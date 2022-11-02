#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=200005;
struct node
{
	int l,r,id;
}b[maxn];
int n,m,a[maxn],t,t2,id[maxn],s[maxn],ans[maxn],sum=0,c[maxn],d[maxn],l,r;
bool cmp(node a,node b)
{
	if(id[a.l]!=id[b.l])return a.l<b.l;
	if(id[a.l]&1)return a.r<b.r;return a.r>b.r;
}
void add(int x){if(x>1e5)return;s[x]++;if(s[x]==x)sum++;if(s[x]==x+1)sum--;}
void cut(int x){if(x>1e5)return;if(s[x]==x)sum--;s[x]--;if(s[x]==x)sum++;}
signed main()
{
	//freopen("P1494_1.in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(),m=read();t=sqrt(n);
	for(int i=1;i<=n;i++)
		a[i]=read(),id[i]=(i-1)/t+1;
	for(int i=1;i<=m;i++)b[i].l=read(),b[i].r=read(),b[i].id=i;
	sort(b+1,b+m+1,cmp);l=b[1].l,r=b[1].r;
	for(int i=b[1].l;i<=b[1].r;i++)add(a[i]);ans[b[1].id]=sum;
	for(int i=2;i<=m;i++)
	{
		
		while(l<b[i].l)cut(a[l]),l++;
		while(l>b[i].l)l--,add(a[l]);
		while(r<b[i].r)r++,add(a[r]);
		while(r>b[i].r)cut(a[r]),r--;
		ans[b[i].id]=sum;
	//	cout<<sum<<" "<<b[i].id<<endl;
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}