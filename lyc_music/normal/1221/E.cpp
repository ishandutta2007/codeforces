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
int T,a,b,n;
string st;
signed main()
{
//	IOS;
	cin>>T;
	while (T--)
	{
		cin>>a>>b>>st;
		n=st.length();
		st=' '+st;
		int lst=0;
		st+='X';
		n++;
		vector<int>g;
		for (int i=1;i<=n;i++)
		{
			if (st[i]=='X')
			{
				if (lst!=i-1)
				{
					g.push_back(i-lst-1);
				}
				lst=i;
			}
		}
		int x=0,y=0;
		int ans=0;
		sort(g.begin(),g.end());
		for (int i=0;i<g.size();i++)
		{
			int u=g[i];
		
//			cout<<i<<" "<<u<<endl;
			if (u<b) continue;
			if (u>=b&&u<a)
			{
				x++;
				if (i==g.size()-1)
				{
					if (!x&&(y%2==1)) ans=1;
				}
			} else
			if (u>=a&&u<2*b)
			{
				y++;
				if (i==g.size()-1)
				{
					if (!x&&(y%2==1)) ans=1;
				}
			} else
			{
				if (i!=g.size()-1) 
				{
					break;
				}
//				cout<<"?"<<i<<endl;
				for (int j=0;u-a-j>=0;j++)
				{
					int ax=j,ay=u-a-j,bl=0;
					if (ax>=a&&ax<2*b) y++;
					else if (ax>=b&&ax<a) x++;
					else if (ax>=2*b) bl=1;
					
					if (ay>=a&&ay<2*b) y++;
					else if (ay>=b&&ay<a) x++;
					else if (ay>=2*b) bl=1;
//					cout<<ax<<","<<ay<<" "<<x<<" "<<y<<endl;
					
					if (!x&&(y%2==0)&&!bl)
					{
						ans=1;
						break;
					}
					
					if (ax>=a&&ax<2*b) y--;
					else if (ax>=b&&ax<a) x--;
					
					if (ay>=a&&ay<2*b) y--;
					else if (ay>=b&&ay<a) x--;
				}
			}
		}
		if (ans) puts("YES");
		else puts("NO");
	}
}
/*

*/