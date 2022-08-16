//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo vis[1000000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(llo ind=2;ind<=100000;ind++){
		if(vis[ind]==0){
			vis[ind]=2;
			//cout<<ind<<",";
			for(llo j=ind+ind;j<=100000;j+=ind){
				vis[j]=1;
			}
		}
	}

	llo t;
	cin>>t;
	while(t--){
		llo d;
		cin>>d;
		vector<llo> kk;
		for(llo i=d+1;true;i++){
			if(vis[i]==2){
				if(kk.size()==1){
					if(i-kk[0]<d){
						continue;
					}
				}
				kk.pb(i);
			}
			if(kk.size()==2){
				break;
			}
		}
		llo ans=min(kk[0]*kk[1],kk[0]*kk[0]*kk[0]);
		cout<<ans<<endl;
	}





	
 
	return 0;
}