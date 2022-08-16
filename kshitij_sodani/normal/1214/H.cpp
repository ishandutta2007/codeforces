//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int n,k;
vector<int> adj[200001];
pair<int,int> ma={-1,-1};

void dfs(int no,int lev=0,int par=-1){
	ma=max(ma,{lev,no});
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,lev+1,no);
		}
	}
}
int rr=-1;
vector<int> ss;
vector<int> tt;
void dfs2(int no,int par=-1){
	ss.pb(no);
	if(no==rr){
		tt=ss;
	}
	for(auto j:adj[no]){
		if(j!=par){
			dfs2(j,no);	
		}
	}
	ss.pop_back();
}
int ans[200001];
int vis[200001];
int ma2=0;
vector<pair<int,int>> cot;
int ma3[200001];
void dfs3(int no,int par=-1,int lev=0){
	ma2=max(ma2,lev);
	cot.pb({no,lev});
	ma3[no]=lev;
	for(auto j:adj[no]){
		if(j!=par and vis[j]==0){
			dfs3(j,no,lev+1);	
			ma3[no]=max(ma3[no],ma3[j]);
		}
	}

}
vector<int> ee;
void dfs4(int no,int par=-1,int lev=0){
	ee.pb(no);
	if(lev>=k){
		ans[no]=ans[ee[lev-k]];
	}
	for(auto j:adj[no]){
		if(j!=par and vis[j]==0){
			dfs4(j,no,lev+1);	
		}
	}
	ee.pop_back();

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	dfs(0,0);
	int x=ma.b;
	ma={-1,-1};
	dfs(x,0);
	int y=ma.b;
	rr=y;
	dfs2(x);
	if(tt.size()<k){
		cout<<"Yes"<<endl;
		for(int i=1;i<=n;i++){
			cout<<1<<" ";
		}
		cout<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		ans[i]=0;
	}
	for(int i=0;i<tt.size();i++){
		ans[tt[i]]=((i%k))+1;
		vis[tt[i]]=1;
	}
/*	for(auto j:tt){
		cout<<j<<",";
	}
	cout<<endl;*/
	for(int i=0;i<tt.size();i++){
		ma2=0;
		cot.clear();
		dfs3(tt[i]);
		for(auto j:cot){
			//do left
			//
			if(j.a!=tt[i]){
				set<int> cur;
				if(j.b<k){
					//cout<<tt[i]<<":"<<j.a<<":"<<":"<<ma3[j.a]<<endl;
					if(ma3[j.a]+(int)(tt.size())-i-1+1>=k){
						//cout<<11<<endl;
						cur.insert(ans[tt[i-j.b]]);
					}
					if((ma3[j.a]+i+1>=k)){
						//cout<<22<<endl;
						cur.insert(ans[tt[i+j.b]]);
					}
					if(cur.size()==2){
						cout<<"No"<<endl;
						return 0;
					}
					if(cur.size()==0){
						ans[j.a]=1;
						continue;
					}
					ans[j.a]=*(cur.begin());
				}
			}
		}
		dfs4(tt[i]);
	}
	cout<<"Yes"<<endl;
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;








	return 0;
}