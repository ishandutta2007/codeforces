//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
vector<llo> it[100001];
llo vis[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	vector<pair<llo,llo>> ss;
	llo ans=n*n;
	for(llo i=0;i<n;i++){
		llo x;
		cin>>x;
		llo st=1;
		for(llo j=0;j<x;j++){
			llo aa;
			cin>>aa;
			it[i].pb(aa);
			if(it[i].size()>=2){
				if(it[i][j]>it[i][j-1]){
					st=0;
				}
			}
		}
		vis[i]=st;
		if(st){
			ss.pb({it[i].back(),i+1});
			ss.pb({it[i][0],-(i+1)});
			
		}
	}
	
	if(ss.size()){
		sort(ss.begin(),ss.end());
		vector<llo> tt;
		llo ind=-1;
		for(auto j:ss){
			//cout<<j.a<<","<<j.b<<endl;
			if(j.b<0){
				tt.pb(j.a);
			}
			else{
				while(ind+1<tt.size()){
					if(tt[ind+1]<=j.a){
						ind++;
					}
					else{
						break;
					}
				}
				ans-=(ind+1);
			}
		}
	}
	cout<<ans<<endl;







 
	return 0;
}