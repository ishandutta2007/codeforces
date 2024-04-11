//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int t;
int it[300001];
int ma[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
	//	set<pair<int,int>> ss;
	//	set<int> ss;
		set<pair<int,int>> ss;
		vector<pair<int,int>> tt;
	//	set<int> vis;
		for(int i=0;i<n;i++){
			cin>>it[i];
			ss.insert({i,it[i]});
			tt.pb({it[i],i});
		}	
		sort(tt.begin(),tt.end());
		for(auto j:tt){
		/*	if(vis.find(j.b)!=vis.end()){
				continue;
			}*/
			if(ss.size()==1){
				break;
			}
			auto ii=ss.lower_bound({j.b,j.a});
			if(ii==ss.end()){
				continue;
			}
			if((*ii).a!=j.b){
				continue;
			}
			auto kk=ss.end();
			kk--;
			if((*kk).a==(*ii).a){
				break;
			}
			vector<pair<int,int>> ee;
			while((*ii).a<(*kk).a){
				ee.pb(*ii);
				ii++;
			}
			for(auto j:ee){
				ss.erase(j);
			}
		}
		if(ss.size()==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}


	}











 
	return 0;
}