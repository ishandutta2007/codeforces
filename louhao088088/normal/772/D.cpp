// Problem: CF772D Varying Kibibits
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF772D
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 2022-04-21 18:43:05
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
const int maxn=1e6+5,M=34005,mod=1e9+7;
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
int n,m,x,a[maxn],b[maxn],c[maxn],fac[maxn],ans=0;
void mul(int x,int y){
	a[x]=a[x]*fac[c[y]]%mod+a[y]*fac[c[x]]%mod+b[x]*b[y]*2%mod;a[x]%=mod;
	b[x]=b[x]*fac[c[y]]%mod+b[y]*fac[c[x]]%mod;b[x]%=mod;
	c[x]+=c[y];
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();fac[0]=1;m=1e6;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*2%mod;
	for(int i=1;i<=n;i++)x=read(),a[m]=x*x%mod,b[m]=x,c[m]=1,mul(x,m);x=1;
	for(int i=0;i<6;i++,x=x*10){
		for(int j=m-1;j>=0;j--)
			if((j/x)%10!=9)mul(j,j+x);//break;
	}x=1;
	for(int i=0;i<6;i++,x=x*10){
		for(int j=0;j<m;j++)
			if((j/x)%10!=9)a[j]=(a[j]-a[j+x]+mod)%mod;//break;
	}
	for(int i=0;i<m;i++){
		ans=ans^(i*a[i]);
		//if(a[i])cout<<a[i]<<" "<<i<<endl;
	}cout<<ans<<endl;
 	return 0;
}