//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define inf 1e18
#define mod 998244353
#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[15];
int T;
char c;
string st;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while (T--)
	{
		cin>>n>>c>>st;
		int ans=inf;
		int bl=1;
		for (auto u:st)
		{
			if (u!=c) bl=0;
		}
		if (bl)
		{
			cout<<0<<endl;
			continue;
		}
//		cout<<"!"<<endl;
		for (int i=0;i<st.length();i++)
		{
			int p=1;
			for (int j=i;j<st.length();j+=i+1)
				if (st[j]!=c) p=0;
			if (p)
			{
				cout<<1<<endl;
				cout<<i+1<<endl;
				ans=1;
				break;
			}
		}
		if (ans!=1)
		{
			cout<<"2\n"<<n-1<<" "<<n<<endl;
		}
	}
}
/*

*/