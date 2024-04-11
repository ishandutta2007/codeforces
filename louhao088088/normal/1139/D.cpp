// Problem: CF1139D Steps to One
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1139D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2022-10-09 19:32:43
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
#define int long long
const int maxn=2e5+5,M=2e5+5,mod=1e9+7;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1){x=-x;}return x;
}
void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,x,y,a[maxn],mu[maxn],inv[maxn],fac[maxn],vis[maxn],p[maxn],cnt=0,ans;
int Pow(int x,int y){int res=1;while(y){if(y&1)res=res*x%mod;x=x*x%mod;y=y/2;}return res;}
void init(int n){
	fac[0]=1;inv[0]=1;mu[1]=1;
	for(int i=1;i<=n;i++)inv[i]=Pow(i,mod-2);
	for(int i=2;i<=n;i++){
		if(!vis[i]){p[++cnt]=i;mu[i]=-1;}
		for(int j=1;j<=cnt&&i*p[j]<=n;j++){
			vis[i*p[j]]=1;
			if(i%p[j]==0){mu[i*p[j]]=0;break;}
			else mu[i*p[j]]=-mu[i];
		}
	}
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	n=read();
 	init(n+1);ans=1;
 	for(int i=2;i<=n;i++)
 		ans=(ans-mu[i]*(n/i)%mod*inv[n-n/i]%mod+mod)%mod;
 	cout<<ans<<endl;
 	return 0;
}