#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstring>
#include<cmath>
#include<algorithm>
#define F(i,j,n) for(int i=j;i<=n;i++)
#define D(i,j,n) for(int i=j;i>=n;i--)
#define ll long long
#define maxn 100005
#define inf 1000000000
using namespace std;
int n,f[maxn];
ll a[maxn],b[maxn];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline bool cmp(int x,int y)
{
	ll dx=(a[x]-a[1])*(a[x]-a[1])+(b[x]-b[1])*(b[x]-b[1]);
	ll dy=(a[y]-a[1])*(a[y]-a[1])+(b[y]-b[1])*(b[y]-b[1]);
	return dx<dy;
}
int main()
{
	n=read();
	F(i,1,n) a[i]=read(),b[i]=read();
	F(i,1,n) f[i]=i;
	sort(f+1,f+n+1,cmp);
	printf("%d %d ",f[1],f[2]);
	int t=3;
	while ((b[f[t]]-b[f[1]])*(a[f[2]]-a[f[1]])==(b[f[2]]-b[f[1]])*(a[f[t]]-a[f[1]])) t++;
	printf("%d\n",f[t]);
}