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
#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m;
set<int>S;
int col[N];
int tr[N];
int s[N];
void update(int x,int y)
{
	// cout<<"upd "<<x<<" "<<y<<" "<<col[x]<<" "<<s[col[x]]<<endl;
	while (x<=n)
	{
		tr[x]+=y;
		x+=(x&-x);
	}
}
int query(int x)
{
	int res=0;
	while (x>0)
	{
		res+=tr[x];
		x-=(x&-x);
	}
	return res;
}
void BellaKira()
{
	cin>>n>>m;
	S.insert(1);
	S.insert(n+1);
	col[1]=1;
	for (int i=1;i<=m;i++)
	{
		string st;
		cin>>st;
		if (st=="Color")
		{
			int l,r,x;
			cin>>l>>r>>x;
			auto it=S.lower_bound(l);
			// if (l==58&&r<70) cout<<"???"<<l<<" "<<r<<" "<<x<<endl;
			if ((*it)!=l)
			{
				auto it1=it;
				--it;
				// cout<<(*it)<<" "<<l<<" "<<col[(*it)]<<endl;
				if (col[(*it)]!=x)
				{
					update(l,s[col[(*it)]]-s[x]);
					update(min((*it1),r+1),s[x]-s[col[(*it)]]);
				}
				++it;
			}
			int lstcol=col[*(--S.upper_bound(r))];
			vector<int>g;
			while ((*it)<=r)
			{
				int now=(*it);
				g.push_back(now);
				auto it1=it;
				it++;
				// if (now==63)
				// cout<<"!"<<now<<" "<<min((*it),r+1)<<" "<<col[now]<<" "<<x<<" "<<query(now)<<" "<<s[col[now]]<<" "<<s[x]<<endl;
				if (col[now]!=x)
				{
					update(now,s[col[now]]-s[x]);
					update(min((*it),r+1),s[x]-s[col[now]]);
				}
			}
			for (auto u:g) S.erase(u);
			if (!S.count(l)) S.insert(l);
			col[l]=x;
			if (!S.count(r+1)) 
			{
				S.insert(r+1);
				col[r+1]=lstcol;
			}
		} else
		if (st=="Add")
		{
			int x,y;
			cin>>x>>y;
			s[x]+=y;
		} else
		{
			int x;
			cin>>x;
			int cl=col[(*(--S.upper_bound(x)))];
			// cout<<cl<<" "<<query(x)+s[cl]<<endl;
			cout<<query(x)+s[cl]<<endl;
		}
	}
			
}
signed main()
{
	IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/