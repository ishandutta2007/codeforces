// Problem: CF148D Bag of mice
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF148D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2022-04-07 16:20:28
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
//#define double long double
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
int n,m;
double f[2005][2005];
double dp(int x,int y)
{
	if(x==0)return 0;
	if(y==0)return 1;
	if(f[x][y]>0)return f[x][y];
	double res=1.0*x/(x+y);
	if(y==2)res+=1.0*y/(x+y)*(y-1)/(x+y-1)*dp(x-1,y-2);
	else if(y>=3)res+=1.0*y/(x+y)*(y-1)/(x+y-1)*(1.0*x/(x+y-2)*dp(x-1,y-2)+1.0*(y-2)/(x+y-2)*dp(x,y-3));
	//cout<<res<<" "<<x<<" "<<y<<endl;
	return f[x][y]=res;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	printf("%.9lf",dp(n,m));	
 	return 0;
}