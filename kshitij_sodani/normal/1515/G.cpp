//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo n,m;
vector<pair<llo,llo>> adj[200001];
vector<pair<llo,llo>> adj2[200001];
vector<pair<llo,llo>> adj3[200001];
llo ans[200001];
vector<llo> ord;
llo vis[200001];
llo cot=0;
void dfs(llo no){
	vis[no]=1;
	for(auto j:adj[no]){
		if(vis[j.a]==0){
			dfs(j.a);
		}
	}
	ord.pb(no);
}
void dfs2(llo no){
	vis[no]=cot;
	for(auto j:adj2[no]){
		if(vis[j.a]==0){
			dfs2(j.a);
		}
	}
}
vector<pair<pair<llo,llo>,llo>> cur;
llo lev[200001];
void dfs3(llo no,llo levv=0){
	vis[no]=1;
	lev[no]=levv;
	ord.pb(no);
	for(auto j:adj3[no]){
		if(vis[j.a]==0){
			dfs3(j.a,levv+j.b);
		}
		else if(vis[j.a]==1){
			cur.pb({{no,j.a},j.b});
		}
	}
	//vis[no]=2;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(llo i=0;i<m;i++){
		llo aa,bb,cc;
		cin>>aa>>bb>>cc;
		aa--;
		bb--;
		adj[aa].pb({bb,cc});
		adj2[bb].pb({aa,cc});
	}
	for(llo i=0;i<n;i++){
		if(vis[i]==0){
			dfs(i);
		}
	}
	for(llo i=0;i<n;i++){
		vis[i]=0;	
	}
	reverse(ord.begin(),ord.end());
	for(auto i:ord){
		if(vis[i]==0){
			cot++;
			dfs2(i);
		}
	}
	/*for(int i=0;i<n;i++){
		cout<<vis[i]<<":";
	}
	cout<<endl;*/
	for(llo i=0;i<n;i++){
		for(auto j:adj[i]){
			if(vis[i]==vis[j.a]){
				adj3[i].pb(j);
			}
		}
	}
	for(llo i=0;i<n;i++){
		vis[i]=0;	
	}
	for(llo i=0;i<n;i++){
		if(vis[i]==0){
			ord.clear();
			cur.clear();
			dfs3(i);
		/*	for(auto j:cur){
				cout<<j.a.a<<":"<<j.a.b<<":"<<j.b<<endl;
			}
			cout<<endl;
			cout<<11<<endl;*/
			if(cur.size()==0){
				for(auto j:ord){
					ans[j]=-1;
				}
			}
			else{
				llo st=-1;
				for(auto j:cur){
					llo val=lev[j.a.a]-lev[j.a.b]+j.b;
					val=abs(val);
					if(st==-1){
						st=val;
					}
					st=__gcd(st,val);
				}
				//cout<<st<<endl;
			
				for(auto j:ord){
					ans[j]=st;
				}
			}

		}
	}
	llo q;
	cin>>q;
	while(q--){
		llo aa,bb,cc;
		cin>>aa>>bb>>cc;
		aa--;

		if(ans[aa]==-1){
			if(bb==0){
				cout<<"YES"<<endl;
				continue;
			}
			cout<<"NO"<<endl;
			continue;
		}
		if(bb%(__gcd(ans[aa],cc))==0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}

	}









	return 0;
}