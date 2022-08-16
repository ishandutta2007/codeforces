//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
 
int t;
vector<int> adj[500001];
vector<int> adj2[500001];

int vis[500001];
int co[500001];
int ans[500001];
int ans2[500001];
set<int> xx;
int vis2[500001];
void dfs(int no){
	vis[no]=1;
	xx.erase(no);
	for(auto j:adj[no]){
		vis2[j]=1;
	}

	vector<int> yy;
	vector<int> zz;
	for(auto j:xx){
		if(vis2[j]==0){
			yy.pb(j);
		}
		else{
			zz.pb(j);
		}
	}
	xx.clear();
	for(auto j:zz){
		xx.insert(j);
	}
	for(auto j:adj[no]){
		vis2[j]=0;
	}
	for(auto j:yy){
		if(vis[j]==0){
			adj2[no].pb(j);
			adj2[j].pb(no);
		//	cout<<no<<"::"<<j<<endl;
			dfs(j);
		}	
	}
}

int par[500001];
int co2[500001];
int lev[500001];
int vis3[500001];

vector<int> ss;
void dfs2(int no,int par2=-1,int levv=0){
	par[no]=par2;
	ss.pb(no);
	lev[no]=levv;
	for(auto j:adj2[no]){
		if(j!=par2){
			co2[no]++;
			//cout<<no<<"::"<<j<<endl;
			dfs2(j,no,levv+1);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int ind=1;
		set<pair<int,int>> cur;
		for(int i=0;i<n;i++){
			vis[i]=0;
			adj[i].clear();
			adj2[i].clear();
			co2[i]=0;
			vis2[i]=0;
			vis3[i]=0;
		}
		for(int i=0;i<m;i++){
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			adj[l].pb(r);
			adj[r].pb(l);
		}
		for(int i=0;i<n;i++){
			co[i]=adj[i].size();
		}
		for(int i=0;i<n;i++){
			cur.insert({-co[i],i});
		}
		int xx5=n;
		while(cur.size()){
			pair<int,int> no=*cur.begin();
			no.a=-no.a;
			cur.erase(cur.begin());
			if(no.a==xx5-1){
				vis[no.b]=1;
				ans[no.b]=ind;
				ans2[no.b]=ind;
				for(auto j:adj[no.b]){
					if(vis[j]==0){
						cur.erase({-co[j],j});
						co[j]--;
						cur.insert({-co[j],j});
					}
				}
				//cout<<no.b<<"::"<<endl;
				xx5--;
				ind++;

			}
			else{
				break;
			}
		}
		xx.clear();

		for(int i=0;i<n;i++){
			if(vis[i]==0){
				xx.insert(i);
			}
		}
		for(int i=0;i<n;i++){
			if(vis[i]==0){
				dfs(i);
				ss.clear();

				dfs2(i);
				/*cout<<i<<":"<<endl;
				for(auto j:ss){
					cout<<j<<",";
				}
				cout<<endl;*/
				vector<pair<int,int>> tt;
				for(auto j:ss){
					vis3[j]=0;
					//if(co[j]==0){
						tt.pb({-lev[j],j});
					//}
				}
				sort(tt.begin(),tt.end());

				int le=tt.size();
				for(auto no:tt){
					//cout<<no.a<<">"<<no.b<<endl;
					if(vis3[no.b]==0){
						//cout<<no.b<<"<"<<endl;
						/*if(le==3){
							if(lev[no.b]==2){

								int x=par[par[no.b]];
								int y=par[no.b];
								int z=no.b;
								vis3[x]=1;
								vis3[y]=1;
								vis3[z]=1;
								ans[y]=ind;
								ans[x]=ind+1;
								ans[z]=ind+2;
								ans2[x]=ind;
								ans2[z]=ind+1;
								ans2[y]=ind+2;
								break;
								//continue;
							}
						}
*/
						
						vector<int> ee;
						//cout<<11<<endl;
						//cout<<par[no.b]<<endl;
						
						for(auto j:adj2[par[no.b]]){
							if(j!=par[par[no.b]] and vis3[j]==0){
								ee.pb(j);
								vis3[j]=1;
								//cout<<j<<"...."<<endl;
							}
						}
						le-=ee.size();
						le-=1;
						if(le==1){
							ee.pb(i);
							vis3[i]=1;
							le--;
						}
						ans[par[no.b]]=ind;
						for(int j=0;j<ee.size();j++){
							ans[ee[j]]=ind+j+1;
						}
						for(int j=0;j<ee.size();j++){
							ans2[ee[j]]=ind+j;
						}
						vis3[par[no.b]]=1;
						ans2[par[no.b]]=ind+ee.size();
						/*for(auto ii:ee){

							cout<<ii<<",,"<<ans[ii]<<",,"<<ans2[ii]<<endl;
						}*/
						ind+=ee.size();
						ind+=1;
						
					//	cout<<ind<<"//"<<endl;

					}

				}
				/*while(tt.size()){
					pair<int,int> no=*tt.begin();
					tt.erase(no);
					co[par[no.b]]--;
					if(co[par[no].b]==1){

					}


				}*/
			}
		}
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		for(int i=0;i<n;i++){
			cout<<ans2[i]<<" ";
		}
		cout<<endl;
	}




 
 
 
 
	return 0;
}