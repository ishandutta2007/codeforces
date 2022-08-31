//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo par3[200001];
pair<llo,llo> ma[200001];
llo ma3[200001];
vector<pair<llo,llo>> adj[200001];
llo find(llo no){
	if(par3[no]==no){
		return no;
	}
	par3[no]=find(par3[no]);
	return par3[no];
}
pair<llo,llo> par[200001][20];
llo lev[200001];
void dfs(llo no,llo par2=-1,llo levv=0){
	if(par2==-1){
		par[no][0]={-1,0};
	}
	lev[no]=levv;
	for(auto j:adj[no]){
		if(j.a!=par2){
			par[j.a][0]={no,j.b};
			dfs(j.a,no,levv+1);
		}
	}
}
llo lca(llo aa,llo bb){
	if(aa==bb){
		return 0;
	}
	llo ma=0;
	if(lev[aa]>lev[bb]){
		swap(aa,bb);
	}
	llo dif=lev[bb]-lev[aa];
	for(llo j=19;j>=0;j--){
		if((1<<j)&dif){
			ma=max(ma,par[bb][j].b);
			bb=par[bb][j].a;
		}
	}

	if(aa==bb){
		return ma;
	}
	for(llo j=19;j>=0;j--){
		if(par[aa][j].a!=par[bb][j].a){
			ma=max(ma,par[bb][j].b);
			ma=max(ma,par[aa][j].b);
			aa=par[aa][j].a;
			bb=par[bb][j].a;
		}
	}
	ma=max(ma,par[aa][0].b);
	ma=max(ma,par[bb][0].b);
	return ma;



}
llo ans2[200001];

llo ans[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,q;
	cin>>n>>q;
	for(llo i=0;i<n;i++){
		
		par3[i]=i;
		cin>>ma[i].a;
		ma[i].b=i;
		ma3[i]=0;
	}
	vector<pair<llo,pair<llo,llo>>> xx;

	for(llo i=0;i<n-1;i++){
		llo aa,bb,cc,dd;
		cin>>aa>>bb>>cc>>dd;
		aa--;
		bb--;
		adj[aa].pb({bb,dd});
		adj[bb].pb({aa,dd});
		xx.pb({cc,{aa,bb}});
	}
	dfs(0);
	for(llo j=1;j<20;j++){
		for(llo i=0;i<n;i++){
			if(par[i][j-1].a==-1){
				par[i][j]={-1,0};
			}
			else{
				par[i][j].a=par[par[i][j-1].a][j-1].a;
				par[i][j].b=max(par[i][j-1].b,par[par[i][j-1].a][j-1].b);
			}
		}
	}
	for(llo i=0;i<q;i++){
		llo v,x;
		cin>>v>>x;
		x--;
		xx.pb({v,{-(i+1),x}});
	}
	sort(xx.begin(),xx.end());
	reverse(xx.begin(),xx.end());
	for(auto j:xx){
		if(j.b.a<0){
			//query
			llo x=find(j.b.b);
			
			llo i=(-(j.b.a))-1;
			//cout<<i<<":"<<endl;
			ans2[i]=ma[x].a;
			ans[i]=max(ma3[x],lca(j.b.b,ma[x].b));

		}
		else{
			//cout<<j.b.a<<":"<<j.b.b<<endl;
			llo x=find(j.b.a);
			llo y=find(j.b.b);
			if(ma[x].a>ma[y].a){
				swap(x,y);
			}

			par3[x]=y;
			if(ma[x].a==ma[y].a){
				ma3[y]=max(ma3[y],ma3[x]);
				ma3[y]=max(ma3[y],lca(ma[y].b,ma[x].b));
			}
		}
	}
	for(llo i=0;i<q;i++){
		cout<<ans2[i]<<" "<<ans[i]<<endl;
	}



 
 

 
	return 0;
}