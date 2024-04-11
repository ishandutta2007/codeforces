#include<bits/stdc++.h>
using namespace std;
vector<int>e[1005];int n,deg[1005],s[2005],h=1,t=0;
int main()
{
	ios::sync_with_stdio(false);cin>>n;
	for(int i=1,x,y;i<n;i++) cin>>x>>y,e[x].push_back(y),e[y].push_back(x),deg[x]++,deg[y]++;
	for(int i=1;i<=n;i++) if(deg[i]==1) s[++t]=i;
	while(h+1<=t)
	{
		int x=s[h++],y=s[h++],r;
		cout<<"? "<<x<<" "<<y<<endl,cin>>r;
		if(r==x||r==y) return cout<<"! "<<r<<endl,0;
		for(int i=0;i<(int)e[x].size();i++) {deg[e[x][i]]--;if(deg[e[x][i]]==1) s[++t]=e[x][i];}
		for(int i=0;i<(int)e[y].size();i++) {deg[e[y][i]]--;if(deg[e[y][i]]==1) s[++t]=e[y][i];}
	}
	return cout<<"! "<<s[h]<<endl,0;
}