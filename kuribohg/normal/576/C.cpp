#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=1000010;
vector<int> v[1010];
struct Point
{
	int x,y,id;
}P[MAXN];
bool cmp(const Point &p,const Point &q)
{
	if(p.x/1000!=q.x/1000) return p.x/1000<q.x/1000;
	if(p.y!=q.y) return p.y<q.y;
	return false;
}
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&P[i].x,&P[i].y),P[i].id=i;
	sort(P+1,P+n+1,cmp);
	for(int i=1;i<=n;i++) v[P[i].x/1000].push_back(P[i].id);
	for(int i=0;i<=1000;i++)
	{
		if(i&1) reverse(v[i].begin(),v[i].end());
		for(int j=0;j<v[i].size();j++)
			printf("%d ",v[i][j]);
	}
	return 0;
}