//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define y1 yyds 
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
#define N 6005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,x[N],y[N],cnt[5][5][5];
ll ans,ans1;
int work(int x,int y,int x1,int y1,int x2,int y2)
{
	return ((x*(y1-y2)+x1*(y2-y)+x2*(y-y1))%4+4)%4;
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		x[i]=read(),y[i]=read();
	}
	for (int i=1;i<=n;i++)
	{
		memset(cnt,0,sizeof(cnt));
		for (int j=1;j<=n;j++)
			if (i!=j)
			{
				cnt[x[j]%4][y[j]%4][__gcd(abs(x[i]-x[j]),abs(y[i]-y[j]))%4]++;
//				cout<<(x[j]%4)<<" "<<(y[j]%4)<<" "<<__gcd(abs(x[i]-x[j]),abs(y[i]-y[j]))%4<<endl;
			}
//		puts("");
		for (int j=0;j<=3;j++)
			for (int k=0;k<=3;k++)
				for (int p=0;p<=3;p++)
				{
					int now=cnt[j][k][p];
					cnt[j][k][p]--;
					for (int j1=(j&1);j1<=3;j1+=2)
						for (int k1=(k&1);k1<=3;k1+=2)
							for (int p1=(p&1);p1<=3;p1+=2)
							{
								int S=work(x[i],y[i],j,k,j1,k1);
//								cout<<S<<endl;
								S/=2;
								int p2=__gcd(abs(j-j1),abs(k-k1));
								int a=S-(p1+p+p2)/2+1;
								a=(a%2+2)%2;
//								cout<<a<<endl;
								if (a%2==1)
								{
									if (p%2==0) ans+=cnt[j1][k1][p1]*now;
									else ans1+=cnt[j1][k1][p1]*now;
								}
							}
					cnt[j][k][p]++;
				}
	}
	writeln(ans/6+ans1/2);			 
}
/*

				
*/