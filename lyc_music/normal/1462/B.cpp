//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
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
int T,a[1005];
int n;
int ans;
string st;
signed main()
{
//	IOS;
	cin>>T;
	while (T--)
	{
		cin>>n;
		cin>>st;
		for (int i=1;i<=8;i++) a[i]=0;
		string st1="";
		st=' '+st;
		for (int i=1;i<=n;i++)
		{
			st1+=st[i];
			if (st1=="2") a[1]=1;
			else if (st1=="20") a[2]=1;
			else if (st1=="202") a[3]=1;
			else if (st1=="2020") a[4]=1;
		}
		st1="";
		for (int i=n;i>=1;i--)
		{
			st1=st[i]+st1;
			if (st1=="0") a[5]=1;
			else if (st1=="20") a[6]=1;
			else if (st1=="020") a[7]=1;
			else if (st1=="2020") a[8]=1;
		}
		ans=a[4]|a[8]|(a[2]&a[6])|(a[7]&a[1])|(a[5]&a[3]);
		if (ans) puts("YES");
		else puts("NO");
	}
		
}
/*

*/