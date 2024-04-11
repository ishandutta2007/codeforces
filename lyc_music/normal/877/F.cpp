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
#define int ll
#define N 300005
#define B 405
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int Mp[N];
int n,K,a[N],s[N],t[N];
int S1[N],S2[N],S3[N];
int nowans,ans[N];
vector<int>g; 
int From[N];
int q;
int l,r;
struct nd
{
	int l,r,id;
}Q[N];
void ad(int x,int y)
{
	if (y==0) nowans+=Mp[S2[x]];
	else nowans+=Mp[S3[x]];
	Mp[S1[x]]++;
}
void del(int x,int y)
{
	Mp[S1[x]]--;
	if (y==0) nowans-=Mp[S2[x]];
	else nowans-=Mp[S3[x]];
}
bool cmp(nd x,nd y)
{
	return (From[x.l]^From[y.l])?x.l<y.l:((From[x.l]&1)?x.r<y.r:x.r>y.r);
}
signed main()
{
	n=read();K=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		if (a[i]==2) a[i]-=3;
	}
	for (int i=1;i<=n;i++)
	{
		t[i]=read();
		s[i]=s[i-1]+a[i]*t[i];
	}
	for (int i=0;i<=n;i++)
	{
		g.push_back(s[i]);
		g.push_back(s[i]-K);
		g.push_back(s[i]+K);
	}
	sort(g.begin(),g.end());
	g.erase(unique(g.begin(),g.end()),g.end());
	for (int i=0;i<=n;i++)
	{
		S1[i]=lower_bound(g.begin(),g.end(),s[i])-g.begin()+1;
		S2[i]=lower_bound(g.begin(),g.end(),s[i]+K)-g.begin()+1;
//		cout<<i<<" "<<S1[i]<<" "<<S2[i]<<" "<<S3[i]<<endl;
		S3[i]=lower_bound(g.begin(),g.end(),s[i]-K)-g.begin()+1;
	}
	for (int i=1;i<=n+1;i++) From[i-1]=(i-1)/B+1;
	q=read();
	for (int i=1;i<=q;i++)
	{
		Q[i].l=read()-1,Q[i].r=read(),Q[i].id=i;
	}
	sort(Q+1,Q+q+1,cmp);
	l=1,r=0;
	for (int i=1;i<=q;i++)
	{
		while (r<Q[i].r)
		{
			ad(++r,1);
		}
		while (r>Q[i].r)
		{
			del(r--,1);
		}
		while (l<Q[i].l)
		{
			del(l++,0);
		}
		while (l>Q[i].l)
		{
			ad(--l,0);
		}
		ans[Q[i].id]=nowans;
	}
	for (int i=1;i<=q;i++) writeln(ans[i]);
}
/*

*/