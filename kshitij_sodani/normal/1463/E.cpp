//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

vector<int> adj[300001];
int par[300001];
vector<int> adj2[300001];
vector<int> adj3[300001];
int coo=0;
int st[300001];
int endd[300001];
void dfs(int no,int par2=-1){
	par[no]=par2;
	st[no]=coo;
	coo++;
	for(auto j:adj[no]){
		dfs(j,no);
	}
	endd[no]=coo-1;
}
vector<vector<int>> ss;
int ind[300001];
int vis2[300001];
int vis[300001];
int cot[300001];
llo vis4[300001];
void dfs2(int no){
	vis[no]=1;
	vis2[no]=1;
	if(par[no]!=-1){
		if(vis2[par[no]]==1){
			vis4[no]=1;
			cot[ss.size()-1]++;
		}
	}
	ss[ss.size()-1].pb(no);
	ind[no]=ss.size()-1;
	for(auto j:adj2[no]){
		dfs2(j);
	}
	vis2[no]=0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	int cur=-1;
	for(int i=0;i<n;i++){
		int aa;
		cin>>aa;
		if(aa!=0){
			adj[aa-1].pb(i);
		}
		else{
			cur=i;
		}
	}
	int stt=1;
	for(int i=0;i<k;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj2[aa].pb(bb);
		adj3[bb].pb(aa);
		if(bb==cur){
			stt=0;
		}
	}
	if(stt==0){
		cout<<0<<endl;
		return 0;
	}
	dfs(cur);
	for(int i=0;i<n;i++){
		if(adj3[i].size()==0){
			ss.pb({});
			dfs2(i);
			set<int> cur2;
			for(auto j:ss.back()){
				auto jj=cur2.lower_bound(st[j]);
				if(jj!=cur2.end()){
					if(*jj<=endd[j]){
						cout<<0<<endl;
						return 0;
					}
				}
				cur2.insert(st[j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			cout<<0<<endl;
			return 0;
		}
	}
	queue<int> tt;
	tt.push(cur);
	cot[ind[cur]]++;
	int le=n;
	vector<int> ans;
	/*for(auto j:ss){
		for(auto i:j){
			cout<<i<<',';
		}
		cout<<endl;
	}*/
	//set<int> cur;
	while(le){
		if(tt.size()==0){
			cout<<0<<endl;
			return 0;
		}
		int no=tt.front();
	//	cout<<no<<":"<<endl;
	/*	for(auto j:adj[no]){
			if(ind[j]==ind[no]){
				cot[ind[j]]++;
			}
		}*/
		if(cot[ind[no]]<ss[ind[no]].size()){
			cout<<0<<endl;
			return 0;
		}

		tt.pop();
		le-=ss[ind[no]].size();
		for(auto j:ss[ind[no]]){
			ans.pb(j+1);
			for(auto i:adj[j]){
				//cur.insert(i);
				if(vis4[i]){
					continue;
				}
				if(ind[i]!=ind[no]){
					cot[ind[i]]++;
					if(cot[ind[i]]==ss[ind[i]].size()){
						tt.push(ss[ind[i]][0]);
					}
				}
			}
		}
	}
	for(auto j:ans){
		cout<<j<<" ";
	}
	cout<<endl;
	//dfs(cur);








 
	return 0;
}