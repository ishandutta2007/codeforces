// Problem: Divan and a Store
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/1614/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 2021-11-26 19:17:13
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
int n,m,T,l,r,k,s,b[maxn],ans;
pi a[maxn];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)a[i].fi=read(),a[i].se=i;
	sort(a+1,a+n+1);ans=0;
	b[0]=0;int tot=0;
	for(int i=n;i>=1;i--)
	{
		if(tot<=0)tot=-tot+1;
		else tot=-tot;
		b[a[i].se]=tot;ans=ans+abs(tot)*a[i].fi;
	}
	cout<<ans*2<<endl;
	for(int i=0;i<=n;i++)
		printf("%lld ",b[i]);
	puts("");
	
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)
	{
		solve();
	}	
 	return 0;
}