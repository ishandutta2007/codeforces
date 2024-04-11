// Problem: CF1285E Delete a Segment
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1285E
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 2022-04-28 21:33:25
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
const int maxn=8e5+5,M=34005;
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
int n,m,a[maxn],b[maxn],d[maxn],c[maxn],sz[maxn],T,ans,sum,tot;
void solve(){
	n=read(),sum=0,ans=0,tot=0;
	
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=read(),d[++tot]=a[i],d[++tot]=b[i];
	sort(d+1,d+tot+1);
	for(int i=1;i<=n;i++)a[i]=lower_bound(d+1,d+tot+1,a[i])-d,a[i]*=2,
	b[i]=lower_bound(d+1,d+tot+1,b[i])-d,b[i]*=2,c[a[i]]++,c[b[i]+1]--;tot=tot*2;
	for(int i=1;i<=tot;i++)c[i]+=c[i-1],sz[i]=sz[i-1]+(c[i]==1&&c[i-1]!=1),sum+=(c[i]>0&&c[i-1]==0);
	for(int i=1;i<=n;i++){
		int o=sum+sz[b[i]]-sz[a[i]]-(c[b[i]]==1);
		ans=max(ans,sum+sz[b[i]]-sz[a[i]]-(c[b[i]]==1));
	}
	for(int i=1;i<=2*tot;i++)c[i]=sz[i]=0;	
	cout<<ans<<endl;
	
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)solve();
 	return 0;
}