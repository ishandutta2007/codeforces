#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#define pb push_back
#define mp make_pair
using namespace std;
int n;
struct node { int x,y,z; }a[110000];
map<pair<int,int>,vector<int> > dic1;
map<int,vector<int> > dic2;
vector<int> dic3;
bool cmp1(int x,int y)
{
	return a[x].z<a[y].z;
}
bool cmp2(int x,int y)
{
	return a[x].y<a[y].y;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	for(int i=1;i<=n;i++)dic1[mp(a[i].x,a[i].y)].pb(i);
	for(auto p:dic1)
	{
		auto q=p.second;
		sort(q.begin(),q.end(),cmp1);
		int cnt=q.size();
		for(int i=0;i<q.size()-1;i+=2)printf("%d %d\n",q[i],q[i+1]);
		if (cnt&1)dic2[a[q[cnt-1]].x].pb(q[cnt-1]);
	}
	for(auto p:dic2)
	{
		auto q=p.second;
		sort(q.begin(),q.end(),cmp2);
		int cnt=q.size();
		for(int i=0;i<q.size()-1;i+=2)printf("%d %d\n",q[i],q[i+1]);
		if (cnt&1)dic3.pb(q[cnt-1]);
	}
	int cnt=dic3.size();
	for(int i=0;i<cnt-1;i+=2)printf("%d %d\n",dic3[i],dic3[i+1]);
}