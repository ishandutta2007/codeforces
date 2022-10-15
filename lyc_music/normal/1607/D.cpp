//The Hunting Party - Keys To The Kingdom
//~
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
//#define int llasdiuogqwe
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,w[N];
string st;
void What_will_Diana_eat_today()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>w[i];
	cin>>st;
	vector<int>g,g1;
	int x=0,y=0,a=0,b=0;
	int ans=1;
	st=' '+st;
	for (int i=1;i<=n;i++)
		if (st[i]=='R')
			x++,g.push_back(w[i]);
		else y++,g1.push_back(w[i]);
	sort(g.begin(),g.end());
	int m=g.size();
	for (int i=m-1;i>=0;i--)
	{
		if (g[i]<=n-(m-1-i)) continue;
		ans=0;
//		cout<<"!"<<g[i]<<endl;
		break;
	}
	sort(g1.begin(),g1.end());
	m=g1.size();
	for (int i=0;i<m;i++)
	{
		if (g1[i]>=i+1) continue;
		ans=0;
		break;
	}
	if (ans) puts("Yes");
	else puts("No");
		
}
signed main()
{
	int T=1;
	cin>>T;
	while (T--)
	{
	 	  What_will_Diana_eat_today();
	}
}
/*

*/