//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
vector<llo> adj[200001];
llo ma[200001];
void dfs(llo no,llo par=-1){
	ma[no]=0;
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no);
			ma[no]=max(ma[no],ma[j]+1);
		}
	}
}
vector<llo> ss;
void dfs2(llo no,llo par=-1,llo lev=0){
	llo st=1;
	for(auto j:adj[no]){
		if(j!=par){
			if(st==1 and ma[j]==ma[no]-1){
				st=0;
				dfs2(j,no,lev+1);
				continue;
			}
			dfs2(j,no,1);
		}
	}
	if(ma[no]==0){
		ss.pb(lev);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,k;
	cin>>n>>k;
	for(llo i=0;i<n-1;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	dfs(0);
	dfs2(0);
	llo ans=-1e18;
	sort(ss.begin(),ss.end());
	reverse(ss.begin(),ss.end());
	llo su=0;
	
	for(llo i=0;i<=k;i++){
		if(i>ss.size()){
			ans=max(ans,i*(n-i));
			continue;
		}
		llo cur=i*(n-i);
		llo xx=min(n-su,(n/2));
		cur+=xx*(xx-n);
		ans=max(ans,cur);
		if(i<k){
			su+=ss[i];
			if(i==0){
				su++;
			}
		}
	}	
	cout<<ans<<endl;






 
	return 0;
}