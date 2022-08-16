//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo vis[500001];
vector<llo> it[500001];
llo par[500001];
llo find(llo no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
llo mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,m;
	cin>>n>>m;
	vector<llo> ans2;
	for(llo i=0;i<m;i++){
		par[i]=i;
	}
	llo ans=1;
	vector<llo> xx;
	for(llo i=0;i<n;i++){
		llo x;
		cin>>x;
		vector<llo> aa;
		for(llo j=0;j<x;j++){
			llo bb;
			cin>>bb;
			bb--;
			aa.pb(bb);
		}
		it[i]=aa;
	/*	if(x==1){
			if(vis[aa[0]]==0){
				vis[aa[0]]=1;
				xx.pb(aa[0]);
				ans=(ans*2)%mod;
				ans2.pb(i);
			}
		}
		else{
			it[i]=aa;
		}*/
	}
	/*for(llo i=0;i+1<xx.size();i++){
		llo aa=find(xx[i]);
		llo bb=find(xx[i+1]);
		if(aa!=bb){
			par[aa]=bb;
		}
	}*/
	map<pair<int,int>,int> ss;
	llo la=-1;
	for(llo i=0;i<n;i++){
		if(it[i].size()==2){
			//if(vis[it[i][0]]==0 or vis[it[i][1]]==0){
				llo aa=find(it[i][0]);
				llo bb=find(it[i][1]);
				if(aa!=bb){
					par[aa]=bb;
					ans=(ans*2)%mod;
					ans2.pb(i);
					/*if(vis[it[i][1]] or vis[it[i][0]]){
						vis[it[i]][0]=1;
					}*/
				}
				
			//}
		}
		else{
			llo aa=find(it[i][0]);
			if(la!=-1){
				llo bb=find(la);
				if(aa==bb){
					continue;
				}
				par[aa]=bb;
				ans=(ans*2)%mod;
				ans2.pb(i);
				la=it[i][0];
			}
			else{
				ans=(ans*2)%mod;
				ans2.pb(i);
				la=it[i][0];
			}
			/*if(aa==it[i][0]){
				
				ans=(ans*2)%mod;
				ans2.pb(i);
				la=it[i][0];
			}*/
		}
	}
	sort(ans2.begin(),ans2.end());
	cout<<ans<<" "<<ans2.size()<<endl;
	for(auto j:ans2){
		cout<<j+1<<" ";
	}
	cout<<endl;





 
	return 0;
}