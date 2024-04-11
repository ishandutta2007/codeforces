//mjy.. good luck ..
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000007
typedef long long ll;
using namespace std;

void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 100010
int v[maxn],c[maxn],l[maxn],r[maxn];
int n,m;
map<pair<int,int>,int>	S;
ll f[maxn];
bool vis[maxn];
int from[maxn];
int cnt,ans[maxn];

int main()
{
	read(n);
	for (int i=1;i<=n;i++)	read(v[i]),read(c[i]),read(l[i]),read(r[i]);
	for (int i=1;i<=n;i++)
	{
		if (l[i]==0)
		{
			f[i]=v[i];
			from[i]=0;
			int x=c[i],y=r[i];
			int q=S[mp(x,y)];
			if (q==0||f[q]<f[i])	S[mp(x,y)]=i;
			vis[i]=true;
		}	else
		{
			int x=l[i],y=r[i]+c[i];
			int q=S[mp(x,y)];
			if (q==0)	continue;
			from[i]=q;
			f[i]=f[q]+v[i];
			x=l[i]+c[i],y=r[i];
			q=S[mp(x,y)];
			if (q==0||f[q]<f[i])	S[mp(x,y)]=i;
			vis[i]=true;
		}
	}
	ll mjy=0,pos=0;
	for (int i=1;i<=n;i++)
	if (r[i]==0 && vis[i])
	if (mjy<f[i])	mjy=f[i],pos=i;
	while (pos)
	{
		ans[++cnt]=pos;
		pos=from[pos];
	}
	printf("%d\n",cnt);
	for (int i=cnt;i>=1;i--)	printf("%d ",ans[i]);
	printf("\n");
	return 0;
}