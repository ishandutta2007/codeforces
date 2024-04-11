// Problem: CF1547F Array Stabilization (GCD version)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1547F
// Memory Limit: 500 MB
// Time Limit: 4000 ms
// 2022-02-11 08:28:29
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit (x&-x)
const int maxn=4e5+5,M=34005;
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
int T,a[maxn],n,sum[maxn*4];
void build(int rt,int l,int r)
{
	if(l==r){sum[rt]=a[l];return;}
	build(ls,l,mid),build(rs,mid+1,r);
	sum[rt]=__gcd(sum[ls],sum[rs]);
}
int query(int rt,int l,int r,int L,int R)
{
	if(l>=L&&r<=R)return sum[rt];
	else if(L>mid)return query(rs,mid+1,r,L,R);
	else if(R<=mid)return query(ls,l,mid,L,R);
	return __gcd(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
}
void solve()
{
	int g=0;n=read();
	for(int i=1;i<=n;i++)a[i]=read(),g=__gcd(a[i],g);
	for(int i=1;i<=n;i++)a[i]=a[i]/g;
	for(int i=1;i<=n;i++)a[i+n]=a[i];build(1,1,2*n);int r=1,ans=0;//exit(0);
	for(int i=1;i<=n;i++)
	{
		r=max(r,i);
		while(query(1,1,2*n,i,r)!=1&&r<=2*n)r++;
		ans=max(ans,r-i);
	}
	cout<<ans<<endl;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout)
	T=read();//T=1;
	while(T--)solve();
 	return 0;
}