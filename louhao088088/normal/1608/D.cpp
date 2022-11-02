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
const int maxn=2e5+5,M=34005,mod=998244353;
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
int n,m,F,s1,s2,t,ans,t1,t2,sum[maxn];
char a[maxn][5];
int Pow(int x,int y){int res=1;while(y){if(y&1)res=res*x%mod;y=y/2;x=x*x%mod;}return res;}
int C(int x,int y)
{
	sum[0]=1;
	for(int i=1;i<=x;i++)sum[i]=sum[i-1]*i%mod;
	//cout<<x<<" "<<y<<endl;
	return sum[x]*Pow(sum[y],mod-2)%mod*Pow(sum[x-y],mod-2)%mod;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();s1=1,s2=1;t=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a[i]+1);
		if(a[i][1]==a[i][2]&&a[i][1]!='?')F=1;
		if(a[i][1]=='B')s1=0,t1++;
		if(a[i][1]=='W')s2=0,t2++;
		if(a[i][2]=='B')s2=0,t1++;
		if(a[i][2]=='W')s1=0,t2++;
		if(a[i][1]=='?'&&a[i][2]=='?')t++;
	}
	ans+=C(2*n-t1-t2,n-t1);
	//cout<<ans<<endl;
	if(!F)
	{
		ans=ans-Pow(2,t)+mod;ans=ans%mod;
		ans=ans+s1+s2;ans%=mod;
	}
	cout<<ans;
 	return 0;
}