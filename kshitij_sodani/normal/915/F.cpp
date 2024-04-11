#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
 
llo n;
llo it[1000001];
llo par[1000001];
llo ss[1000001];
llo vis[1000001];
vector<llo> adj[1000001];
llo find(llo no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<pair<llo,llo>> ss3;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		par[i]=i;
		ss[i]=1;
		ss3.pb({it[i],i});
	}
	for(llo i=0;i<n-1;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	llo ans=0;

	sort(ss3.begin(),ss3.end());

	for(auto j:ss3){
		vis[j.b]=1;
		llo su=1;
		llo su2=0;
		for(auto i:adj[j.b]){
			if(vis[i]==1){
				llo x=find(i);
				su+=ss[x];
				su2+=(ss[x]*ss[x]+ss[x])/2;
				par[x]=j.b;
				ss[j.b]+=ss[x];
			}
		}
		llo zz=su*su;
		zz=(zz+su)/2;
		zz-=su2;
		ans+=zz*j.a;
	}
	for(llo i=0;i<n;i++){
		ss3[i].a=-ss3[i].a;
		vis[i]=0;
		par[i]=i;
		ss[i]=1;
	}
	sort(ss3.begin(),ss3.end());

		for(auto j:ss3){
		vis[j.b]=1;
		llo su=1;
		llo su2=0;
		for(auto i:adj[j.b]){
			if(vis[i]==1){
				llo x=find(i);
				su+=ss[x];
				su2+=(ss[x]*ss[x]+ss[x])/2;
				par[x]=j.b;
				ss[j.b]+=ss[x];
			}
		}
		llo zz=su*su;
		zz=(zz+su)/2;
		zz-=su2;
		ans+=zz*j.a;
	}
	cout<<ans<<endl;
 
 
 
 
 
	return 0;
}