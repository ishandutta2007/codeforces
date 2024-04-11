#include <bits/stdc++.h>
using namespace std;
vector<int> vec[100005];
int a[100005],b[100005],ans[100005],visited[100005];
int u,v,c;
void DFS(int node,int lvl){
	visited[node]=1;
	int temp;
	if(lvl%2==1)temp=u;
	else temp=v;
	bool flag=false;
	if((a[node]^temp)!=b[node]){
		flag=true;
		a[node]=b[node];
		ans[c++]=node;
		if(lvl%2==1)u^=1;
		else v^=1;
	}
	for(int i=0;i<vec[node].size();i++){
		int breh=vec[node][i];
		if(visited[breh]==false){
			DFS(breh,lvl+1);
		}
	}
	if(flag==true){
		if(lvl%2==1)u^=1;
		else v^=1;
	}
}
int main(){
	int N;
	cin>>N;
	memset(visited,0,sizeof(visited));
	for(int i=1;i<=N;i++)vec[i].clear();
	for(int i=1;i<=N-1;i++){
		int x,y;
		cin>>x>>y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for(int i=1;i<=N;i++)cin>>a[i];
	for(int i=1;i<=N;i++)cin>>b[i];
	c=0;u=0;v=0;
	DFS(1,1);
	cout<<c<<"\n";
	for(int i=0;i<c;i++)cout<<ans[i]<<"\n";
	return 0;
}