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
vector<pair<int,string> >ans,Ans;
string ST;
int n,m,k;
void workh()
{
	int x=(m-1)/4,now=1;
	ans.push_back({m-1,"R"});
	ans.push_back({m-1,"L"});
}
void workl()
{
	ans.push_back({n-1,"U"});
	ans.push_back({n-1,"D"});
}
signed main()
{
	n=read(),m=read(),k=read();
	int now=1;
	while (now<n)
	{
		workh();
		ans.push_back({1,"D"});
		now++;
	}
	if (m>1) ans.push_back({1,"R"});
	now=2;
	while (now<=m)
	{
		workl();
		if (now!=m) ans.push_back({1,"R"});
		now++;
	}
	ans.push_back({m-1,"L"});
	ans.push_back({n-1,"U"});
	for (auto u:ans)
	{
		if (k<u.fi*u.se.length())
		{
//			cout<<"!"<<k<<endl;
			int p=k/u.se.length();
			if (p!=0&&u.se!="") Ans.push_back({p,u.se});
			k=0;
			break;
		}
		if (u.fi!=0&&u.se!="") Ans.push_back({u.fi,u.se});
		k-=u.fi*u.se.length();
	}
//	writeln(Ans.size());
	if (k>0) return puts("NO"),0;
	puts("YES");
	writeln(Ans.size());
	int lll=0;
	for (auto u:Ans)
	{
//		if (u.fi==1) lll++;
		cout<<u.fi<<" "<<u.se<<endl;
//		lll+=u.fi;
	}
//	writeln(lll);
	
		
}
/*
500 1 1237123123
*/