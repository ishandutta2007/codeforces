// Problem: CF27E Number With The Given Amount Of Divisors
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF27E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2021-12-11 07:34:02
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
const int maxn=1e5+5,M=34005;
#define int long long
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
int n,m,ans=1e18,p[15]={2,3,5,7,11,13,17,19,23,29,31,37};
void dfs(int x,int y,int res,int dep)
{
	if(res>=ans||res<=0)return;
	if(x==1)ans=res;
	//cout<<x<<" "<<y<<" "<<res<<" "<<dep<<endl;
	for(int i=y;i>=2;i--)
		if(x%i==0)dfs(x/i,min(i,x/i),res*pow(p[dep],i-1),dep+1);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	dfs(n,n,1,0);
	cout<<ans<<endl;
 	return 0;
}