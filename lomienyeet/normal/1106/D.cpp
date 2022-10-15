#include <bits/stdc++.h>
using namespace std;
const int mxN=1e5+6969;
bool vis[mxN];
vector<int> adjlist[mxN];
void solve(){
	int N,M;
	cin>>N>>M;
	for(int i=0,u,v;i<M;i++){
		cin>>u>>v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	priority_queue<int,vector<int>,greater<int> >pq;
	pq.push(1);
	vis[1]=true;
	for(int i=1;i<=N;i++){
		int cur=pq.top();
		pq.pop();
		cout<<cur<<" ";
		for(auto i:adjlist[cur]){
			if(!vis[i]){
				pq.push(i);
				vis[i]=true;
			}
		}
	}
}
int main(){
	int T=1;
	//cin>>T;
	while(T--)solve();
}