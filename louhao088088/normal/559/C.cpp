// Problem: CF559C Gerald and Giant Chess
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF559C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2021-12-19 08:26:47
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
const int maxn=5e5+5,M=34005,mod=1e9+7;
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
int n,m,k,f[maxn],sum[maxn],inv[maxn],ans;
int Pow(int x,int y){int res=1;while(y){if(y&1)res=res*x%mod;x=x*x%mod;y=y/2;}return res;}
struct node
{
	int x,y;
}a[maxn];
bool cmp(node a,node b){if(a.x==b.x)return a.y<b.y;return a.x<b.x;}
int C(int x,int y){return sum[x]*inv[y]%mod*inv[x-y]%mod;}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(),k=read();sum[0]=1;inv[0]=1;
	for(int i=1;i<=n+m;i++)sum[i]=sum[i-1]*i%mod,inv[i]=Pow(sum[i],mod-2);
	for(int i=1;i<=k;i++)a[i].x=read(),a[i].y=read();k++;a[k].x=n,a[k].y=m;
	sort(a+1,a+k+1,cmp);//cout<<ans<<endl;
	for(int i=1;i<=k;i++)
	{
		f[i]=C(a[i].x+a[i].y-2,a[i].x-1);
		for(int j=1;j<i;j++)
			if(a[j].y<=a[i].y)
				f[i]-=f[j]*C(a[i].x+a[i].y-a[j].x-a[j].y,a[i].x-a[j].x)%mod,f[i]+=mod,f[i]%=mod;
	}
	cout<<f[k];
 	return 0;
}