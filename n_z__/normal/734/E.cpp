#include<bits/stdc++.h>
using namespace std;
struct point{
	int c,f;
	vector<int>a;
}q[200001];
int far;
void dfs(int x,int p){
	if(p==0)q[x].f=1;else q[x].f=q[p].f+(q[x].c^q[p].c);
	if(q[x].f>q[far].f)far=x;
	for(auto y:q[x].a)if(y!=p)dfs(y,x);
}
int main()
{
	int n;
	cin>>n;
	for(int x=1;x<=n;x++)
	cin>>q[x].c;
	for(int x=1,u,v;x<n;x++)cin>>u>>v,q[u].a.push_back(v),q[v].a.push_back(u);
	dfs(1,0),dfs(far,0);
	cout<<q[far].f/2;
}