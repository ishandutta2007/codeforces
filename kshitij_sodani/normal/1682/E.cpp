#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
int it[200001];

int ne[200001];
int be[200001];
vector<pair<int,int>> pre[200001];
vector<int> adj[200001];
vector<int> adj2[200001];
int co[200001];
int vis[200001];
int ind[200001];
vector<int> dd;
void dfs(int no){
	ind[no]=dd.size();
	vis[no]=1;
	dd.pb(no);
	for(auto j:adj[no]){
		if(vis[j]==0){
			dfs(j);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	map<pair<int,int>,int> ss;
	set<pair<int,int>> cur;
	for(int i=0;i<n;i++){
		cin>>it[i];
		it[i]--;
		adj[i].pb(it[i]);
	}
	for(int i=0;i<m;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		pre[aa].pb({bb,i});
		pre[bb].pb({aa,i});
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			dd.clear();
			dfs(i);
		
			for(auto j:dd){
					
				for(int ii=0;ii<pre[j].size();ii++){
					if(ind[pre[j][ii].a]<ind[j]){
		
						pre[j][ii].a=ind[pre[j][ii].a]+dd.size();
					}
					else{
						pre[j][ii].a=ind[pre[j][ii].a];
					}
				}

				sort(pre[j].begin(),pre[j].end());
				
				for(int ii=0;ii+1<pre[j].size();ii++){
				//	cout<<j<<":"<<pre[j][ii].b<<endl;
					co[pre[j][ii+1].b]++;
					adj2[pre[j][ii].b].pb(pre[j][ii+1].b);
				}
			}

		}
	}
	queue<int> tt;
	for(int i=0;i<m;i++){
		if(co[i]==0){
			tt.push(i);
		}
	}
	while(tt.size()){
		int no=tt.front();
		tt.pop();
		cout<<no+1<<" ";
		for(auto j:adj2[no]){
			co[j]--;
			if(co[j]==0){
				tt.push(j);
			}
		}
	}
	cout<<endl;






	return 0;
}