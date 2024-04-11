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
#define get(x) __builtin_popcount(x)
const int maxn=1e6+5e4+5,M=34005,mod=1e9+7;
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
int n,m,k,x,a[19][maxn],b[19][maxn],c[maxn],d[maxn],g[maxn],f[maxn],ans;
void And(int *f,int F){
	for(int k=1;k<n;k=k*2)
		for(int len=k*2,i=0;i<n;i+=len)
			for(int j=0;j<k;j++)
				if(F)f[i+j]=(f[i+j]+f[i+j+k])%mod;
				else f[i+j]=(f[i+j]-f[i+j+k]+mod)%mod;
}
void Or(int *f,int F){
	for(int k=1;k<n;k=k*2)
		for(int len=k*2,i=0;i<n;i+=len)
			for(int j=0;j<k;j++)
				if(F)f[i+j+k]=(f[i+j+k]+f[i+j])%mod;
				else f[i+j+k]=(f[i+j+k]-f[i+j]+mod)%mod;
}
void Xor(int *f,int F){
	for(int k=1;k<n;k=k*2)
		for(int len=k*2,i=0;i<n;i+=len)
			for(int j=0;j<k;j++){
				int x=f[i+j],y=f[i+j+k];
				f[i+j]=(x+y)%mod;f[i+j+k]=(x-y+mod)%mod;
				if(!F)f[i+j]=1ll*f[i+j]*(mod/2+1)%mod,f[i+j+k]=1ll*f[i+j+k]*(mod/2+1)%mod;
			}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();f[0]=0,f[1]=1;m=17;
	for(int i=1;i<=n;i++)x=read(),c[x]++;n=(1<<m);
	for(int i=2;i<n;i++)f[i]=(f[i-1]+f[i-2])%mod;
	for(int i=0;i<n;i++)a[get(i)][i]=d[i]=g[i]=c[i];
	for(int i=0;i<=m;i++)Or(a[i],1);
	for(int i=0;i<=m;i++)
		for(int k=0;k<=i;k++)
			for(int j=0;j<n;j++)
				b[i][j]=(b[i][j]+1ll*a[i-k][j]*a[k][j]%mod)%mod;
	for(int i=0;i<=m;i++)Or(b[i],0);
	for(int i=0;i<n;i++)d[i]=b[get(i)][i];
	Xor(g,1);for(int i=0;i<n;i++)g[i]=1ll*g[i]*g[i]%mod;Xor(g,0);
	for(int i=0;i<n;i++)d[i]=1ll*d[i]*f[i]%mod,g[i]=1ll*g[i]*f[i]%mod,c[i]=1ll*c[i]*f[i]%mod;
	And(d,1),And(g,1),And(c,1);
	for(int i=0;i<n;i++)d[i]=1ll*d[i]*g[i]%mod*c[i]%mod;
	And(d,0);for(int i=0;i<n;i++)if(get(i)==1)ans=(ans+d[i])%mod;cout<<ans<<endl;
 	return 0;
}


/*********************************************************************
    :louhao088
    : 2022-04-19 20:18
*********************************************************************/