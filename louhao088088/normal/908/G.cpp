// Problem: CF908G New Year and Original Order
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF908G
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2022-04-26 06:55:53
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
#define lowbit(x) (x&-x)
#define int long long
const int maxn=1e3+5,M=34005,mod=1e9+7;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
char a[maxn];
int f[maxn][2],g[maxn][2],d,ans=0,n;
void dfs(int x,int y){
	if(f[x][y]!=-1)return ;
	f[x][y]=g[x][y]=0;
	if(x==0){g[x][y]=d;return;}
	int r=9;
	if(y==1){
		int z=a[n-x+1]-'0';r=z-1;
		if(z>d)dfs(x-1,y),f[x][y]+=f[x-1][y]*10,g[x][y]+=g[x-1][y]*10;
		if(z==d)dfs(x-1,y),f[x][y]+=f[x-1][y]*10+g[x-1][y],g[x][y]+=g[x-1][y];
		if(z<d)dfs(x-1,y),f[x][y]+=f[x-1][y],g[x][y]+=g[x-1][y];
		f[x][y]%=mod,g[x][y]%=mod;
	}
	for(int i=0;i<=r;i++){
		int z=i;
		if(z>d)dfs(x-1,0),f[x][y]+=f[x-1][0]*10,g[x][y]+=g[x-1][0]*10;
		if(z==d)dfs(x-1,0),f[x][y]+=f[x-1][0]*10+g[x-1][0],g[x][y]+=g[x-1][0];
		if(z<d)dfs(x-1,0),f[x][y]+=f[x-1][0],g[x][y]+=g[x-1][0];
		f[x][y]%=mod,g[x][y]%=mod;
	}
	//cout<<x<<" "<<y<<" "<<f[x][y]<<" "<<g[x][y]<<" "<<r<<endl;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s",a+1);n=strlen(a+1);
	for(int i=1;i<=9;i++){d=i;
		memset(g,-1,sizeof g);memset(f,-1,sizeof f);
		dfs(n,1);ans+=f[n][1];ans%=mod;
	}cout<<ans<<endl;
 	return 0;
}