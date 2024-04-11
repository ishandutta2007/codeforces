#include<bits/stdc++.h>
#define int long long
#define lll __int128
#define db double
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
namespace IO
{
	const int SZ=1<<20;
	char gchar()
	{
	    static char buf[SZ];
	    static int i=SZ;
	    if(i==SZ)i=0,fread(buf,1,SZ,stdin);
	    return buf[i++];
	}
	void pchar(char c)
	{
	    static char buf[SZ];
	    static int i=0;
	    if(c)buf[i++]=c;
	    if(!c||i==SZ)fwrite(buf,1,i,stdout),i=0;
	}
	void pstr(string s,char end='\n')
	{
		for(char c:s)pchar(c);
		pchar(end);
	}
	template<typename T>void read(T &x)
	{
	    x=0;int f=1;
	    static char c;
	    while((c=gchar())>'9'||c<'0')if(c=='-')f=-1;
	    x=c-'0';
	    while((c=gchar())>='0'&&c<='9')
			x=(x<<1)+(x<<3)+(c^48);
		x*=f;
	}
	template<typename T>void i_write(T x)
	{
	    if(x>9)i_write(x/10);
	    pchar(x%10+'0');
	}
	template<typename T>void write(T x,char end='\n')
	{
	    if(x<0)pchar('-'),x=-x;
	    if(x>9)i_write(x/10);
	    pchar(x%10+'0');
	    pchar(end);
	}
}
using IO::read;
using IO::write;
const int N=1e6+10;
int n,v,t[N],a[N],p[N];
int w[N],b[N];
int f[N];
struct BIT
{
	int c[N];
	void add(int x,int y){for(;x<N;x+=x&(-x))c[x]=max(c[x],y);}
	int ask(int x)
	{
		int res=-1e9;
		for(;x;x-=x&(-x))res=max(res,c[x]);
		return res;
	}
	void clr(int x){for(;x<N;x+=x&(-x))c[x]=-1e9;}
}tr;
void solve(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	solve(l,mid);
	for(int i=l;i<=r;i++)p[i]=i,w[i]=a[i]-v*t[i],b[i-l+1]=w[i];
	sort(b+1,b+r-l+2);int m=unique(b+1,b+r-l+2)-b-1;
	for(int i=l;i<=r;i++)w[i]=lower_bound(b+1,b+m+1,w[i])-b;
	sort(p+l,p+mid+1,[&](int i,int j){return a[i]<a[j];});
	sort(p+mid+1,p+r+1,[&](int i,int j){return a[i]<a[j];});
	int j=l;
	for(int i=mid+1;i<=r;i++)
	{
		while(j<=mid&&a[p[i]]>=a[p[j]])
		{
			if(f[p[j]]!=-1)tr.add(m+1-w[p[j]],f[p[j]]);
			j++;
		}
		f[p[i]]=max(f[p[i]],tr.ask(m+1-w[p[i]])+1);
	}
	for(int k=l;k<j;k++)tr.clr(m+1-w[p[k]]);
	
	for(int i=l;i<=r;i++)p[i]=i,w[i]=a[i]+v*t[i],b[i-l+1]=w[i];
	sort(b+1,b+r-l+2),m=unique(b+1,b+r-l+2)-b-1;
	for(int i=l;i<=r;i++)w[i]=lower_bound(b+1,b+m+1,w[i])-b;
	sort(p+l,p+mid+1,[&](int i,int j){return a[i]>a[j];});
	sort(p+mid+1,p+r+1,[&](int i,int j){return a[i]>a[j];});
	j=l;
	for(int i=mid+1;i<=r;i++)
	{
		while(j<=mid&&a[p[i]]<=a[p[j]])
		{
			if(f[p[j]]!=-1)tr.add(w[p[j]],f[p[j]]);
			j++;
		}
		f[p[i]]=max(f[p[i]],tr.ask(w[p[i]])+1);
	}
	for(int k=l;k<j;k++)tr.clr(w[p[k]]);
	solve(mid+1,r);
}
signed main()
{
	read(n),read(v);
	for(int i=1;i<=n;i++)read(t[i]);
	for(int i=1;i<=n;i++)read(a[i]);
	memset(f,-1,sizeof(f)),memset(tr.c,~0x3f,sizeof(tr.c));
	t[0]=0,a[0]=0,f[0]=1;
	solve(0,n);
	int ans=1;
	for(int i=1;i<=n;i++)ans=max(ans,f[i]);
	write(ans-1);
	IO::pchar(0);
	return 0;
}