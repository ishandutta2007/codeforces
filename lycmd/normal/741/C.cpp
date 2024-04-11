#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,c[N];
pair<int,int>p[N];
vector<int>e[N];
void dfs(int x,int col){
	c[x]=col;
	for(int y:e[x])
		if(!c[y])dfs(y,col^3);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
		p[i]={x,y};
	}
	for(int i=1;i<=2*n;i+=2)
		e[i].push_back(i+1),
		e[i+1].push_back(i);
	for(int i=1;i<=2*n;i++)
		if(!c[i])dfs(i,1);
	for(int i=1;i<=n;i++)
		cout<<c[p[i].first]<<" "<<c[p[i].second]<<"\n";
}