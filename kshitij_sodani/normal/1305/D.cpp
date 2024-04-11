#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long int llo;
#define a first
#define  b second
#define endl "\n"
int n;
set<int> adj[1001];
int vis[1001];
int co;
int aa,bb;
int ind;
void dfs(int no,int lev=0){
	if(lev==0){
		for(auto nn:adj[no]){
			aa=nn;
			if(adj[nn].size()>1){
				dfs(nn,lev+1);
				break;
			}
			
		}
	}
	else if(lev==1){
		aa=no;
		//bb=-1;
		for(auto nn:adj[no]){
			if(nn!=ind){
				bb=nn;
				break;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(vis,0,sizeof(vis));
	cin>>n;
	co=n;
	int u,v;
	int x;
	if(n==2){
		cout<<"? "<<1<<" "<<2<<endl;
		cout.flush();
		cin>>x;
		cout<<"!"<<" "<<x<<endl;
		return 0;
	}

	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		adj[u-1].insert(v-1);
		adj[v-1].insert(u-1);
	}
	//cout<<11<<endl;
	ind=-1;
	for(int i=0;i<n;i++){
		for(auto j:adj[i]){
			if(adj[j].size()>1){
				ind=i;
				break;
			}
		}
		if(ind>-1){
			break;
		}
	}
	while(true){
		aa=-1;
		bb=-1;
		if(ind!=-1){
			dfs(ind);
		}
		if(aa==-1){
			cout<<"! "<<ind+1<<endl;
			cout.flush();
			break;
		}
		else if(bb==-1){
			int st=0;
			for(auto j:adj[ind]){
				for(auto k:adj[j]){
					if(adj[k].size()>1){
						ind=j;
						st=1;
						break;
					}
				}
				if(st==1){
					break;
				}
			}
			if(st==1){
				continue;
			}
			else{
				cout<<"? "<<ind+1<<" "<<aa+1<<endl;
				cout.flush();
				cin>>x;
				cout<<"! "<<x<<endl;
			}
			break;
		}
		

		cout<<"? "<<ind+1<<" "<<bb+1<<endl;
		cout.flush();
		//cout<<aa<<" "<<bb<<" "<<ind<<endl;
	   // fflush(stdout);
		cin>>x;

		//cout<<x<<endl;
		if(x==aa+1){
			vis[ind]=1;
			vis[bb]=1;
			for(auto nn:adj[bb]){
				adj[nn].erase(bb);
			}
			adj[bb].clear();
			for(auto nn:adj[ind]){
				adj[nn].erase(ind);
			}
			adj[ind].clear();
			ind=aa;
			co-=2;
			continue;
		}
		else if(x==bb+1){
			vis[aa]=1;
			vis[ind]=1;
			for(auto nn:adj[ind]){
				adj[nn].erase(ind);
			}
			adj[ind].clear();
			for(auto nn:adj[aa]){
				adj[nn].erase(aa);
			}

			adj[aa].clear();
			co-=2;
			ind=bb;
			continue;
		}
		else if(x==ind+1){
			vis[aa]=1;
			vis[bb]=1;
			for(auto nn:adj[aa]){
				adj[nn].erase(aa);
			}

			adj[aa].clear();
			for(auto nn:adj[bb]){
				adj[nn].erase(bb);
			}
			adj[bb].clear();
			co-=2;
			continue;
		}
	}
/*	if(co==1){
		//int ans=-1;
		for(int i=0;i<n;i++){
			if(vis[i]==0){
				cout<<"! "<<i+1<<endl;
				break;
			}
		}
	}
	else{
		vector<int> ac;
		for(int i=0;i<n;i++){
			if(vis[i]==0){
				ac.pb(i);
			}
		}
		cout<<"? "<<ac[0]+1<<" "<<ac[1]+1<<endl;
		cout.flush();
		cin>>x;
		cout<<"! "<<x<<endl;
	}
*/


	









	return 0;
}