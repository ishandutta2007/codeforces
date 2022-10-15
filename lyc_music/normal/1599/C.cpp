//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n;
double p;
double C(int x,int y)
{
	if (x<y||y<0) return 0.0;
	double res=1.0;
	for (int i=x;i>x-y;i--)	res=res*i/(x-i+1);
	return res;
}
void LYC_music()
{
	cin>>n>>p;
	for (int i=0;i<=n;i++)
	{
		double now=0;
		for (int j=2;j<=3;j++)
			now+=C(i,j)*C(n-i,3-j)/C(n,3);
		for (int j=1;j<=1;j++)
			now+=C(i,j)*C(n-i,3-j)/C(n,3)/2;
//		cout<<"?"<<i<<" "<<now<<" "<<p<<endl;
		if (now>=p) 
		{
			cout<<i<<endl;
			return;
		}
	}
}
signed main()
{
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/