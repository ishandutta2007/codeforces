#include<bits/stdc++.h>
using namespace std;
int const N=500010;
int n,m,x[N],y[N],vis[N];
queue<int>q;
map<int,map<int,int> >a,b;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i];
		if(x[i]==1||y[i]==n){
			if(x[i]==y[i])
				cout<<"-1\n",exit(0);
			q.push(i),vis[i]=1;
		}
		a[x[i]][y[i]]=b[y[i]][-x[i]]=i;
	}
	while(!q.empty()){
		int u=q.front(),tx=x[u]+1,ty=y[u]-1;q.pop();
		if(tx>n||ty<1)
			cout<<"-1\n",exit(0);
		if(a.count(tx)){
			auto i=a[tx].lower_bound(ty);
			if(i!=a[tx].end()){
				int t=i->second;
				if(!vis[t])
					vis[t]=1,q.push(t);
			}
		}
		if(b.count(ty)){
			auto i=b[ty].lower_bound(-tx);
			if(i!=b[ty].end()){
				int t=i->second;
				if(!vis[t])
					vis[t]=1,q.push(t);
			}
		}
	}
	cout<<2*n-2<<"\n";
}