# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

#define mp make_pair
#define f first
#define s second

vector<pair<int,int> >v[2];
int main()
{
	int n,i,j,k,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&t,&k),
		v[t].push_back(mp(k,i));
	sort(v[0].begin(),v[0].end());
	sort(v[1].begin(),v[1].end());
	for(i=j=0;i<v[0].size()&&j<v[1].size();)
	{
		k=min(v[0][i].f,v[1][j].f);
		printf("%d %d %d\n",v[0][i].s,v[1][j].s,k);
		v[0][i].f-=k,v[1][j].f-=k;
		
		if(v[0][i].f)j++; else
		if(v[1][j].f)i++; else
		(i+1<v[0].size())?i++:j++;
	}
	return 0;
}