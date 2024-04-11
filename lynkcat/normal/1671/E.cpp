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
#define mod 1000000009
#define int ll
#define N 5000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int f[N],pwp[N],hsh[N];
int h[N];
string st;
int n;
int gt(int l,int r)
{
	return (hsh[r]-hsh[l-1]*pwp[r-l+1]%mod+mod)%mod;
}
void solve(int k,int l,int r,int L)
{
	if (l==r)
	{
		// cout<<st[L];
		f[k]=1;
		h[k]=gt(L,L);
		return;
	}
	int mid=l+(r-l)/2;
	solve(k<<1,l,mid-1,L*2);
	// cout<<st[L];
	solve(k<<1|1,mid+1,r,L*2+1);
	f[k]=f[k<<1]*f[k<<1|1]%998244353*2%998244353;
	if (h[k<<1]==h[k<<1|1])
	{
		f[k]=f[k<<1]*f[k<<1|1]%998244353;
	}
	if (h[k<<1]<h[k<<1|1])
		h[k]=(h[k<<1]*pwp[r-mid+1]%mod+gt(L,L)*pwp[r-mid]%mod+h[k<<1|1])%mod;
	else
		h[k]=(h[k<<1|1]*pwp[r-mid+1]%mod+gt(L,L)*pwp[r-mid]%mod+h[k<<1])%mod;
	// cout<<k<<" "<<l<<" "<<r<<" "<<f[k]<<" "<<h[k]<<" "<<st[L]<<endl;
}
	
void BellaKira()
{
	cin>>n>>st;
	pwp[0]=1;
	for (int i=1;i<=(1<<n);i++) pwp[i]=pwp[i-1]*19260817%mod; 
	st=' '+st;
	for (int i=1;i<st.size();i++)
		hsh[i]=(hsh[i-1]*19260817%mod+(st[i]-'A'+1))%mod;
	solve(1,1,(1<<n)-1,1);
	cout<<f[1]<<endl;
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