// Problem: P4151 [WC2011]XOR
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4151
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 2022-04-13 20:53:53
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
const int maxn=1e5+5,M=34005;
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
int n,m,a[maxn],x,y,z,flag[maxn],dis[maxn],ans;vector<pi>e[maxn];
void ins(int x){
	for(int i=63;i>=0;i--)
		if((1ll<<i)&x){
			if(!a[i]){a[i]=x;break;}
			x=a[i]^x;
		}
}
void dfs(int x){
	flag[x]=1;
	for(auto i:e[x])
		if(flag[i.fi])ins(dis[i.fi]^dis[x]^i.se);
		else dis[i.fi]=dis[x]^i.se,dfs(i.fi);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++)x=read(),y=read(),z=read(),e[x].pb(mp(y,z)),e[y].pb(mp(x,z));
	dfs(1);ans=dis[n];
	for(int i=63;i>=0;i--)
		if((ans^a[i])<ans)ans=ans^a[i];
	cout<<ans<<endl;
 	return 0;
}