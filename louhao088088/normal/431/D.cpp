// Problem: CF258B Little Elephant and Elections
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF431D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2021-12-08 21:34:18
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
#define int long long 
#define ls (rt<<1)
#define rs (rt<<1|1)
#define lowbit (x&-x)
const int maxn=1e5+5,M=34005;
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
int n,m,a[maxn],f[75][75][2],l,r,res,k;
int dfs(int x,int k,int l)
{
	if(k==0)return 1;
	if(x==0)return 0;
	if(f[x][k][l]!=-1)return f[x][k][l];
	f[x][k][l]=0;
	if(l==1)
	{
		if(a[x])f[x][k][l]+=dfs(x-1,k,0);
		f[x][k][l]+=dfs(x-1,k-a[x],l);
	}
	else
	{
		f[x][k][l]+=dfs(x-1,k,0);
		f[x][k][l]+=dfs(x-1,k-1,0);
	}
	//cout<<x<<" "<<k<<" "<<l<<" "<<f[x][k][l]<<endl;
	return f[x][k][l];
}
int get(int x)
{
	int y=x,tot=0;memset(a,0,sizeof a);
	memset(f,-1,sizeof f);
	while(x){a[++tot]=x%2;x=x/2;}
	return dfs(tot+1,k,1);
}
bool check(int x)
{
	int num=get(2*x)-get(x);
	//cout<<x<<" "<<num<<endl;
	if(num>=m)return true;
	return false;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	m=read();k=read();
	//cout<<get(10)<<" "<<get(5)<<endl;//
	//return 0;
	int l=1,r=1e18,res=1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))r=mid-1,res=mid;
		else l=mid+1;
	}
	cout<<res;
 	return 0;
}