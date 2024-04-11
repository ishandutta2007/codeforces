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
const int P=1e9+7;int n,Q,dp[100005],fc[100005],fi[100005],f[100005];
int cn[55],dl[55][55];char ch[100005];
inline int gtid(char ch) {return ch<='Z'?ch-'A':ch-'a'+26;}
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int C(int n,int m) {return 1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
int main()
{
	fc[0]=1,scanf("%s",ch+1);for(int i=1;i<=100000;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[100000]=ksm(fc[100000]);for(int i=100000;i;i--) fi[i-1]=1ll*fi[i]*i%P;
	n=strlen(ch+1)/2;for(int i=1;i<=n+n;i++) cn[gtid(ch[i])]++;
	int xs=1ll*fc[n]*fc[n]%P;for(int i=0;i<52;i++) if(cn[i]) xs=1ll*xs*fi[cn[i]]%P;
	dp[0]=1;for(int i=0;i<52;i++) if(cn[i]) for(int j=n;j>=cn[i];j--) dp[j]=(dp[j]+dp[j-cn[i]])%P;
	for(int i=0;i<52;i++) if(cn[i]) for(int j=0;j<52;j++) if(cn[j])
	{
		memcpy(f,dp,sizeof(f));for(int k=cn[i];k<=n;k++) f[k]=(f[k]-f[k-cn[i]]+P)%P;
		{if(i^j) for(int k=cn[j];k<=n;k++) f[k]=(f[k]-f[k-cn[j]]+P)%P;}dl[i][j]=dl[j][i]=f[n];
	}
	for(read(Q);Q--;) {int x,y;read(x),read(y),printf("%lld\n",2ll*xs*dl[gtid(ch[x])][gtid(ch[y])]%P);}
	return 0;
}