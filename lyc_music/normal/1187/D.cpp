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
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int tr[N],a[N],b[N],A[N],B[N];
int po[N];
int ans1;
int cnt; 
vector<int>c[N],d[N];
int T,n;
void update(int x,int y)
{
	while (x<=n)
	{
		tr[x]+=y;
		x+=(x&(-x));
	}
}
int query(int x)
{
	int res=0;
	while (x)
	{
		res+=tr[x];
		x-=(x&(-x));
	}
	return res;
}
void update1(int x,int y)
{
	while (x<=n)
	{
		tr[x]=min(tr[x],y);
		x+=(x&(-x));
	}
}
int query1(int x)
{
	int res=n+1;
	while (x)
	{
		res=min(res,tr[x]);
		x-=(x&(-x));
	}
	return res;
}
signed main()
{
	T=read();
	int T1=T;
	while (T--)
	{
		cnt++;
		int ans=1;
		n=read();
		for (int i=1;i<=n;i++) a[i]=read(),A[i]=a[i];
		for (int i=1;i<=n;i++) b[i]=read(),B[i]=b[i];
		bool bl=1;
		for (int i=1;i<=n;i++)
			if (a[i]!=b[i]) bl=0;
		sort(A+1,A+n+1);
		sort(B+1,B+n+1);
		for (int i=1;i<=n;i++) tr[i]=0,c[i].clear(),d[i].clear();
		for (int i=1;i<=n;i++)
			if (A[i]!=B[i])
			{
				ans=0;
				break;
			}
		if (!ans) 
		{
			puts("NO");
			continue;
		}
		for (int i=1;i<=n;i++)
			c[a[i]].push_back(i);
		for (int i=1;i<=n;i++) d[b[i]].push_back(i);
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<c[i].size();j++)
			{
				po[c[i][j]]=d[i][j];
			}
		}
		for (int i=1;i<=n;i++) tr[i]=n+1;
		for (int i=1;i<=n;i++)
			if (po[i]==0) assert(0);
		for (int i=n;i>=1;i--)
		{
			if (query1(n-a[i]+1)<po[i]) ans=0,ans1=i;
			update1(n-a[i]+1,po[i]);
		}
		if (!ans)
		{
			puts("NO");
			continue;
		}
		for (int i=1;i<=n;i++) tr[i]=0,c[i].clear(),d[i].clear();
		for (int i=n;i>=1;i--)
		{
			c[a[i]].push_back(query(a[i]));
			update(a[i],1);
		}
		for (int i=1;i<=n;i++) tr[i]=0;
		for (int i=n;i>=1;i--)
		{
			d[b[i]].push_back(query(b[i]));
			update(b[i],1);
		}
		
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<c[i].size();j++)
			{
				if (d[i][j]>c[i][j])
				{
					ans=0;
					break;
				}
			}	
		}
		
		for (int i=1;i<=n;i++) tr[i]=0,c[i].clear(),d[i].clear();
		for (int i=1;i<=n;i++)
		{
			c[a[i]].push_back(query(n)-query(a[i]-1));
			update(a[i],1);
		}
		for (int i=1;i<=n;i++) tr[i]=0;
		for (int i=1;i<=n;i++)
		{
			d[b[i]].push_back(query(n)-query(b[i]-1));
			update(b[i],1);
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<c[i].size();j++)
			{
				if (d[i][j]>c[i][j])
				{
					ans=0;
					break;
				}
			}	
		}
		if (!ans)
		{
			puts("NO");
			continue;
		} else
		{
			
			puts("YES");
		}
	}
}
/*
1
5
3 4 5 1 2
1 2 3 4 5

1
9
3 2 5 9 8 4 1 2 3
2 3 4 1 5 8 9 2 3

1
10
8 10 10 3 1 6 10 8 1 3 
8 1 1 3 10 8 6 10 3 10 
*/