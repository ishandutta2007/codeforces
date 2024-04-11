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
#define inf 1e9
using namespace std;

inline void read(int &x)
{
	char c; while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
const int maxn = 2100;

int n,mark[maxn];
int d[maxn][maxn],mind;

ll f[maxn][2];
struct node
{
	ll x; int i,j;
	friend inline bool operator <(const node x,const node y){return x.x>y.x;}
}; priority_queue<node>q;

int main()
{
	read(n); mind=inf;
	for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) 
	{
		read(d[i][j]); d[j][i]=d[i][j];
		mind=min(mind,d[i][j]);
	}
	for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++)
	{
		d[i][j]-=mind,d[j][i]-=mind;
		if(!d[i][j]) mark[i]=mark[j]=1;
	}
	
	memset(f,-1,sizeof f);
	for(int i=1;i<=n;i++)
	{
		if(mark[i]) f[i][0]=0,q.push((node){0,i,0});
	}
	while(!q.empty())
	{
		const node now=q.top(); q.pop();
		int i=now.i,j=now.j;
		if(now.x!=f[i][j]) continue;
		for(int y=1;y<=n;y++) if(y!=i)
		{
			if(!j)
			{
				if(f[y][0]>now.x+d[i][y]||f[y][0]==-1) f[y][0]=now.x+d[i][y],q.push((node){f[y][0],y,0});
				if(f[y][1]>now.x||f[y][1]==-1) f[y][1]=now.x,q.push((node){f[y][1],y,1});
			}
			else
			{
				if(f[y][0]>now.x+2ll*d[i][y]||f[y][0]==-1)
					f[y][0]=now.x+2ll*d[i][y],q.push((node){f[y][0],y,0});
			}
		}
	}
	for(int i=1;i<=n;i++) printf("%lld\n",f[i][0]+(ll)mind*(n-1));
	
	return 0;
}