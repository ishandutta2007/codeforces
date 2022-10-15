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
#define int ll
#define N 2005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,s[N];
string st;
int ans;
signed main()
{
	cin>>T;
	while(T--){
		cin>>st;
		n=st.length();
		st=' '+st;
		for (int i=1;i<=n;i++)
		{
			if (st[i]!='0') s[i]=s[i-1]+1;
			else s[i]=s[i-1];
		}
		ans=s[n];
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if (st[i]=='2'&&st[j]=='5'||st[i]=='0'&&st[j]=='0'||st[i]=='5'&&st[j]=='0'||st[i]=='7'&&st[j]=='5')
				{
					ans=min(ans,n-i-1);
				}
		cout<<ans<<endl;
	}
}
/*

*/