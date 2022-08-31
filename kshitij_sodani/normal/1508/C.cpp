//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo xx=0;
llo par[200001];
llo vis[1001][1001];
llo n,m;
vector<llo> adj[200001];
llo find(llo no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
llo vis2[200001];
llo st=0;
void dfs(llo no,llo par=-1){
	vis2[no]=1;
	for(llo j=0;j<n;j++){
		if(no!=j){
			if(vis[no][j]==0){
				if(vis2[j]==0){
					dfs(j,no);
				}
				else if(j!=par){
					st=1;
				}
			}
		}
	}
}
set<llo> cur;
llo yy=-1;
void dfs2(llo no){
	if(cur.find(no)!=cur.end()){
		cur.erase(no);
	}
	par[no]=yy;
	set<llo> cur2;
	vis2[no]=1;
	for(auto j:adj[no]){
		cur2.insert(j);
	}
	vector<llo> ss;
	for(auto j:cur){
		if(cur2.find(j)==cur2.end()){
			ss.pb(j);
		}
	}
	for(auto j:ss){
		cur.erase(j);
	}
	for(auto j:ss){
		dfs2(j);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	cin>>n>>m;
	xx=((n*(n-1))/2);

	llo cur2=0;
	vector<pair<llo,pair<llo,llo>>> ed;
	for(llo i=0;i<m;i++){
		llo aa,bb,cc;
		cin>>aa>>bb>>cc;
		aa--;
		bb--;
		if(n<=1000){
			vis[aa][bb]=cc;
			vis[bb][aa]=cc;
		}
		adj[aa].pb(bb);
		adj[bb].pb(aa);
		cur2=(cur2^cc);
		ed.pb({cc,{aa,bb}});
	}

	ed.pb({cur2,{-1,-1}});
	sort(ed.begin(),ed.end());
	


	xx-=m;
	xx--;
	if(n<=1000){
		for(int i=0;i<n;i++){
			vis2[i]=0;
		}
		for(llo i=0;i<n;i++){
			if(vis2[i]==0){
				dfs(i);
			}
		}
		if(st==0){
			//cout<<11<<endl;
			vector<pair<llo,llo>> pp;
			for(llo i=0;i<n;i++){
				for(llo j=i+1;j<n;j++){
					if(vis[i][j]==0){
						pp.pb({i,j});
					}
				}
			}
			llo ans=1e18;
			vector<pair<llo,pair<llo,llo>>> ed2;
			for(int i=0;i<n;i++){
				par[i]=i;
			}
			for(auto j:ed){
				if(j.b.a==-1){
					ed2.pb(j);
					continue;
				}
				int x=find(j.b.a);
				int y=find(j.b.b);
				if(x!=y){
					ed2.pb(j);
					par[x]=y;
				}
			}
			for(auto i:pp){
				for(llo i=0;i<n;i++){
					par[i]=i;
				}
				llo su=0;
				for(auto j:pp){
					if(j.a==i.a and j.b==i.b){
						continue;
					}
					llo x=find(j.a);
					llo y=find(j.b);
					if(x!=y){
						par[x]=y;
					}
				}
				for(auto j:ed2){
					llo x,y;
					if(j.b.a==-1){
						x=find(i.a);
						y=find(i.b);
					}
					else{
						x=find(j.b.a);
						y=find(j.b.b);
					}
					if(x!=y){
						par[x]=y;
						su+=j.a;
					}
				}
				ans=min(ans,su);
			}
			cout<<ans<<endl;
			return 0;
		}

	}
	for(int i=0;i<n;i++){
			vis2[i]=0;
		}
	for(int i=0;i<n;i++){
		cur.insert(i);
	}
	for(llo i=0;i<n;i++){
		if(vis2[i]==0){
			yy=i;
			dfs2(i);
		}
	}
	
	llo ans=0;
	for(auto j:ed){
		if(j.b.a==-1){
			continue;
		}
		llo x=find(j.b.a);
		llo y=find(j.b.b);
		if(x!=y){
			par[x]=y;
			ans+=j.a;
		}
	}
	cout<<ans<<endl;
















 
 
	return 0;
}