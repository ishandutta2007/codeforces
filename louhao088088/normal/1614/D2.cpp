// Problem: Divan and Kostomuksha (easy version)
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/1614/problem/D1
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 2021-11-26 19:50:29
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize(2)
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
const int maxn=2e7+5;
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
int n,m,a[maxn],s[maxn],M,p[maxn],vis[maxn],tot=0;
long long f[maxn],ans;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();int t=sqrt(a[i]);
		for(int j=1;j<=t;j++)
			if(a[i]%j==0)
			{
				s[a[i]/j]++;
				if(j*j!=a[i])s[j]++;
			}
		M=max(M,a[i]);
	}
	for(int i=2;i<=M;i++)
	{
		if(!vis[i])p[++tot]=i;
		for(int j=1;j<=tot&&p[j]*i<=M;j++)
			vis[p[j]*i]=1;
	}
	for(int i=M;i>=1;i--)
	{
		if(s[i])f[i]=1ll*s[i]*i;
		for(int j=1;p[j]*i<=M&&j<=tot;j++)
			f[i]=max(f[i],f[p[j]*i]+1ll*(s[i]-s[p[j]*i])*i);
		if(s[i]==n)ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
 	return 0;
}