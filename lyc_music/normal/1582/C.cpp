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
#define N 3000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n;
int ans;
int b[N];
string st,st1;
signed main()
{
	IOS;
	cin>>T;
	while (T--)
	{
		cin>>n;
		cin>>st;
		st=' '+st;
		ans=inf;
		for (int i=1;i<=26;i++)
		{
			bool bl=1;
			string st1="";
			int cnt=0;
			b[cnt]=0;
			for (int j=1;j<=n;j++)
				if (st[j]!=(char)(i+'a'-1)) st1+=st[j],cnt++,b[cnt]=0;
				else
				{
					b[cnt]++;
				}
			for (int j=0;j<(int)st1.length()-1-j;j++)
				if (st1[j]!=st1[st1.length()-1-j]) bl=0;
			int x=st.length()-st1.length()-1;
//			cout<<i<<" "<<x<<endl;
			for (int j=0;j<cnt-j;j++) x-=min(b[j],b[cnt-j])*2;
			if (cnt%2==0) x-=b[cnt/2];
//			cout<<i<<" "<<x<<endl;
			if (bl) ans=min(ans,x);
		}
		if (ans==inf) cout<<"-1"<<endl;else
		cout<<ans<<endl;
	}
		
}
/*

*/