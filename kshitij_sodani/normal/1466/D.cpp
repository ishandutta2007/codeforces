//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[100001];
vector<llo> adj[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){
		llo n;	
		cin>>n;
		llo cur=0;
		vector<pair<llo,llo>> ss;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			cur+=it[i];
			ss.pb({it[i],i});
			adj[i].clear();
		}
		for(llo i=0;i<n-1;i++){
			llo aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			/*if(aa>bb){
				swap(aa,bb);
			}*/
			//if(it[aa]>=it[bb]){
				adj[aa].pb(bb);
			//}
			//else{
				adj[bb].pb(aa);
			//}
		}
		sort(ss.begin(),ss.end());
		reverse(ss.begin(),ss.end());
		//for(llo i=0;i<n;i++){
		/*for(auto j:ss){
				cout<<j.a<<":"<<j.b<<endl;
			}*/
			cout<<cur<<" ";
			llo cot=1;

			for(auto j:ss){
				for(llo k=0;k+1<adj[j.b].size();k++){
					cur+=j.a;
					cout<<cur<<" ";
				}
				//for(auto k:adj[j.b]){
				//	cot++;
				/*	if(cot==n){
						break;
					}*/
					//cur+=j.a;
				//	cout<<cur<<" ";
				//}
			}
			cout<<endl;
		//}
		



	}



 
	return 0;
}