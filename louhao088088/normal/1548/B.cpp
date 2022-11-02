// Problem: CF1548B Integers Have Friends
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1548B
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2022-02-11 09:09:34
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
#define int long long
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
int T,a[maxn],n,sum[maxn*4],b[maxn];
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
	n=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<n;i++)a[i]=b[i+1]-b[i];n--;
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
	if(n==0){puts("1");return ;}
	build(1,1,n);int r=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		r=max(r,i);
		while(abs(query(1,1,n,i,r))!=1&&r<=n)r++;
		//cout<<i<<" "<<r<<endl;
		ans=max(ans,r-i+1);
	}
	printf("%lld\n",ans);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout)
	T=read();//T=1;
	while(T--)solve();
 	return 0;
}