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
//#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
string st,st1;
int n,x,y,z;
void work(int k)
{
	int ls=0,rs=n+1;
	int l=1,r=n;
	st[0]=st1[k],st[n+1]=st1[k];
	vector<int>g;
	vector<int>g1;
	while (l<=r)
	{
		while (st[l]!=st1[k]) l++;
		while (st[r]!=st1[k]) r--;
		vector<int>g3,g4;
		vector<int>g5,g6;
		char x=' ',y=' ';
		if (k==1) x='b',y='c';
		else if (k==2) x='a',y='c';
		else if (k==3) x='a',y='b';
		if (l>r) 
		{
			swap(l,r);
			for (int i=l;i<=r;i++)
				if (st[i]==x) g3.push_back(i);
			for (int i=l;i<=r;i++)
				if (st[i]==y) g4.push_back(i);
			if (g3.size()>g4.size()) for (auto u:g3) g.push_back(u);
			else for (auto u:g4) g.push_back(u);
			break;
		}
		if (l==r)
		{
			l=ls+1,r=rs-1;
			for (int i=l;i<=r;i++)
				if (st[i]==x) g3.push_back(i);
			for (int i=l;i<=r;i++)
				if (st[i]==y) g4.push_back(i);
			for (int i=l;i<=r;i++)
				if (st[i]!=y&&st[i]!=x) g5.push_back(i);
			if (g3.size()>=g4.size()&&g4.size()>=g5.size()) for (auto u:g3) g.push_back(u);
			else 
			if (g4.size()>=g5.size()&&g4.size()>=g3.size()) for (auto u:g4) g.push_back(u);
			else for (auto u:g5) g.push_back(u);
			break;
		}
			
		for (int i=ls+1;i<l;i++)
			if (st[i]!=st1[k]&&st[i]==x) g3.push_back(i);
			else if (st[i]==y) g4.push_back(i);
		for (int i=rs-1;i>r;i--)
			if (st[i]!=st1[k]&&st[i]==x) g5.push_back(i);
			else if (st[i]==y) g6.push_back(i);
		if (min(g3.size(),g5.size())>min(g4.size(),g6.size()))
		{
			for (int i=0;i<min(g3.size(),g5.size());i++) 
			{
				int u=g3[i];
				g.push_back(u);
			}
			for (int i=0;i<min(g3.size(),g5.size());i++) 
			{
				int u=g5[i];
				g1.push_back(u);
			}
			g.push_back(l);
			if (l!=r) g1.push_back(r);
		} else
		{
			for (int i=0;i<min(g4.size(),g6.size());i++) 
			{
				int u=g4[i];
				g.push_back(u);
			}
			for (int i=0;i<min(g4.size(),g6.size());i++) 
			{
				int u=g6[i];
				g1.push_back(u);
			}
			g.push_back(l);
			if (l!=r) g1.push_back(r);
		}
		ls=l,rs=r;
		l++,r--;
//		cout<<l<<" "<<r<<endl;
	}
	if (g.size()+g1.size()>=n/2)
	{
//		cout<<"!"<<k<<endl;
		for (auto u:g) cout<<st[u];
		for (int i=g1.size()-1;i>=0;i--)
			cout<<st[g1[i]];
		exit(0);
	}
}
			
signed main()
{
	cin>>st;
	st1=" abc";
	n=st.length();
	st=' '+st+' ';
	for (int i=1;i<=n+1;i++)
	{
		if (st[i]=='a') x++;
		else if (st[i]=='b') y++;
		else if (st[i]=='c') z++;
	}
//	cout<x<<" "<<
	if (max({x,y,z})>=(n/2))
	{
		if (x>=y&&x>=z)
		{
			for (int i=1;i<=x;i++) cout<<'a';
		} else
		if (y>=x&&y>=z)
		{
			for (int i=1;i<=y;i++) cout<<'b';
		}
		else if (z>=x&&z>=y)
		{
			for (int i=1;i<=z;i++) cout<<'c';
		}
		return 0;
	}
	work(1);
	work(2);
	work(3);
	puts("IMPOSSIBLE");
}
/*

*/