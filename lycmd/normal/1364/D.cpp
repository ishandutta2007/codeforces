#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int n,m,k,x,y,d[N],flg[N];
vector<int>e[N],ans;
stack<int>s;
void dfs(int x,int fa,int de){
	d[x]=de,s.push(x);
	for(int y:e[x])
		if(!d[y])dfs(y,x,de+1);
		else if(y^fa&&d[x]>d[y]&&d[x]-d[y]+1<=k){
			cout<<"2\n"<<d[x]-d[y]+1<<"\n";
			for(int t=d[x]-d[y]+1;t--;)
				cout<<s.top()<<" ",s.pop();
			exit(0);
		}
	if(!flg[x]){
		ans.push_back(x);
		for(int y:e[x])flg[y]=1;
	}
	s.pop();
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>n>>m>>k;m--;)
		cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
	dfs(1,0,1);
	cout<<"1\n";
	for(int i=0;i<(k+1)/2;i++)
		cout<<ans[i]<<" ";
}