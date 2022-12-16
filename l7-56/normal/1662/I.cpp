#include<bits/stdc++.h>
#define ll long long
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
const int N=2e5+10,S=2e9;
int n,m,p[N],x[N],mn[N];
ll ans;
int il[N],ir[N];
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)read(p[i]);
	for(int i=1;i<=m;i++)read(x[i]);
	sort(x+1,x+m+1);
	for(int i=1;i<=m;i++)
	{
		int pos=(x[i]+99)/100+1;
		if(pos<=n)il[pos]=i;
		else il[n+1]=i;
	}
	for(int i=m;i;i--)
	{
		int pos=x[i]/100+1;
		if(pos<=n)ir[pos]=i;
		else ir[n+1]=i;
	}
	for(int i=1;i<=n;i++)
		if(!il[i])il[i]=il[i-1];
	for(int i=n;i;i--)
		if(!ir[i])ir[i]=ir[i+1];
	map<int,ll>mp;
	for(int i=1;i<=n;i++)
	{
		mn[i]=2e9;int pos=(i-1)*100;
		if(il[i])mn[i]=min(mn[i],pos-x[il[i]]);
		if(ir[i])mn[i]=min(mn[i],x[ir[i]]-pos);
		int l=max(0,2*(pos-mn[i])+1),r=min(S,2*(pos+mn[i])-1);
		mp[l]+=p[i],mp[r+1]-=p[i];
	}
	ll now=0;
	for(auto it:mp)now+=it.second,ans=max(ans,now);
	write(ans);
	IO::pchar(0);
	return 0;
}