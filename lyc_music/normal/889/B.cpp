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
//#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n;
string st,ans;
int nx[105];
int ls[105];
int vis[105];
int V[105];
int tot;
void What_will_Diana_eat_today()
{
	IOS;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>st;
		for (int i=0;i+1<st.length();i++)
		{
			if (nx[st[i]-'a'+1]>0&&nx[st[i]-'a'+1]!=st[i+1]-'a'+1)
			{
				cout<<"NO"<<endl;
				return;
			}
			nx[st[i]-'a'+1]=st[i+1]-'a'+1;
			if (ls[st[i+1]-'a'+1]>0&&ls[st[i+1]-'a'+1]!=st[i]-'a'+1)
			{
				cout<<"NO"<<endl;
				return;
			}
			ls[st[i+1]-'a'+1]=st[i]-'a'+1;
		}
		if (!nx[st[st.length()-1]-'a'+1]) nx[st[st.length()-1]-'a'+1]=-1;
		for (auto u:st) V[u-'a'+1]++;
	}
	for (int i=1;i<=26;i++)
	{
		tot+=(V[i]>0);
		if (nx[i]&&!ls[i])
		{
			int now=i;
			while (now&&now!=-1)
			{
				if (vis[now])
				{
					cout<<"NO"<<endl;
					return;
				}
				vis[now]=1;
				ans+=(char)(now+'a'-1);
				now=nx[now];
			}
		}
	}
	if (ans.size()!=tot) cout<<"NO"<<endl;
	else
	cout<<ans<<endl;
			
}
signed main()
{

	int T=1;
	while (T--)
	{
	 	  What_will_Diana_eat_today();
	}
}
/*

*/