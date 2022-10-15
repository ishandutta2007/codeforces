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
#define inf 1e9
#define mod 998244353
//#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
void BellaKira()
{
	int n;
	string st,st1;
	cin>>n;
	cin>>st>>st1;
	int ans=inf;
	int x=0,y=0;
	int xx=0,yy=0;
	for (int i=0;i<n;i++)
		if (st[i]!=st1[i]) 
		{
			if (st[i]=='1') x++;
			else y++;
		} else
		{
			if (st[i]=='1') xx++;
			else yy++;
		}
	if (xx-yy==1) ans=min(ans,xx+yy);
		if (x==y) ans=min(ans,x+y);
	if (ans==inf) cout<<"-1"<<endl;
	else cout<<ans<<endl;
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