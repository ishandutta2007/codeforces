#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 110000;
const int maxa = 1e7+10;

int n,m;
struct edge
{
	int y,nex;
	edge(){}
	edge(const int _y,const int _nex){y=_y;nex=_nex;}
}a[maxn]; int len,fir[maxn];
inline void ins(const int x,const int y){a[++len]=edge(y,fir[x]);fir[x]=len;}

int v[maxn],s[maxa];
int c,num[2],fid[maxn];

void dfs(const int x)
{
	if(!fir[x]) fid[x]=1;
	for(int k=fir[x];k;k=a[k].nex)
	{
		const int y=a[k].y;
		dfs(y); fid[x]=!fid[y];
	}
	if(fid[x]) c^=v[x];
	else s[v[x]]++;
	num[fid[x]]++;
}
ll count(const ll x){return x*(x-1)/2;}

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	for(int i=2;i<=n;i++)
	{
		int x;scanf("%d",&x);
		ins(x,i);
	}
	
	c=0; dfs(1);
	ll ans=0;
	if(c)
	{
		for(int i=1;i<=n;i++) if(fid[i])
			if((c^v[i])<maxa) ans+=(ll)s[c^v[i]];
		printf("%I64d\n",ans);
	}
	else
	{
		ans+=count(num[0])+count(num[1]);
		for(int i=1;i<=n;i++) if(fid[i])
			ans+=(ll)s[v[i]];
		printf("%I64d\n",ans);
	}
	
	return 0;
}