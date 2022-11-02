// Problem: CF510D Fox And Jumping
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF510D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2021-11-26 21:07:55
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)
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
int n,m,a[maxn],c[maxn];
map<int,int>f;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(!f[a[i]])f[a[i]]=c[i];
		else f[a[i]]=min(f[a[i]],c[i]);
		for(auto j:f)
		{
			int x=__gcd(j.fi,a[i]);
			//cout<<j.se<<" "<<j.fi<<endl;
			if(!f[x])f[x]=j.se+c[i];
			else f[x]=min(j.se+c[i],f[x]);
		}
	}
	if(!f[1])puts("-1");
	else cout<<f[1]<<endl;
 	return 0;
}