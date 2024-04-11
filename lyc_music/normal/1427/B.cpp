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
//#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,k;
string st;
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n>>k;
		cin>>st;
		char ls='L';
		vector<int>g;
		int now=0,p=-1;
		for (int i=0;i<st.length();i++)
			if (st[i]=='W') 
			{
				now++;
			}
		for (int i=0;i<st.length();i++)
			if (st[i]=='W') 
			{
				p=i;
				break;
			}
		if (p==-1)
		{
			if (k==1) now=1;
			else if (k>1) now=1+(k-1)*2;
		} else
		{
		int L=p;
		for (int i=p+1;i<st.length();i++)
			if (st[i]=='W')
			{
				g.push_back(i-1-p);
				p=i;
			}
		int R=st.length()-1-p;
		sort(g.begin(),g.end());
		for (auto u:g)
		{
			if (k>=u)
			{
				k-=u;
				now+=u*2+1;
			} else
			{
				now+=k*2;
				k=0;break;
			}
		}
		if (k>=R)
		{
			k-=R;
			now+=R*2;
		}
		else now+=k*2,k=0;
		now+=min(L,k)*2;}
		writeln(now);
	}
		
		
}
/*

*/