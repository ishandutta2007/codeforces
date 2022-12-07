#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<utility>
#include<cstdlib>
using namespace std;
const int MAXN=2010;
int n,P[MAXN],Q[MAXN],pos[MAXN],ans;
vector<pair<int,int> > v;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&Q[i]);
	for(int i=1;i<=n;i++) scanf("%d",&P[i]);
	for(int k=1;k<=n;k++)
	{
		int sub1=0,sub2=0;
		for(int i=1;i<=n;i++)
			if(P[i]==k) sub1=i;
		for(int i=1;i<=n;i++)
			if(Q[i]==k) sub2=i;
		ans+=abs(sub1-sub2);
	}
	printf("%d\n",ans>>1);
	for(int i=1;i<=n;i++) pos[P[i]]=i;
	for(int i=1;i<=n;i++) Q[i]=pos[Q[i]];
	for(int k=n;k>=1;k--)
	{
		int sub=0,now;
		for(int i=1;i<=n;i++)
			if(Q[i]==k) sub=i;
		now=sub;
		for(int i=sub+1;i<=k;i++)
			if(Q[i]<=now) swap(Q[i],Q[now]),v.push_back(make_pair(i,now)),now=i;
	}
	printf("%d\n",(int)v.size());
	for(int i=0;i<v.size();i++) printf("%d %d\n",v[i].first,v[i].second);
	return 0;
}