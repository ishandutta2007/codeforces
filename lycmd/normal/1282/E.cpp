#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int t,n,deg[N],vis[N];
vector<int>e1[N],e2[N];
map<pair<int,int>,int>cnt;
queue<int>q;
void ins(int i,int j,int x){
	if(i>j)swap(i,j);
	int&y=cnt[{i,j}];
	if(y){
		e1[x].push_back(y);
		e1[y].push_back(x);
		deg[x]++,deg[y]++,y=0;
	}else y=x;
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n,cnt.clear();
		for(int i=1;i<=n;i++)
			e1[i].clear(),e2[i].clear(),deg[i]=vis[i]=0;
		for(int i=1;i<n-1;i++){
			int a,b,c;cin>>a>>b>>c;
			ins(a,b,i),ins(a,c,i),ins(b,c,i);
		}
		for(auto i:cnt)
			if(i.second){
				int x=i.first.first,y=i.first.second;
				e2[x].push_back(y);
				e2[y].push_back(x);
			}
		cout<<1;
		for(int x=1,y=e2[x][0],t;y^1;t=y,y=e2[y][x!=e2[y][1]],x=t)
			cout<<" "<<y;
		cout<<"\n";
		for(int i=1;i<n-1;i++)
			if(deg[i]<2)
				q.push(i),vis[i]=1;
		while(!q.empty()){
			int x=q.front();q.pop();
			cout<<x<<" ";
			for(int y:e1[x])
				if(!vis[y]&&--deg[y]<2)
					q.push(y),vis[y]=1;
		}
		cout<<"\n";
	}
}