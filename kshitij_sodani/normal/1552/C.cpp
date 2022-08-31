//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo vis[201];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,k;
		cin>>n>>k;
		for(llo i=0;i<2*n;i++){
			vis[i]=0;
		}
		vector<pair<llo,llo>> cur;
		for(llo i=0;i<k;i++){
			llo aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			vis[aa]=1;
			vis[bb]=1;
			if(aa>bb){
				swap(aa,bb);
			}
			cur.pb({aa,bb});
		}
		vector<llo> ss;
	 	for(llo i=0;i<2*n;i++){
	 		if(vis[i]==0){
	 			ss.pb(i);
	 		}
	 	}
	 	for(llo i=0;i*2<ss.size();i++){
	 		cur.pb({ss[i],ss[i+(ss.size()/2)]});
	 	}
	 	llo ans=0;
	 	for(llo i=0;i<cur.size();i++){
	 		for(llo j=i+1;j<cur.size();j++){
	 			if(cur[i].b<cur[j].a){
	 				continue;
	 			}
	 			if( cur[j].b<cur[i].a){
	 				continue;
	 			}
	 			if(cur[i].a<cur[j].a and cur[j].b<cur[i].b){
	 				continue;
	 			}
	 			if(cur[j].a<cur[i].a and cur[i].b<cur[j].b){
	 				continue;
	 			}

	 			ans++;

	 		}
	 	}
	 	cout<<ans<<endl;
 

 
 
 	}


	return 0;
	
}