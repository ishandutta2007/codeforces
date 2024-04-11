#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
 

int t;
int par3[200001];
int par2[200001];

set<int> pre[200001];//set of componenets in reverse graph
vector<int> pre2[200001];
vector<pair<int,int>> adj[200001];
int find(int no){
	if(par3[no]==no){
		return no;
	}
	par3[no]=find(par3[no]);
	return par3[no];
}
int cur2;
int ans;
int lev[200001];
pair<int,int> par[200001][20];
void dfs(int no,int par5=-1,int ma=-1,int levv=0){
	par[no][0].a=par5;
	if(par5==-1){
		par[no][0].b=0;
	}
	lev[no]=levv;
	for(auto j:adj[no]){
		if(j.a!=par5){
			par[j.a][0].b=j.b;
			dfs(j.a,no,max(ma,j.b),levv+1);
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
		for(int i=0;i<n;i++){
			par3[i]=i;
			par2[i]=i;
			pre[i].clear();
			pre2[i].clear();
			pre[i].insert(i);
			pre2[i].pb(i);
			adj[i].clear();
		}
		map<pair<int,int>,int> ss;
		vector<pair<int,pair<int,int>>> ed;
		for(int i=0;i<m;i++){
			int aa,bb,cc;
			cin>>aa>>bb>>cc;
			aa--;
			bb--;
			ss[{aa,bb}]++;
			ss[{bb,aa}]++;
			ed.pb({cc,{aa,bb}});
		}
		vector<pair<int,pair<int,int>>> ed2;
		ed2=ed;
		sort(ed.begin(),ed.end());
		for(auto kk:ed){
			int x=find(kk.b.a);
			int y=find(kk.b.b);
			if(x!=y){
				//add x to y
				if(pre[x].size()>pre[y].size()){
					swap(x,y);
				}
				par3[x]=y;
				for(auto i:pre[x]){
					vector<int> xx;
					for(auto j:pre[y]){
						int st=0;
						for(auto ii:pre2[i]){
							for(auto jj:pre2[j]){
								if(ss.find({ii,jj})==ss.end()){
									adj[ii].pb({jj,kk.a});
									adj[jj].pb({ii,kk.a});
									//cout<<ii<<"::"<<jj<<":"<<kk.a<<endl;
									xx.pb(j);
									st=1;
									break;
								}
							}
							if(st){
								break;
							}
						}
					}
					//merge component i with all in xx
					int cur=i;
					for(auto j:xx){
						int y=j;
						if(pre2[cur].size()<pre2[y].size()){
							swap(cur,y);
						}
						for(auto ii:pre2[y]){
							pre2[cur].pb(ii);
						}
					}
					pre[y].insert(cur);
					
					for(auto j:xx){
						if(j!=cur){
							pre[y].erase(j);
						}
					}
				}
			}
		}
		dfs(0);
		for(int j=1;j<20;j++){
			for(int i=0;i<n;i++){
				if(par[i][j-1].a==-1){
					par[i][j]={-1,0};
				}
				else{
					par[i][j].a=par[par[i][j-1].a][j-1].a;
					par[i][j].b=max(par[i][j-1].b,par[par[i][j-1].a][j-1].b);
				}
			}
		}
		for(auto j:ed2){
			cur2=j.b.b;
			int aa=j.b.a;
			int bb=j.b.b;
			if(lev[aa]>lev[bb]){
				swap(aa,bb);
			}
			ans=0;
			int dif=lev[bb]-lev[aa];
			for(int i=0;i<20;i++){
				if((1<<i)&dif){
					ans=max(ans,par[bb][i].b);
					bb=par[bb][i].a;
				}
			}
			if(aa!=bb){
				for(int i=19;i>=0;i--){
					if(par[aa][i].a!=par[bb][i].a){
						ans=max(ans,max(par[aa][i].b,par[bb][i].b));
						aa=par[aa][i].a;
						bb=par[bb][i].a;
					}
				}
				ans=max(ans,max(par[aa][0].b,par[bb][0].b));
			}
			//dfs(j.b.a);
			cout<<ans<<" ";
		}
		cout<<endl;
	}




 
 
	return 0;
}