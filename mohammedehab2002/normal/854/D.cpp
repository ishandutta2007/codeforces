#include <iostream>
#include <vector>
using namespace std;
long long mn[1000005][2],l[1000005];
vector<pair<int,int> > v[1000005][2];
int fidx,lidx,fcnt,lcnt;
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	while (m--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if (b)
		v[a][0].push_back(make_pair(b,d));
		else
		v[a][1].push_back(make_pair(c,d));
	}
	for (int i=1;i<=n;i++)
	l[i]=(1<<30),mn[0][0]+=(1<<30);
	for (int i=1;i<1000005;i++)
	{
		mn[i][0]=mn[i-1][0];
		for (int x=0;x<v[i][0].size();x++)
		{
			if (v[i][0][x].second<l[v[i][0][x].first])
			{
				if (l[v[i][0][x].first]==(1<<30))
				fcnt++;
				mn[i][0]-=(l[v[i][0][x].first]-v[i][0][x].second);
				l[v[i][0][x].first]=v[i][0][x].second;
				if (fcnt==n && !fidx)
				fidx=i;
			}
		}
	}
	for (int i=1;i<=n;i++)
	l[i]=(1<<30),mn[1000004][1]+=(1<<30);
	for (int i=1000003;i>0;i--)
	{
		mn[i][1]=mn[i+1][1];
		for (int x=0;x<v[i][1].size();x++)
		{
			if (v[i][1][x].second<l[v[i][1][x].first])
			{
				if (l[v[i][1][x].first]==(1<<30))
				lcnt++;
				mn[i][1]-=(l[v[i][1][x].first]-v[i][1][x].second);
				l[v[i][1][x].first]=v[i][1][x].second;
				if (lcnt==n && !lidx)
				lidx=i;
			}
		}
	}
	long long ans=(1LL<<60);
	for (int i=fidx;i+k+1<=lidx;i++)
	ans=min(ans,mn[i][0]+mn[i+k+1][1]);
	if (ans==(1LL<<60) || !fidx || !lidx)
	ans=-1;
	printf("%I64d",ans);
}