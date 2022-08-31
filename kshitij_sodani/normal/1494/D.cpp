//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int n;
int it[501][501];
vector<pair<int,int>> ed;
int ans[100001];
int co=0;
int cot=0;
void solve(vector<int> aa,int par=-1){

	if(aa.size()==1){
		ed.pb({aa[0]+1,par});
		//ans[aa[i]]=i;
		
	}
	else{
		int ma=0;
		for(auto j:aa){
			for(auto i:aa){
				ma=max(ma,it[j][i]);
			}
		}
		vector<vector<int>> bb;
		for(int i=0;i<aa.size();i++){
			bb.pb({});
		}
		for(int i=0;i<aa.size();i++){
			int st=1;
			for(int j=0;j<i;j++){
				if(it[aa[j]][aa[i]]<ma){
					bb[j].pb(aa[i]);
					st=0;
					break;
				}
			}
			if(st){
				bb[i].pb(aa[i]);
			}
		}

/*		vector<int> bb;
		vector<int> cc;
		for(auto j:aa){
			if(it[aa[0]][j]<ma){
				bb.pb(j);
			}
			else{
				cc.pb(j);
			}
		}*/
		co++;
		int cur=co;
		if(par!=-1){
			ed.pb({cur,par});
		}
		else{
			cot=cur;
		}
		ans[cur]=ma;
		for(auto j:bb){
			if(j.size()){
				solve(j,cur);
			}
		}

	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	co=n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>it[i][j];
		}
	}
	vector<int> aa;
	for(int i=0;i<n;i++){
		aa.pb(i);
	}
	solve(aa);
	cout<<co<<endl;
	for(int i=1;i<=co;i++){
		if(i<=n){
			cout<<it[i-1][i-1]<<" ";
		}
		else{
			cout<<ans[i]<<" ";
		}
	}
	cout<<endl;
	cout<<cot<<endl;
	for(auto j:ed){
		cout<<j.a<<" "<<j.b<<endl;
	
	}






 
	return 0;
}