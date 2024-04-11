#include<bits/stdc++.h>
using namespace std;
int const N=1000010;
int n,cnt;
vector<int>e[N];
void dfs(int x,int fa,int col){
	cnt+=col;
	for(int y:e[x]){
		if(y==fa)continue;
		dfs(y,x,!col);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0,0);
	cout<<min(cnt,n-cnt)-1<<"\n";
}