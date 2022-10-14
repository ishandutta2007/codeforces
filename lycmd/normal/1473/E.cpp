#include<bits/stdc++.h>
#define int long long
#define ord(x,i,j) ((x)+((i)<<1|(j))*n)
using namespace std;
typedef pair<int,int> node;
int const N=2333333;
int n,m,d[N],vis[N];
vector<node>e[N];
priority_queue<node,vector<node>,greater<node> >q;
void add(int x,int y,int w){
	e[x].push_back({y,w});
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	while(m--){
		int a,b,c;cin>>a>>b>>c;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				add(ord(a,i,j),ord(b,i,j),c),
				add(ord(b,i,j),ord(a,i,j),c);
		for(int i=0;i<2;i++)
			add(ord(a,i,0),ord(b,i,1),c*2),
			add(ord(a,0,i),ord(b,1,i),0),
			add(ord(b,i,0),ord(a,i,1),c*2),
			add(ord(b,0,i),ord(a,1,i),0);
		add(ord(a,0,0),ord(b,1,1),c);
		add(ord(b,0,0),ord(a,1,1),c);
	}
	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	q.push({d[1]=0,1});
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;
		vis[x]=1;		
		for(auto i:e[x]){
			int y=i.first,k=i.second;
			if(!vis[y]&&d[y]>d[x]+k)
				q.push({d[y]=d[x]+k,y});
		}
	}
	for(int i=2;i<=n;i++)
		cout<<d[ord(i,1,1)]<<" ";
}