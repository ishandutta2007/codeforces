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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
mt19937 rnd(time(0));
int T,mx,x,y,nowmx,b[105][105],a[N],n,vis[N];
map<pa,int>Mp;
void print()
{
	cout<<"! ";
	for (int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;
}
void check(int val,int xx,int yy)
{
	for (int i=2;i*i<=val;i++)
		if (val%i==0)
		{
			while (val%i==0) val/=i;
			if (i>nowmx)
			{
				nowmx=max(nowmx,i);
				x=xx,y=yy;
			}
		}
	if (val!=1)
	{
		int i=val;
			if (i>nowmx)
			{
				nowmx=max(nowmx,i);
				x=xx,y=yy;
			}
	}
}
int checkmx(int val)
{
	vector<int>g;
	for (int i=2;i*i<=val;i++)
		if (val%i==0)
		{
			while (val%i==0) val/=i;
			g.push_back(i);
		}
	if (val!=1) return val;
	return (*(--g.end()));
}
	
int query(int x,int y)
{
	if (Mp.count({min(x,y),max(x,y)})) 
		return Mp[{min(x,y),max(x,y)}];
	int k;
	cout<<"? "<<x<<" "<<y<<endl;
	cin>>k;
	Mp[{min(x,y),max(x,y)}]=k;
	return k;
}
signed main()
{
	cin>>T;
	while (T--)
	{
		mx=0;x=0,y=0;nowmx=0;
		cin>>n;
		if (n<=100)
		{
			for (int i=1;i<=n;i++)
				for (int j=i+1;j<=n;j++)
				{
					b[i][j]=query(i,j);
					if (b[i][j]>mx)
					{
						x=i,y=j;
						mx=b[i][j];
					}
				}
			int now=sqrt(mx)+1,nowx=mx;
//			cout<<mx<<" "<<now<<endl;
			for (int i=1;i<=n;i++)
				if (x!=i)
				{
					if (b[min(x,i)][max(x,i)]==(now-1)*(now-2))
					{
						swap(x,y);break;
					}
				}
//			cout<<"!!"<<x<<" "<<y<<endl;
			for (int nmsl=1;nmsl<n;nmsl++)
			{
				a[x]=now;
				vis[x]=vis[y]=1;
				for (int i=1;i<=n;i++)
					if (y!=i)
					{
//						cout<<y<<" "<<i<<" "<<b[min(y,i)][max(y,i)]<<endl;
						if (vis[i]) continue;
						if (b[min(y,i)][max(y,i)]==(now-1)*(now-2))
						{
							x=y,y=i;
							break;
						}
					}
				now--;
//				cout<<"111 "<<x<<" "<<y<<" "<<now<<endl;
			}
			a[y]=now;
			print();
		} else
		{
			int tot=min(4999ll,n/2);
			for (int i=1;i<=tot;i++)
			{
				int u=rnd()%n,v=rnd()%n;
				u++,v++;
				while (u==v) u=rnd()%n,v=rnd()%n,u++,v++;
				check(query(u,v),u,v);
			}
			int p=rand()%n+1;
			while (p==x||p==y) p=rnd()%n+1;
			if (checkmx(query(p,x))==nowmx) a[x]=nowmx,a[y]=query(x,y)/nowmx;
			else a[x]=query(x,y)/nowmx,a[y]=nowmx,swap(x,y);
			for (int i=1;i<=n;i++)
				if (x!=i)
					a[i]=query(x,i)/a[x];
			print();
		}
		for (int i=1;i<=n;i++) vis[i]=0;
		Mp.clear();
	}
	
				
				
}
/*
1
3
61

2
3
*/