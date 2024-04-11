
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo mod=998244353;
llo aa[200001];
llo bb[200001];
llo vis[200001];
llo ind[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,k;
		cin>>n>>k;
		for(llo i=0;i<n;i++){
			cin>>aa[i];
			aa[i]--;
			ind[aa[i]]=i;
		}
	/*	for(llo i=0;i<n;i++){
			vis[i]=1;
		}*/
		for(llo i=0;i<k;i++){
			cin>>bb[i];
			bb[i]--;
			vis[ind[bb[i]]]=1;
		}
		llo ans=1;
		for(llo i=0;i<k;i++){
			llo x=ind[bb[i]];
			llo co=0;
			if(x>0){
				if(vis[x-1]==0){
					co+=1;
				}
			}
			if(x<n-1){
				if(vis[x+1]==0){
					co+=1;
				}
			}
			ans=(ans*co)%mod;

			vis[ind[bb[i]]]=0;
		}
		cout<<ans<<endl;

	}









	return 0;
}