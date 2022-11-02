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
const int maxn=1e6+7,M=34005,mod=1e9+7;
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
int n,x,m,a[maxn],ans,k;
int Pow(int x,int y){int res=1;while(y){if(y&1)res=res*x%mod;x=x*x%mod;y=y/2;}return res;}
int f[maxn],inv[maxn],p[maxn];
int get(int n,int k){
	f[0]=0;
	for(int i=1;i<=k+2;i++){
		f[i]=f[i-1]+Pow(i,k);
		f[i]%=mod;//cout<<f[i]<<endl;
	}int res=1,s=0;
	for(int i=1;i<=k+2;i++){
		res=res*(n-i)%mod;
		p[i]=inv[k+2-i];
		p[i]=p[i]*inv[i-1]%mod;
		int zz=k+2-i;
		if(zz%2==1)p[i]=mod-p[i];
		//cout<<p[i]<<" "<<f[i]<<endl;
	}if(n<=k+2)return f[n];
	for(int i=1;i<=k+2;i++){
		int iv=Pow(n-i,mod-2);
		s=s+f[i]*p[i]%mod*res%mod*iv%mod;s%=mod;
	}return s;
}
signed main()
{
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	inv[0]=inv[1]=1;
	for(int i=2;i<=1e6+5;i++)
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	for(int i=2;i<=1e6+5;i++)inv[i]=inv[i-1]*inv[i]%mod;
	n=read(),m=read();
	ans=get(n,m);cout<<ans<<endl;
 	return 0;
}