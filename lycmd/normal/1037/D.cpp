#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,cnt,a[N],vis[N];
vector<int>e[N];
queue<int>q;
set<int>s;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(a[1]!=1)cout<<"No\n",exit(0);
	q.push(cnt=1);
	while(!q.empty()){
		int x=q.front();q.pop();
		vis[x]=1;
		for(int y:e[x])
			if(!vis[y])s.insert(y);
		while(s.size())
			if(s.count(a[++cnt]))
				s.erase(a[cnt]),q.push(a[cnt]);
			else cout<<"No\n",exit(0);
	}
	cout<<"Yes\n";
	return 0;
}