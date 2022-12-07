#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<utility>
#include<vector>
using namespace std;
set<pair<int,int> > S;
pair<int,int> P[200010];
int n,w[200010],x[200010],y[200010];
vector<pair<int,int> > v;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]),S.insert(make_pair(x[i],y[i]));
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=-100000;i<=100000;i++) P[i+100000]=make_pair(-1,-1);
	P[100000]=make_pair(0,0);
	for(int i=1;i<=n;i++)
	{
		pair<int,int> tmp=P[w[i]+100000];
		if(tmp==make_pair(-1,-1)) break;
		v.push_back(tmp);
		P[w[i]+100000]=make_pair(-1,-1);
		tmp.first++;
		if(S.count(tmp)) P[tmp.second-tmp.first+100000]=tmp,S.erase(tmp);
		tmp.first--,tmp.second++;
		if(S.count(tmp)) P[tmp.second-tmp.first+100000]=tmp,S.erase(tmp);
	}
	if((int)v.size()!=n) puts("NO");
	else
	{
		puts("YES");
		for(int i=0;i<n;i++)
			printf("%d %d\n",v[i].first,v[i].second);
	}
	return 0;
}