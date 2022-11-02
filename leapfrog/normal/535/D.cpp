//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int N=1000005,P=1e9+7;int M,n,m,a[N],nx[N];char ch[N],fg[N];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	read(M),read(m),scanf("%s",ch+1),n=strlen(ch+1),nx[1]=0;
	for(int i=2,k=0;i<=n;i++)
	{
		while(k&&ch[k+1]^ch[i]) k=nx[k];
		nx[i]=(k+=ch[k+1]==ch[i]);
	}
	for(int k=nx[n];k;k=nx[k]) fg[k]=1;
	//for(int i=1;i<=n;i++) if(fg[i]) printf("%d",i);
	for(int i=1;i<=m;i++) read(a[i]);
	sort(a+1,a+m+1);for(int i=2;i<=m;i++)
		if(a[i-1]+n>a[i]&&!fg[n-a[i]+a[i-1]]) return puts("0"),0;
	int rs=m?n:0;for(int i=2;i<=m;i++) rs+=n-max(0,a[i-1]+n-a[i]);
	return printf("%d\n",ksm(26,M-rs)),0;
}