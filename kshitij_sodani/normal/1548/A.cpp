//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

set<llo> pre[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,m;
	cin>>n>>m;
	llo ans=0;
	for(llo i=0;i<m;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		if(aa>bb){
			swap(aa,bb);
		}
		pre[aa].insert(bb);

	}
	for(llo i=0;i<n;i++){
		if(pre[i].size()==0){
			ans++;
		}
	}
	llo q;
	cin>>q;
	while(q--){
		llo tt;
		cin>>tt;
		if(tt==1){
			llo aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			if(aa>bb){
				swap(aa,bb);
			}
			if(pre[aa].size()==0){
				ans--;
			}
			pre[aa].insert(bb);

		}
		else if(tt==2){
			llo aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			if(aa>bb){
				swap(aa,bb);
			}
			pre[aa].erase(bb);
			if(pre[aa].size()==0){
				ans++;
			}

		}
		else if(tt==3){
			cout<<ans<<endl;
		}
	}
 
 

 
 
 
	return 0;
}