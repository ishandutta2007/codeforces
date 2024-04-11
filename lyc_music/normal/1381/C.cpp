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
#define N 500005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,x,y,b[N],a[N],cnt[N];
int T,Ans[N];
struct node
{
	int val,id,tp;
}ans[N],c[N];
priority_queue<pa>q;
bool cmp(node x,node y)
{
	return (x.tp)^(y.tp)?x.tp<y.tp:x.val<y.val;
}
void solve()
{
	while (!q.empty()) q.pop();
	n=read(),x=read(),y=read();
	int now=0;
	for (int i=1;i<=n;i++) a[i]=read(),b[a[i]]++;
	for (int i=1;i<=n+1;i++)
		if (!b[i]) now=i;
		else q.push({b[i],i});
	for (int i=1;i<=x;i++)
	{
		pa u=q.top();
		q.pop();
		cnt[u.se]++;
		u.fi--;
		q.push(u);
	}
	for (int i=1;i<=n;i++)
	{
		c[i]={a[i],i,0};
		if (cnt[a[i]])
		{
			c[i].tp=1;
			cnt[a[i]]--;
		}
	}
	sort(c+1,c+n+1,cmp);
	for (int i=1;i<=n;i++) ans[i]=c[i];
	for (int i=1;i<=n-x;i++)
		ans[i].val=(c[(i+q.top().fi-1)%(n-x)+1].val);
	int lst=n-y;
	for (int i=1;i<=n-x;i++)
		if (ans[i].val==c[i].val)
		{
			lst--;
			ans[i].val=now;
		}
	for (int i=1;i<=n-x;i++)
		if (ans[i].val!=now&&(lst>0))
		{
			lst--;
			ans[i].val=now;
		}
	if (lst<0) puts("NO");
	else
	{
		puts("YES");
		for (int i=1;i<=n;i++)
			Ans[ans[i].id]=ans[i].val;
		for (int i=1;i<=n;i++)	
			writesp(Ans[i]);
		puts("");
	}
	for (int i=1;i<=n+1;i++) cnt[i]=b[i]=a[i]=0;
}
		
signed main()
{
	T=read();
	while (T--)
	{
		solve();
	}
}
/*

*/