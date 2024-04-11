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
llo ans[200001];
llo par2[200001];
vector<pair<llo,llo>> adj[200001];
llo find(llo no){
	if(par2[no]==no){
		return no;
	}
	par2[no]=find(par2[no]);
	return par2[no];
}


map<pair<llo,llo>,llo> ss;
llo par[200001][20];
llo mi[200001][20];
//llo mi2[200001][20];
llo lev[200001];
void dfs(llo no,llo par2=-1,llo levv=0){
	par[no][0]=par2;
	//mi2[no][0]=no;
	lev[no]=levv;
	for(auto j:adj[no]){
		if(j.a!=par2){
			mi[j.a][0]=j.b;
			dfs(j.a,no,levv+1);
		}
	}
}
//llo pp=-1;
pair<llo,llo> lca(llo aa,llo bb){
	if(lev[aa]>lev[bb]){
		swap(aa,bb);
	}
	llo dd=lev[bb]-lev[aa];
	llo cur=0;
	for(llo j=19;j>=0;j--){
		if(dd&(1<<j)){
			/*if(mi[bb][j]>cur){
				pp=mi2[bb][j];
			}*/
			cur=max(cur,mi[bb][j]);
			bb=par[bb][j];
		}
	}
	if(aa==bb){
		return {aa,cur};
	}
	for(llo j=19;j>=0;j--){
		if(par[aa][j]!=par[bb][j]){
			/*if(mi[bb][j]>cur){
				pp=mi2[bb][j];
			}*/
			cur=max(cur,mi[bb][j]);
			/*if(mi[aa][j]>cur){
				pp=mi2[aa][j];
			}*/
			cur=max(cur,mi[aa][j]);
			aa=par[aa][j];
			bb=par[bb][j];
		}
	}
	cur=max(cur,mi[aa][0]);
	cur=max(cur,mi[bb][0]);
	return {par[aa][0],cur};
}
vector<llo> pre[200001];
vector<llo> pre2[200001];
multiset<llo> xx[200001];
llo dfs2(llo no,llo par2=-1,llo ba=-1){
	vector<llo> tt;
	pair<llo,llo> ma={-1,-1};
	for(auto j:adj[no]){
		if(j.a!=par2){
		//	cout<<no<<":"<<j.a<<endl;
			llo cur=dfs2(j.a,no,j.b);
			tt.pb(cur);
			ma=max(ma,{(llo)xx[cur].size(),cur});
		}
	}
	if(ma.a==-1){
		for(auto j:pre[no]){
			xx[no].insert(j);
		}

		if(par2!=-1){
			if(xx[no].size()){
				auto j=xx[no].begin();
				//	j--;
				llo x=ss[{no,par2}];
				if(ans[x]==-1){
					ans[x]=(*j)-1;
				}
			}
		}
		return no;
	}
	//cout<<no<<","<<ma.b<<endl;
	for(auto j:pre[no]){
		xx[ma.b].insert(j);
	}
	for(auto j:tt){
		if(j!=ma.b){
			for(auto jj:xx[j]){
				xx[ma.b].insert(jj);
			}
		}
	}
	for(auto j:pre2[no]){
		auto jj=xx[ma.b].find(j);
		xx[ma.b].erase(jj);
	}
	if(par2!=-1){
		if(xx[ma.b].size()){
			auto j=xx[ma.b].begin();
			llo x=ss[{no,par2}];
			if(ans[x]==-1){
				
				ans[x]=(*j)-1;
			}
		}
	}
	return ma.b;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pair<llo,pair<llo,llo>>> ed;
	cin>>n>>m;
	map<pair<llo,llo>,llo> ac;
	for(llo i=0;i<m;i++){
		llo aa,bb,cc;
		cin>>aa>>bb>>cc;
		aa--;
		bb--;
		ac[{aa,bb}]=cc;
		ac[{bb,aa}]=cc;
		ss[{aa,bb}]=i;
		ss[{bb,aa}]=i;
		ed.pb({cc,{aa,bb}});
	}
	sort(ed.begin(),ed.end());
	//reverse(ed.begin(),ed.end());
	for(llo i=0;i<n;i++){
		par2[i]=i;
	}
	vector<pair<llo,llo>> ed2;
	for(auto j:ed){
		llo x=find(j.b.a);
		llo y=find(j.b.b);
		if(x!=y){
			par2[x]=y;
			adj[j.b.a].pb({j.b.b,j.a});
			adj[j.b.b].pb({j.b.a,j.a});
		}
		else{
			ed2.pb(j.b);
		}
	}
	dfs(0);
	for(llo j=1;j<20;j++){
		for(llo i=0;i<n;i++){
			if(par[i][j-1]==-1){
				continue;
			}
			par[i][j]=par[par[i][j-1]][j-1];
			if(par[i][j]>=0){
			/*	if(mi[i][j-1]>=mi[par[i][j-1]][j-1]){
					mi2[i][j]=mi2[i][j-1];
				}
				else{
					mi2[i][j]=mi2[par[i][j-1]][j-1];
				}*/
				mi[i][j]=max(mi[i][j-1],mi[par[i][j-1]][j-1]);
			}
		}
	}
	for(llo i=0;i<m;i++){
		ans[i]=-1;
	}
	for(auto j:ed2){
		pair<llo,llo> no=lca(j.a,j.b);
		ans[ss[j]]=no.b-1;
		llo aa=j.a;
		llo bb=j.b;
		if(bb==no.a){
			swap(aa,bb);
		}
		llo xx=0;
		/*llo yy;
		yy=lca(j.a,pp);*/
		//if(yy<)
		if(aa==no.a){
		//	cout<<bb<<":"<<no.a<<":"<<no.b<<endl;
			pre[bb].pb(ac[j]);
			pre2[no.a].pb(ac[j]);
		}
		else{
			pre[aa].pb(ac[j]);
			pre[bb].pb(ac[j]);
			pre2[no.a].pb(ac[j]);
			pre2[no.a].pb(ac[j]);
		}
	}
	dfs2(0);

	for(llo i=0;i<m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;









 
 
	return 0;
}