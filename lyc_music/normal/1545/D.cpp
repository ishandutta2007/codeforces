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
#define N 2005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
map<int,int>Mp,Mp1;
int n,m,a[N][N],S[N],v[N],s,now2,nowsum,SS[N];
signed main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		int now=0;
		for (int j=1;j<=n;j++)	cin>>a[j][i],now+=a[j][i]-a[j][i-1];
		SS[i]=now;
		if (i!=1)
		{
		Mp1[now]++;
		if (Mp1[now]>Mp1[s]) s=now;
		}
	}
	for (int i=2;i+1<=m;i++)
	{
		int sum=0;
		for (int j=1;j<=n;j++)
			sum+=a[j][i+1]*a[j][i+1]+a[j][i-1]*a[j][i-1]-a[j][i]*a[j][i]*2;
		if (SS[i]==s&&SS[i+1]==s) now2=sum;
		S[i]=sum;
	}
//	cout<<s<<" "<<now2<<" "<<Mp[now2]<<endl;
	for (int i=1;i<=m;i++)
	{
		int now1=0;
		for (int j=1;j<=n;j++) now1+=a[j][i]-a[j][i-1];
		if (now1!=s&&i!=1)
		{
//			cout<<i<<"!"<<" "<<now1<<" "<<S[i]<<endl;
			for (int j=1;j<=n;j++)
			{
				S[i]+=a[j][i]*a[j][i]*2;
				a[j][i]+=s-now1;
				S[i]-=a[j][i]*a[j][i]*2;
				if (S[i]==now2)
				{
					cout<<i-1<<" "<<a[j][i]<<endl;
					return 0;
				}
				S[i]+=a[j][i]*a[j][i]*2;
				a[j][i]-=s-now1;
				S[i]-=a[j][i]*a[j][i]*2;
			}
			cout<<"!"<<i<<endl;
		}
	}	
}
/*

*/