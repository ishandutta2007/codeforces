#include<bits/stdc++.h>
#define ord(x,y) ((x)+(y)*n)
using namespace std;
int const N=5200010;
int n,m,d[N],vis[N];
struct node{
	int first,second;
	int operator<(const node&rhs)const{
		return rhs.first<first;
	}
};
vector<node>e[N];
priority_queue<node>q;
void add(int x,int y,int k){
	e[x].push_back({y,k});
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	while(m--){
		int x,y,k;cin>>x>>y>>k;
		add(x,ord(y,k),k*k),add(y,ord(x,k),k*k);
		for(int i=1;i<=50;i++)
			add(ord(x,i),y,k*k+2*k*i),add(ord(y,i),x,k*k+2*k*i);
	}
	memset(d,0x3f,sizeof d);
	q.push({d[1]=0,1});
	while(!q.empty()){
		int x=q.top().second;q.pop();vis[x]=1;
		for(int i=0;i<e[x].size();i++){
			int y=e[x][i].first,k=e[x][i].second;
			if(d[y]>d[x]+k)q.push({d[y]=d[x]+k,y});
		}
		while(!q.empty()&&vis[q.top().second])
			q.pop();
	}
	for(int i=1;i<=n;i++)
		cout<<(d[i]>1e9?-1:d[i])<<" ";
	cout<<"\n";
}