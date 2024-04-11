#include<bits/stdc++.h>
using namespace std;
int ti[200010];
struct node
{
	int x,y,id;
}p[200010];
bool cmpx(node a,node b){return a.x!=b.x?a.x<b.x:a.y<b.y;}
bool cmpy(node a,node b){return a.y!=b.y?a.y<b.y:a.x<b.x;}
int fa[200010];
int find(int x)
{
	if(x!=fa[x])return fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
    int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y>>ti[i],p[i].id=fa[i]=i;
		sort(p+1,p+n+1,cmpx);
		for(int i=1;i<n;i++)
			if(p[i].x==p[i+1].x&&abs(p[i].y-p[i+1].y)<=k)
			{
				int fx=find(p[i].id),fy=find(p[i+1].id);
				fa[fx]=fy,ti[fy]=min(ti[fy],ti[fx]);
			}
		sort(p+1,p+n+1,cmpy);
		for(int i=1;i<n;i++)
			if(p[i].y==p[i+1].y&&abs(p[i].x-p[i+1].x)<=k)
			{
				int fx=find(p[i].id),fy=find(p[i+1].id);
				fa[fx]=fy,ti[fy]=min(ti[fy],ti[fx]);
			}
		priority_queue<int>q;
		for(int i=1;i<=n;i++)
			if(fa[i]==i)q.push(ti[i]);
		int ans=0;
		while(!q.empty())
		{
			q.pop();
			if(q.empty()||q.top()<=ans)break;
			ans++;
		}
		cout<<ans<<endl;
	}
}