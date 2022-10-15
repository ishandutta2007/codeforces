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
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}

int n,m;
int tot;
int f[5];
int query(int x,int y)
{
	int res;
	cout<<"SCAN "<<x<<" "<<y<<endl;
	cin>>res;
	return res;
}
int fd(int x,int y)
{
	if (x<=0||x>n||y<=0||y>m) return 0;
	int res;
	cout<<"DIG "<<x<<" "<<y<<endl;
	cin>>res;
	return res;
}
void BellaKira()
{
	cin>>n>>m;
	f[1]=query(1,1)+4;
	f[2]=query(1,m)-2*m+2;
	int sumx=(f[1]+f[2])/2;
	int sumy=(f[1]-f[2])/2;
	// cout<<"????"<<f[1]<<" "<<f[2]<<endl;
	int delx=query(sumx/2,1)+2-sumy;	
	int dely=query(1,sumy/2)+2-sumx;
	// cout<<"?"<<sumx<<" "<<delx<<" "<<sumy<<" "<<dely<<endl;
	if (fd((sumx+delx)/2,(sumy+dely)/2))
	{
		fd((sumx-delx)/2,(sumy-dely)/2);
	} else
	{
		fd((sumx-delx)/2,(sumy+dely)/2);
		fd((sumx+delx)/2,(sumy-dely)/2);
	}
}
signed main()
{
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/