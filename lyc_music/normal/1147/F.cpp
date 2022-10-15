//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
//#define int ll
#define N 505
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N][N],p[N][N];
int nowx;
queue<int>q;
bool cmp(int x,int y)
{
	return a[nowx][x]<a[nowx][y];
}
int w2[N],w1[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		w1[i]=w2[i]=0;
		for (int j=1;j<=n;j++)
		{
			a[i][j]=read();
			p[i][j]=j;
		}
	}
	cout<<"B"<<endl;
	char ch;
	cin>>ch;
	int x=1;
	cin>>x;
	if ((ch=='D')^(x>n)) 
	{
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				a[i][j]=-a[i][j];
	}
	for (int i=1;i<=n;i++)
	{
		nowx=i;
		sort(p[i]+1,p[i]+n+1,cmp);
		q.push(i);
	}
	while (!q.empty())
	{
		int now=q.front();
		q.pop();
		for (int i=1;i<=n;i++)
		{
			int to=p[now][i];
			if (!w2[to]||a[now][to]>a[w2[to]][to])
			{
				if (w2[to]) q.push(w2[to]);
				w1[now]=to;
				w2[to]=now;
				break;
			}
		}
	}
	do
	{
		cout<<(x<=n?w1[x]+n:w2[x-n])<<endl;
		cin>>x;
	}while (x>=0);
}
signed main()
{
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/