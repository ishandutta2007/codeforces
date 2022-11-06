//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
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
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int a[15],sm,T,n,m;
vector<int>ans;
int pow(int x,int y)
{
	int res=1;
	for (int i=1;i<=y;i++) res=res*10;
	return res;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read(),m=read();
		sm=0;
		memset(a,0,sizeof(a));
		int x=n;
		for (int i=0;i<=10;i++) a[i]=x%10,x/=10,sm+=a[i];
//		for (int i=0;i<=10;i++) 
//		{
//			cout<<"!"<<a[i]<<endl;
//		}
		while (m>sm)
		{
			for (int i=1;i<=10;i++)
				if (a[i])
				{
					a[i]--;
					a[i-1]+=10;
					sm+=9;
					break;
				}
		}
		if (sm!=m)
		{
			int now=0;
			while ((sm--)>=m)
			{
				for (int i=0;i<=10;i++)	
				if (a[i]){a[i]--,now+=pow(10,i);break;}
			}
			ans.push_back(now);
		}
//		cout<<"!"<<sm<<endl;
		for (int i=0;i<=10;i++) 
		{
//			cout<<"!"<<a[i]<<endl;
			while (a[i]--) ans.push_back(pow(10,i));
		}
		for (auto u:ans) writesp(u);
		puts("");
		ans.clear();
	}
}
/*

*/