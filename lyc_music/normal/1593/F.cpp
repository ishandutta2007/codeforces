//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1000000007
#define mod 998244353
//#define int ll
#define N 41
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
string st;
struct node
{
	int a,b,c,d,e;
}dp[N][N<<1][N][N];
int vis[N][N<<1][N][N];
int T,n,A,B;
signed main()
{
	IOS;
	cin>>T;
	while (T--)
	{
		cin>>n>>A>>B;
		cin>>st;
		st=' '+st;
		dp[0][40][0][0]={0,0,0,0,0};
		vis[0][40][0][0]=1;
		for (int i=0;i<n;i++)
			for (int p=0;p<=80;p++)
				for (int j=0;j<A;j++)
					for (int k=0;k<B;k++)
					if (vis[i][p][j][k])
					{
						if (p+1<=80)  dp[i+1][p+1][j][(k*10+(st[i+1]-'0'))%B]={i,p,j,k,1},vis[i+1][p+1][j][(k*10+(st[i+1]-'0'))%B]=1;
						if (p-1>=0) dp[i+1][p-1][(j*10+(st[i+1]-'0'))%A][k]={i,p,j,k,0},vis[i+1][p-1][(j*10+(st[i+1]-'0'))%A][k]=1;
					}
		int ans=inf;
		string ans1="-1";
		node lst={114514,0,0,0,0};
			for (int p=0;p<=80;p++)
				for (int j=0;j<1;j++)
					for (int k=0;k<1;k++)
					{
						if (vis[n][p][j][k])
						{
							if ((abs(p-40))<ans)
							{
								ans=abs(p-40);
								lst={n,p,j,k,0};
							}
						}
					}
		if (ans!=inf)
		{
			ans1="";
//			cout<<inf<<endl;
			while (1)
			{
				if (dp[lst.a][lst.b][lst.c][lst.d].e==1)
				{
					ans1='B'+ans1;
				} else
				ans1='R'+ans1;
				lst=dp[lst.a][lst.b][lst.c][lst.d];
				if (lst.a==0) break;
			}
			char ch=ans1[0];
			bool bl=1;
			for (auto u:ans1)if (u!=ch) bl=0;
			if (bl) ans1="-1";
		}
		cout<<ans1<<endl;
		memset(vis,0,sizeof(vis));
	}
						
					
}
/*

*/