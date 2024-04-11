// Problem: CF713E Sonya Partymaker
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF713E
// Memory Limit: 250 MB
// Time Limit: 1500 ms
// 2022-04-28 16:08:18
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
#define lowbit(x) (x&-x)
const int maxn=2e5+5,M=34005;
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
int n,m,l,r,ans,b[maxn],a[maxn],id,f[maxn];
bool check(int x){
	f[1]=0;
	for(int i=2;i<=n;i++){f[i]=0;
		if(f[i-1]>=b[i]-1)f[i]=b[i]+x;
		else if(f[i-1]>=b[i]-x-1)f[i]=b[i];
		if(f[i-2]>=b[i]-x-1)f[i]=max(f[i],b[i-1]+x);
	}
	if(f[n]>=m-x-1)return 1;
	f[1]=x;f[2]=max(x,b[2]);
	for(int i=3;i<=n;i++){f[i]=0;
		if(f[i-1]>=b[i]-1)f[i]=b[i]+x;
		else if(f[i-1]>=b[i]-x-1)f[i]=b[i];
		if(f[i-2]>=b[i]-x-1)f[i]=max(f[i],b[i-1]+x);
	}
	
	if(f[n]>=min(m-1,m+b[2]-x-1))return 1;return 0;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	m=read(),n=read();
	for(int i=1;i<=n;i++)a[i]=read();sort(a+1,a+n+1);
	for(int i=n+1;i<=n+n;i++)a[i]=a[i-n]+m;
	if(n==1){cout<<m-1;exit(0);}
	for(int i=2;i<=n+1;i++)
		if(a[i]-a[i-1]>r)r=a[i]-a[i-1],id=i-1;
	for(int i=1;i<=n;i++)b[i]=a[i+id];
	for(int i=n;i>=1;i--)b[i]=b[i]-b[1];
	l=0;ans=r;f[0]=-1e9;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}	
	cout<<ans<<endl;
 	return 0;
}