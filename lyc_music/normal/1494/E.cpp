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
int n,q;
map<pa,int>Mp;
int cntx,cnty;
signed main()
{
	IOS;
	cin>>n>>q;
	for (int i=1;i<=q;i++)
	{
		char ch,ch1;
		int x,y;
		cin>>ch;
		if (ch=='+')
		{
			cin>>x>>y>>ch1;
			Mp[{x,y}]=ch1;
			if (Mp[{y,x}])
			{
				if (Mp[{y,x}]==ch1)
				{
					cntx++;
				}
				else 
				cnty++;
			}
		} else
		if (ch=='-')
		{
			cin>>x>>y;
			if (Mp[{y,x}])
			{
				if (Mp[{y,x}]==Mp[{x,y}])
				{
					cntx--;
				}
				else 
				cnty--;
			}
			Mp[{x,y}]=0;
		} else
		{
			cin>>x;
			if (x%2==1) 
			{
				if (cntx+cnty) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
			} else
			{
				if (cntx) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
			}
		}
	}
}
/*

*/