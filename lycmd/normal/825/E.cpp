#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,m,cur,in[N],ans[N];
vector<int>e[N];
priority_queue<int>q;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	while(m--){
		int x,y;cin>>x>>y;
		e[y].push_back(x),in[x]++;
	}
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	cur=n;
	while(!q.empty()){
		int x=q.top();q.pop();
		ans[x]=cur--;
		for(int y:e[x])
			if(!--in[y])
				q.push(y);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
}