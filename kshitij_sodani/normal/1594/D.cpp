#include <bits/stdc++.h>
using namespace std;
typedef long long llo;

#define a first
#define b second
#define pb push_back
#define mp make_pair
#define endl '\n'

vector<pair<llo,llo>> adj[500001];
llo vis[500001];
vector<llo> ss;
llo kk=1;
void dfs(llo no){
	ss.pb(no);
	for(auto j:adj[no]){
		if(vis[j.a]==-1){
			vis[j.a]=(j.b^vis[no]);
			dfs(j.a);
		}
		else{
			if((j.b^vis[no])!=vis[j.a]){
				kk=0;
			}
		}
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		for(llo i=0;i<n;i++){
			adj[i].clear();
			vis[i]=-1;
		}
		llo st=1;
		for(llo i=0;i<m;i++){
			llo cc,aa,bb;
			string ss;

			cin>>aa>>bb>>ss;
			if(ss=="crewmate"){
				cc=2;
			}
			else{
				cc=1;
			}
			aa--;
			bb--;
			cc=3-cc;
			adj[aa].pb({bb,cc-1});
			adj[bb].pb({aa,cc-1});
		}
		llo ans=0;
		for(llo i=0;i<n;i++){
			if(vis[i]==-1){
				
				llo cur=-1;
				kk=1;
				ss.clear();		
				vis[i]=0;	
				dfs(i);
				if(kk==1){
					llo cot=0;
					for(auto j:ss){
						if(vis[j]==1){
							cot++;
						}
					}
					cur=max(cur,cot);
				}
			/*	for(auto j:ss){
					cout<<vis[j]<<",";	
				}
				cout<<endl;*/
				for(auto j:ss){
					vis[j]=-1;
				}

				kk=1;
				ss.clear();		
				vis[i]=1;	
				dfs(i);
				if(kk==1){
					llo cot=0;
					for(auto j:ss){
						if(vis[j]==1){
							cot++;
						}
					}
					cur=max(cur,cot);
				}
				/*for(auto j:ss){
					cout<<vis[j]<<",";	
				}
				cout<<endl;*/
				ans+=cur;
				if(cur==-1){
					st=0;
				}

			}
		}
		if(st==0){
			cout<<-1<<endl;
		}
		else{
			cout<<ans<<endl;
		}
	}






	return 0;
}