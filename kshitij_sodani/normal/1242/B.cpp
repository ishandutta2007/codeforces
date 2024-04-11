#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define a first
#define b second
#define pb push_back
llo mod=100000007;
vector<int> adj[100001];
int par[100001];
int si[100001];
int find(int no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	int aa,bb;
	for(int i=0;i<m;i++){
		cin>>aa>>bb;
		adj[aa-1].pb(bb-1);
		adj[bb-1].pb(aa-1);
	}
	int ans=n;
	for(int i=0;i<n;i++){
		par[i]=i;
		si[i]=1;
	}
	set<int> kk;
	kk.insert(0);
	for(int i=1;i<n;i++){
		map<int,int> ss;
		ss.clear();
		for(auto j:adj[i]){
			if(j>=i){
				continue;
			}
			ss[find(j)]+=1;
		}
		int st=0;
		vector<int> kl;
		for(auto k:kk){
			if(ss[k]<si[k] or ss.find(k)==ss.end()){
				par[k]=i;
				si[i]+=si[k];
				ans-=1;
				kl.pb(k);
				st=1;
			}
			else{
				continue;
			}
		}
		for(auto j:kl){
			kk.erase(j);
		}
		kk.insert(i);
	
	}
	cout<<ans-1<<endl;


	return 0;
}