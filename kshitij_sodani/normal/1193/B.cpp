#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
#define endl "\n"
llo par[100001];

vector<llo> adj[100001];
llo vis[100001];
llo vis2[100001];
  set<pair<llo,llo>> *ss[100001];
llo m;
void  dfs(llo no){
//	cout<<no<<endl;
//	cout<<endl;
	llo ma=0;
	llo ind=-1;

	for(auto nn:adj[no]){
		dfs(nn);
		if((*ss[nn]).size()>ma){
			ma=(*ss[nn]).size();
			ind=nn;
		}
	}
	if(ind==-1){
		ss[no]=new set<pair<llo,llo>> ();
	}
	else{
		ss[no]=ss[ind];
	}
	for(auto jj:adj[no]){
		if(jj!=ind){
			for(auto kk:*(ss[jj])){
				auto it=(*ss[no]).lower_bound({kk.a,-1});
				if(it==(*ss[no]).end() or (*it).a!=kk.a){
					(*ss[no]).insert(kk);
				}
				else{
					pair<llo,llo> st=*it;
					st.b+=kk.b;
					(*ss[no]).insert(st);
					(*ss[no]).erase(it);
				}
				
			}
		}
	}
	if(vis[no]>-1){

		auto x=(*ss[no]).lower_bound({vis[no],-1});
		if(x==(*ss[no]).end() or (*x).a!=vis[no]){
			(*ss[no]).insert({vis[no],vis2[no]});
		}
		else{
			pair<llo,llo> y=*x;
			y.b+=vis2[no];
			(*ss[no]).erase(x);
			(*ss[no]).insert(y);
			
		}
		llo pre=0;
			while(true){
				auto ac=(*ss[no]).lower_bound({vis[no]+1,-1});
				if(ac==(*ss[no]).end()){
					break;
				}
				else{
					pre+=(*ac).b;
					if(pre>vis2[no]){
						pair<llo,llo> cc=*ac;
						(*ss[no]).erase(cc);
						cc.b=pre-vis2[no];
						(*ss[no]).insert(cc);
						break;
					}
					(*ss[no]).erase(ac);
				}
			}
	}

}

  
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	llo n,k;
	cin>>n>>m>>k;
	for(llo i=1;i<n;i++){
		cin>>par[i];
		adj[par[i]-1].pb(i);
	}
	for(llo i=0;i<n;i++){
		vis[i]=-1;
	}


	llo bb,cc,dd;
	for(llo i=0;i<m;i++){
		cin>>bb>>cc>>dd;
		vis[bb-1]=cc;
		vis2[bb-1]=dd;
	}
	dfs(0);
	llo tot=0;
	for(auto jj:(*ss[0])){
		tot+=jj.b;
	}
	cout<<tot<<endl;

	return 0;
}