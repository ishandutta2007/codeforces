// Problem: CF1017E The Supersonic Rocket
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1017E
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 2022-03-28 19:30:00
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
const int maxn=1e6+5,M=34005;
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
int n,m,b[maxn],c[maxn];
struct Conv
{
	pi a[maxn],st[maxn];
	int b[maxn],tot,top;
	int check(pi a1,pi a2,pi b1,pi b2){return (a2.fi-a1.fi)*(b2.se-b1.se)-(b2.fi-b1.fi)*(a2.se-a1.se);}//a1a2b1b2  
	int getdis(pi a,pi b){
		return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);}
	void work(int n)
	{
		for(int i=1;i<=n;i++)a[i].fi=read(),a[i].se=read();
		sort(a+1,a+n+1);
		st[++top]=a[1],st[++top]=a[2];
		for(int i=3;i<=n;i++)
		{
			while(top>1&&check(st[top-1],st[top],st[top],a[i])<=0)top--;
			st[++top]=a[i];
		}int cnt=top-1;st[++top]=a[n-1];
		for(int i=n-2;i>=1;i--)
		{
			while(top>cnt+1&&check(st[top-1],st[top],st[top],a[i])<=0)top--;
			st[++top]=a[i];
		}
		st[++top]=st[2];
		for(int i=1;i<top-1;i++)
			b[++tot]=getdis(st[i],st[i+1]),b[++tot]=getdis(st[i+1],st[i+2]),b[++tot]=getdis(st[i],st[i+2]);
	}
}A,B;
bool check(Conv x,Conv y)
{
	if(x.tot!=y.tot)return 0;
	int n=x.tot,a[maxn],c[maxn];
	for(int i=1;i<=n;i++)a[i+n]=a[i]=x.b[i],c[i]=y.b[i];
	int nex[maxn];nex[1]=0;int j=0;
	for(int i=2;i<=n;i++)
	{
		while(j&&c[i]!=c[j+1])j=nex[j];
		if(c[i]==c[j+1])j++;nex[i]=j;
	}
	j=0;
	for(int i=1;i<=n*2;i++)
	{
		while(j&&a[i]!=c[j+1])j=nex[j];
		if(a[i]==c[j+1])j++;
		if(j==n&&i%3==0)return 1;
		if(j==n)j=nex[j];
	}
	return 0;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	A.work(n),B.work(m);
	if(check(A,B))puts("YES");
	else puts("NO");
 	return 0;
}