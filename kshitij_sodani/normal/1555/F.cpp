//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int par2[300001];
int find(int no){
	if(par2[no]==no){
		return no;
	}
	par2[no]=find(par2[no]);
	return par2[no];
}
int par[300001][20];
int vis[300001];
int ss[300001];
int endd[300001];
int co=0;
int tree[300001];
void u(int i,int j){
	while(i<=300000){
		tree[i]+=j;
		i+=(i&-i);
	}
}
int ss2(int i){
	int su=0;
	while(i>0){
		su+=tree[i];
		i-=(i&-i);
	}
	return su;
}
int lev[300001];
int lev2[300001];
vector<pair<int,int>> adj[300001];
void dfs(int no,int par3=-1,int levv=0,int levv2=0){
	vis[no]=1;
	par[no][0]=par3;
	ss[no]=co;
	co++;
	lev2[no]=levv2;
	lev[no]=levv;
	for(auto j:adj[no]){
		if(vis[j.a]==0){
			dfs(j.a,no,levv^j.b,levv2+1);
		}
	}
	endd[no]=co-1;
	/*if(par3>=0){
		u(ss[no]+1,1);
		u(endd[no]+2,-1);
	}*/
}
int lca(int aa,int bb){
	if(lev2[aa]>lev2[bb]){
		swap(aa,bb);
	}
	int xx=lev2[bb]-lev2[aa];
	for(int j=19;j>=0;j--){
		if((1<<j)&xx){
			bb=par[bb][j];
		}
	}
	if(aa==bb){
		return aa;
	}
	for(int j=19;j>=0;j--){
		if(par[aa][j]!=par[bb][j]){
			aa=par[aa][j];
			bb=par[bb][j];
		}
	}
	return par[aa][0];


}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		par2[i]=i;
	}
	vector<pair<pair<int,int>,int>> ss5;
	for(int i=0;i<q;i++){
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		aa--;
		bb--;
		int x=find(aa);
		int y=find(bb);
		if(x!=y){
			par2[x]=y;
			adj[aa].pb({bb,cc});
			adj[bb].pb({aa,cc});
			//cout<<aa<<":"<<bb<<":"<<cc<<endl;
			ss5.pb({{-1,-1},-1});
		}
		else{
			ss5.pb({{aa,bb},cc});
		}
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			dfs(i);
		}
	}


	for(int j=1;j<20;j++){
		for(int i=0;i<n;i++){
			if(par[i][j-1]==-1){
				par[i][j]=-1;
			}
			else{
				par[i][j]=par[par[i][j-1]][j-1];
			}
		}
	}

	for(auto j:ss5){

		if(j.a.a==-1){
			cout<<"YES"<<endl;
			continue;
		}
		int x=lca(j.a.a,j.a.b);
		int su=ss2(ss[j.a.a]+1)+ss2(ss[j.a.b]+1)-2*ss2(ss[x]+1);
		/*if(j.a.a==2 and j.a.b==3){
			cout<<su<<endl;	
		}*/
		if(su>0){
			cout<<"NO"<<endl;
			continue;
		}
		if((j.b+lev[j.a.a]+lev[j.a.b])%2==0){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		int cur=j.a.a;
		while(cur!=x){
			u(ss[cur]+1,1);
			u(endd[cur]+2,-1);
			cur=par[cur][0];
		}
		cur=j.a.b;
		while(cur!=x){
			u(ss[cur]+1,1);
			u(endd[cur]+2,-1);
			cur=par[cur][0];
		}


	

	}


 
	return 0;
}