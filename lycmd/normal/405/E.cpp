#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int n,m,d[N];
vector<int>e[N];
int dfs(int x,int fa){
	int p=0;
	for(int y:e[x]){
		if(y==fa||(d[y]?d[x]<=d[y]:(d[y]=d[x]+1,dfs(y,x))))
			continue;
		if(p)
			cout<<p<<" "<<x<<" "<<y<<"\n",p=0;
		else
			p=y;
	}
	return p?(cout<<p<<" "<<x<<" "<<fa<<"\n",1):0;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	if(m&1)
		cout<<"No solution\n",exit(0);
	while(m--){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	d[1]=1,dfs(1,0);
}