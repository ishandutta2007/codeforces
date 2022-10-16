#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=5005;

int n,m,cnt[MAXN],fac[MAXN],ifac[MAXN];
int dp[2][MAXN],f[2][MAXN];
void solve()
{
	readint(n);
	memset(cnt,0,sizeof(int)*(n+1));
	for(int x,i=1;i<=n;++i)readint(x),++cnt[x];
	m=n;for(;!cnt[m];--m);
	if(cnt[m]>=2){printf("0\n");return;}
	n/=2;
	fac[0]=1;for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[n]=qmi(fac[n],MOD-2);for(int i=n;i;--i)ifac[i-1]=1ll*ifac[i]*i%MOD;
	memset(dp[0],0,sizeof(int)*(n+1)),memset(dp[1],0,sizeof(int)*(n+1));
	dp[1][0]=1;
	for(int t=m-1;t;--t)
	{
		int x=cnt[t];
		if(!x)continue;
		memset(f[0],0,sizeof(int)*(n+1)),memset(f[1],0,sizeof(int)*(n+1));
		for(int w=0;w<=1;++w)
			for(int i=0;i<=n;++i)
				for(int v=0;v<=w;++v)
					for(int j=max(x-v-1,0);j<=i && v+j<=x;++j)
					{
						int o=x-v-j;
						if(!o)
							inc(f[w-v][i-j],1ll*fac[i]*ifac[i-j]%MOD*ifac[j]%MOD*dp[w][i]%MOD);
						else if(w && !v && i+w-v-j<=n && i+w-v-j+o-1>=0)
							inc(f[1][i+w-v-j],1ll*fac[i]*ifac[i-j]%MOD*ifac[j]%MOD*dp[w][i]%MOD);
					}
		memcpy(dp[0],f[0],sizeof(int)*(n+1)),memcpy(dp[1],f[1],sizeof(int)*(n+1));
	}
	printf("%d\n",dp[0][0]);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}