//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
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
int n,m;
int ans;
string st;
int x;
char y;
bool chk(int xx)
{
	if (xx<=0) return 0;
	if (xx+2>n) return 0;
	if (st[xx]=='a'&&st[xx+1]=='b'&&st[xx+2]=='c') return 1;
	return 0;
}
void LYC_music()
{
	cin>>n>>m;
	cin>>st;
	st=' '+st;
	for (int i=3;i<=n;i++)
	{
		if (st[i-2]=='a'&&st[i-1]=='b'&&st[i]=='c') ans++;
	}
	while (m--)
	{
		cin>>x>>y;
		if (chk(x-1)||chk(x-2)||chk(x)) ans--;
		st[x]=y;
		if (chk(x-1)||chk(x-2)||chk(x)) ans++;
//		cout<<ans<<" "<<(chk(x-1))<<" "<<x-1<<endl;
	cout<<ans<<endl;
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