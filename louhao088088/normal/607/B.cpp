// Problem: CF607B Zuma
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF607B
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 2021-12-18 21:08:09
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
const int maxn=2e3+5,M=34005;
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
int a[maxn],f[maxn][maxn],n;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=1;
	for(int i=1;i<n;i++)f[i][i+1]=1+(a[i]!=a[i+1]);
	for(int i=n;i>=1;i--)
		for(int j=i+2;j<=n;j++)
		{
			if(a[i]==a[j])f[i][j]=f[i+1][j-1];
			for(int k=i;k<=j;k++)f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
		}
	cout<<f[1][n];
 	return 0;
}