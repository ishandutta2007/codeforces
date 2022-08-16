#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<list>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>
#include<unordered_set>
#include<unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=100010;
const int MaxT=300;

int n,m;
int a[MaxN];
ll b[MaxN<<2];
int t[MaxN],l[MaxN],r[MaxN],d[MaxN];
int F[MaxN],pa[MaxN];

void add(int k,int L,int R,int x,int y,int d)
{
	if (L==x&&R==y)
	{
		b[k]+=d;
		return;
	}
	b[k]+=(ll)(y-x+1)*d;
	int m=(L+R)>>1;
	if (y<=m)
		add(k<<1,L,m,x,y,d);
	else if (x>m)
		add(k<<1|1,m+1,R,x,y,d);
	else
	{
		add(k<<1,L,m,x,m,d);
		add(k<<1|1,m+1,R,m+1,y,d);
	}
}

ll get(int k,int L,int R,int x,int y)
{
	if (L==x&&R==y) return b[k];
	int m=(L+R)>>1;
	if (y<=m)
		return get(k<<1,L,m,x,y);
	else if (x>m)
		return get(k<<1|1,m+1,R,x,y);
	else
		return get(k<<1,L,m,x,m)+get(k<<1|1,m+1,R,m+1,y);
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		a[i]=i;
	}
	for (int i=1;i<=m;++i)
	{
		scanf("%d",&t[i]);
		if (t[i]==1)
			scanf("%d%d%d",&l[i],&r[i],&d[i]);
		else
			scanf("%d%d",&l[i],&r[i]);
	}
	vector<int> event;
	for (int i=1;i<=m;i+=MaxT)
		event.push_back(i);
	event.push_back(m+1);
	for (int k=0;k<event.size()-1;++k)
	{
		vector<int> p;
		p.push_back(1);
		p.push_back(n+1);
		for (int i=event[k];i<event[k+1];++i)
		{
			p.push_back(l[i]);
			p.push_back(r[i]+1);
		}
		sort(p.begin(),p.end());
		p.erase(unique(p.begin(),p.end()),p.end());
		int m=p.size();
		for (int i=0;i<m;++i)
			F[p[i]]=i;
		for (int i=0;i<m-1;++i)
			pa[i]=-1;
		for (int i=event[k];i<event[k+1];++i)
		{
			int x=F[l[i]],y=F[r[i]+1];
			if (t[i]==1)
			{
				for (int j=x;j<y;++j)
				{
					if (pa[j]==-1)
					{
						for (int u=p[j];u<p[j+1];++u)
						{
							add(1,1,n,u,u,abs(a[u]-d[i]));
							//printf("%d %d %d\n",u,u,abs(a[u]-d[i]));
							a[u]=d[i];
						}
					}
					else
					{
						add(1,1,n,p[j],p[j+1]-1,abs(pa[j]-d[i]));
						//printf("%d %d %d\n",p[j],p[j+1]-1,abs(pa[j]-d[i]));
					}
					pa[j]=d[i];
				}
			}
			else
			{
				printf("%I64d\n",get(1,1,n,l[i],r[i]));
			}
		}
		for (int i=0;i<m-1;++i)
		{
			if (pa[i]==-1) continue;
			for (int j=p[i];j<p[i+1];++j)
				a[j]=pa[i];
		}
	}
	return 0;
}