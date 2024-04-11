//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 1000000007
#define int ll
#define N 1000005
#define ad(x,y) (x=(x+y)%mod)
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int fac[N],inv[N],a[N],s[N],vis[N],f[N],ans;
int n;
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
inline int C(int x,int y)
{
	if (x<y||y<0) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void LYC_music()
{
	n=read();
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=quickPower(fac[n],mod-2);
	for (int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%mod;
	for (int i=1;i<=n;i++)
		a[read()]+=1;
	s[0]=C(n-1,0);
	for (int i=1;i<n;i++)
	{
		ad(s[i],s[i-1]);
		ad(s[i],C(n-1,i));
//		cout<<i<<" "<<s[i]<<endl;
	}
	for (int i=1;i<=n;i++)
	{
		ad(f[i],((s[n-1]-s[i-1]+mod)%mod-((i==1)?0ll:s[i-2])+mod)%mod);
//		cout<<i<<" "<<f[i]<<endl;
	}
	reverse(f+1,f+n+1);
	for (int i=1;i<=n;i++) ad(f[i],f[i-1]);
//	cout<<i<<" "<<f[i]<<endl;
	for (int i=2;i<N;i++)
	{
		if (vis[i]) continue;
		for (int j=2*i;j<N;j+=i) vis[j]=1;
		int lst=n;
		for (int j=i;j<N;j+=i)
			lst-=a[j];
//		cout<<"?"<<lst<<" "<<i<<" "<<ans<<endl;
		int now=1;
		for (int j=i;j<N;j*=i)
		{
			int x=0;
			for (int k=j;k<N;k+=j)
				if ((k/j)%i!=0)
					x+=a[k];
			ad(ans,(now)*(f[lst+x]-f[lst]+mod)%mod);
//			cout<<j<<" "<<lst<<" "<<x<<" "<<f[lst+x]-f[lst]<<endl;
			lst+=x;
			now++;
		}
	}
	writeln(ans);
}
signed main()
{
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*
3
8 12 12
3
4 6 6 
*/