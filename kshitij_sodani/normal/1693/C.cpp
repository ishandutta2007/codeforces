#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

vector<int> adj[200001];
int co[200001];
int dist[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		co[aa]++;
		adj[bb].pb(aa);
	}
	for(int i=0;i<n;i++){
		dist[i]=-1;
	}
	dist[n-1]=0;
	priority_queue<pair<int,int>> ss;
	ss.push({0,n-1});
	while(ss.size()){
		pair<int,int> no=ss.top();
		ss.pop();
		no.a=-no.a;
		if(no.a>dist[no.b]){
			continue;
		}
		for(auto j:adj[no.b]){
			co[j]--;
			if(dist[j]==-1 or dist[j]>dist[no.b]+1+co[j]){
				dist[j]=dist[no.b]+1+co[j];
				ss.push({-dist[j],j});
			}
		}
	}
	cout<<dist[0]<<endl;

 
 
 
 
	return 0;
}