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
llo it[301];
llo aa[301];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	vector<pair<llo,llo>> ss;
	for(llo i=0;i<m;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		ss.pb({aa,bb});
	}
	llo ans=-1;
	vector<llo> ans2;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<n;j++){
			aa[j]=it[j];
		}
		vector<llo> ind;
		llo ind2=0;
		for(auto j:ss){
			ind2++;
			if(j.b<i or j.a>i){
				ind.pb(ind2);
				for(llo k=j.a;k<=j.b;k++){
					aa[k]--;
				}
			}
		}
		llo mi=aa[i];
		for(llo j=0;j<n;j++){
			mi=min(mi,aa[j]);
		}
		llo cur=aa[i]-mi;
		if(cur>ans){
			ans=cur;
			ans2=ind;
		}

	}
	cout<<ans<<endl;
	cout<<ans2.size()<<endl;
	for(auto j:ans2){
		cout<<j<<" ";
	}
	cout<<endl;
	



 
	return 0;
}