#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int t,n,m,cur,in[N],deg[N],h[N];
vector<int>e[N],g[N];
queue<int>q;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		memset(in,0,sizeof in);
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			e[i].clear(),g[i].clear();
		while(m--){
			int op,x,y;
			cin>>op>>x>>y;
			if(op)e[x].push_back(y),in[y]++;
			else g[x].push_back(y);
		}
		for(int i=1;i<=n;i++)
			if(!in[i])
				q.push(i);
		while(!q.empty()){
			int x=q.front();q.pop();
			h[x]=++cur;
			for(int y:e[x])
				if(!--in[y])
					q.push(y);
		}
		int flg=1;
		for(int i=1;i<=n;i++)
			flg&=!in[i];
		if(!flg){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		for(int i=1;i<=n;i++){
			for(int j:e[i])
				cout<<i<<" "<<j<<"\n";
			for(int j:g[i]){
				if(h[i]<h[j])
					cout<<i<<" "<<j<<"\n";
				else
					cout<<j<<" "<<i<<"\n";
			}
		}
	}
}