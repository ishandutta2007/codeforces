#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define int long long
#define ls (rt<<1)
#define rs (rt<<1|1) 
#define mid (l+r>>1)
#define mp make_pair
#define fi first
#define se second
const int maxn=2e5+5;
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
int n,m,q,a[maxn],tag[maxn*4],Max[maxn*4],f[maxn],l,r,x,ans;
void push(int rt,int l,int r)
{
	if(tag[rt])
	{
		tag[ls]+=tag[rt],Max[ls]+=tag[rt];
		tag[rs]+=tag[rt];Max[rs]+=tag[rt];tag[rt]=0;
	}
}
void add(int rt,int l,int r,int L,int R,int num)
{
	if(l>R||r<L)return;
	if(l>=L&&r<=R){tag[rt]+=num;Max[rt]+=num;return;}
	push(rt,l,r);
	add(ls,l,mid,L,R,num),add(rs,mid+1,r,L,R,num);
	Max[rt]=max(Max[ls],Max[rs]);
}
int query(int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return 0;
	if(l>=L&&r<=R){return Max[rt];}
	push(rt,l,r);
	return max(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
}
vector<pair<int,int>>b[maxn];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)l=read(),r=read(),x=read(),b[r].push_back(mp(l,x));ans=0;
	for(int i=1;i<=n;i++)
	{
		add(1,1,n,i,i,ans);add(1,1,n,1,i,-a[i]);
		for(auto j:b[i])
			add(1,1,n,1,j.fi,j.se);
		ans=max(query(1,1,n,1,i),ans);
	//	cout<<ans<<endl;
	}cout<<ans<<endl;
 	return 0;
}