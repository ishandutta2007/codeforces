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
#define int ll
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,a[N];
int query(int x,int y,int z,int p)
{
	cout<<"? "<<x<<" "<<y<<" "<<z<<" "<<p<<endl;
	int xx;
	cin>>xx;
	return xx;
}
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n;
		int now1=n;
		for (int i=1;i<n;i+=2)
		{
			int x=query(2,i,i+1,1);
			if (x==2)
			{
				int y=query(2,i+1,i,1);
				if (y==1) 
				{
					now1=i+1;
					break;
				}
			} else
			if (x==1)
			{
				now1=i;
				break;
			}
		}
		a[now1]=1;
		for (int i=1;i<=n;i++)
			if (now1!=i)
			{
				a[i]=query(1,now1,i,n-1);
			}
		cout<<"! ";
		for (int i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
		
		
		
}
/*

*/