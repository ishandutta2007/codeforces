
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 

int n;
int it[1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<pair<int,int>> aa;
	for(int i=0;i<n;i++){
		cin>>it[i];
		aa.pb({it[i],i});
	}
	sort(aa.begin(),aa.end());
	vector<pair<int,int>> ans;
	int co=0;
	for(auto j:aa){
		it[j.b]=co;
		co++;
//		cout<<j.b<<":"<<co<<endl;
	}
/*	for(int i=0;i<n;i++){
		cout<<it[i]<<":";
	}
	cout<<endl;*/
	for(int i=0;i<n;i++){
		int ind=-1;
		for(int j=0;j<n;j++){
			if(it[j]==i){
				ind=j;
				break;
			}
		}
	//	cout<<ind<<endl;
		vector<int> pp;
		for(int j=ind+1;j<n;j++){
			if(it[j]<i){
				pp.pb(j);
			}
		}
		/*for(auto j:pp){
			cout<<j<<".";
		}
		cout<<endl;*/
		if(pp.size()){
			for(int i=pp.size()-1;i>=0;i--){
				ans.pb({ind,pp[i]});
			}
		}


	}
	cout<<ans.size()<<endl;
	for(auto j:ans){
		cout<<min(j.a,j.b)+1<<" "<<max(j.a,j.b)+1<<endl;
	}






	return 0;
}