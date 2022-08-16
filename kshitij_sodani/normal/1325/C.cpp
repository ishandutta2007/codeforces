#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long int llo;
#define a first
#define  b second
#define endl "\n"

int adj[100001];
vector<pair<pair<int,int>,int>> e;
int comp(pair<pair<int,int>,int> ac,pair<pair<int,int>,int> cc){
	if(min(adj[ac.a.a],adj[ac.a.b])<min(adj[cc.a.a],adj[cc.a.b])){
		return 1;
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//memset(ans,0,sizeof(ans));
	int n;
	cin>>n;
	int aa,bb;
	memset(adj,0,sizeof(adj));
	for(int i=0;i<n-1;i++){
		cin>>aa>>bb;
		e.pb(mp(mp(aa-1,bb-1),i));
		adj[aa-1]+=1;
		adj[bb-1]+=1;
	}
	sort(e.begin(),e.end(),comp);
	int ans[n-1];
	for(int i=0;i<n-1;i++){
		ans[e[i].b]=i;
	}
	for(int i=0;i<n-1;i++){
		cout<<ans[i]<<endl;
	}

	return 0;
}