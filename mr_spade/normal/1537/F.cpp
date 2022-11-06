#include<bits/stdc++.h>
#define int long long
#define abs(x) ((x)<0?-(x):(x))
using namespace std;
const int N=1e6+5,NANC=0x3f3f3f3f3f3f3f3f;
int n,m;
int v[N],t[N],b[N];
void extend(int x,int y)
{
	if(y&&abs(y)<abs(x))
		swap(x,y);
	if(x<0)
		x*=-1,y*=-1;
	if(b[x]==NANC)
		return b[x]=y,void();
	if(y==0)
	{
		if(b[x]==0)
			return;
		else
			return extend(abs(b[x]),0);
	}
	else
	{
		if(b[x]==y)
			return;
		else if(b[x]==-y)
			return extend(abs(y),0);
		else if(b[x]==0)
			return b[x]=y,extend(y,0);
		else
			return extend(y,-b[x]);
	}
}
inline bool judge()
{
	register int i;
	for(i=1;i<=n;i++)
		if(t[i])
		{
			if(b[i]==NANC)
				return 0;
			else if(b[i]==0)
			{
				if(t[i]&1)
					return 0;
				t[i]=0;
			}
			else if(b[i]>0)
				t[b[i]]-=t[i],t[i]=0;
			else
				t[-b[i]]+=t[i],t[i]=0;
		}
	return 1;
}
inline void solve()
{
	int x,y;
	register int i;
	cin>>n>>m;
	memset(b+1,NANC,sizeof(int)*n);
	for(i=1;i<=n;i++)
		cin>>v[i];
	for(i=1;i<=n;i++)
		cin>>t[i],t[i]-=v[i];
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		extend(x,y);
	}
	puts(judge()?"YES":"NO");
	return;
}
signed main()
{
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}