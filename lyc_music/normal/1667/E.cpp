//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 800005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n;
int fac[N],inv[N];
int f[N];
#define ad(x,y) (x=(x+y)%mod)
int quickPower(int x,int y)
{
    int res=1;
    while (y)
    {
        if(y&1)res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
void BellaKira()
{
	cin>>n;
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=quickPower(fac[n],mod-2);
	for (int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%mod;
	int sm=0;
	for (int i=n;i>=2;i--)
	{
		f[i]=(f[i]-sm+mod)%mod;
		int S=n-(n-1)/2-i;
		if (S<0) continue;
		// cout<<"?"<<i<<" "<<S<<" "<<fac[i+S-1]<<" "<<inv[i-1]%mod<<" "<<inv[S]%mod*fac[n-i]%mod*(i-1)%mod<<endl;
		
		
		f[i]=(f[i]+fac[i+S-1]*inv[i-1]%mod*inv[S]%mod*fac[n-i]%mod*fac[i-2]%mod*(i-1)%mod)%mod;
		sm=(sm+fac[i+S-1]*inv[i-1]%mod*inv[S]%mod*fac[n-i]%mod*fac[i-2]%mod)%mod;
		
		
		// for (int j=0;j<=n-i;j++)
			// if (n-(i+j-1)>(n-1)/2)
			// {
				// if (i==1&&j!=0) break;
				// // cout<<"!"<<i<<" "<<j<<" "<<endl;
				// if (i==1&&j==0)
				// {
					// f[i]=(f[i]+fac[n-1])%mod;
					// break;
				// }
				// f[i]=(f[i]+inv[j]%mod*fac[i+j-2]%mod)%mod;
				// if (i!=1)
					// sm=(sm+fac[n-i]*inv[j]%mod*fac[i+j-2]%mod)%mod;
// 				
			// }
	}
	f[1]=(fac[n-1]-sm+mod)%mod;
	for (int i=1;i<=n;i++)
		cout<<f[i]<<" ";
	cout<<endl;
	
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/