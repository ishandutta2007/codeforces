//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define IOS ios::sync_with_stdio(false)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
//#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T;
string st;
signed main()
{
	IOS;
	cin>>T;
	while (T--)
	{
		cin>>st;
//		string ans;
//		memset(g,-1,sizeof(g));
		vector<int>vis(27),vis1(27);
		set<int>g[27];
		for (int i=0;i<st.length();i++)
			g[st[i]-'a'].insert(i);
//		for (int i=0;i<26;i++)
//			if (g[i].size()==0) vis[i]=1;
		deque<int>ans;
		ans.clear();
		for (int j=0;j<st.length();j++)
		{
			char uu=st[j];
			if (vis[uu-'a']) continue;
			if (ans.empty())
			{
				ans.push_back(j);
				vis[uu-'a']++;
//				g[uu-'a'].insert(j);
			}
			else
			{
				while (!ans.empty())
				{
					int u=ans.back();
					if ((*(--g[st[u]-'a'].end()))>j&&st[u]<st[j])
					{
						vis[st[u]-'a']--;
						g[st[u]-'a'].erase(u);
//						cout<<u<<" "<<(*(--g[st[u]-'a'].end()))<<endl;
						ans.pop_back();
						continue;
					}
					break;
				}
				ans.push_back(j);
				vis[uu-'a']++;
//				g[uu-'a'].insert(j);
//				cout<<"!"<<endl;
			}
		}
//		cout<<endl;
		for (auto u:ans) cout<<st[u];
		cout<<endl;
	}	
}
/*

*/