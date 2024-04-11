//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n;
llo aa[200001];
llo bb[200001];
llo it[200001];
vector<llo> adj[200001];
llo ans=0;
pair<llo,llo> dfs(llo no,llo par=-1,llo mi=-1){
	if(par==-1){
		mi=it[no];
	}
	mi=min(mi,it[no]);
	pair<llo,llo> cur={0,0};
	if(aa[no]!=bb[no]){
		if(aa[no]==0){
			cur.a+=1;
		}
		else{
			cur.b+=1;
		}
	}
	for(auto j:adj[no]){
		if(j!=par){
			pair<llo,llo> cot=dfs(j,no,mi);
			cur.a+=cot.a;
			cur.b+=cot.b;
		}
	}
	llo mii=min(cur.a,cur.b);
	ans+=mi*mii;

	//cout<<no<<","<<cur.a<<","<<cur.b<<endl;
	cur.a-=mii;
	cur.b-=mii;
	return cur;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	llo co=0;
	for(llo i=0;i<n;i++){
		cin>>it[i]>>aa[i]>>bb[i];
		if(aa[i]!=bb[i]){
			if(aa[i]==0){
				co++;
			}
			else{
				co--;
			}
		}
	}
	for(llo i=0;i<n-1;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	if(co!=0){
		cout<<-1<<endl;
		return 0;
	}
	dfs(0);
	cout<<ans*2<<endl;

	return 0;
}