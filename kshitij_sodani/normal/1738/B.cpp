#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo t;
llo it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n,k;
		cin>>n>>k;
		vector<llo> aa;
		for(llo i=0;i<k;i++){
			cin>>it[i];
			if(i>0){
				aa.pb(it[i]-it[i-1]);
			}
		}
		llo st=1;
		for(llo i=0;i+1<aa.size();i++){
			if(aa[i]>aa[i+1]){
				st=0;
			}
		}
		if(k==1){
			cout<<"YES"<<endl;
			continue;
		}
		//n-k+1 elements left
	//	if(aa[0]<=0){
			if(it[0]<=aa[0]*(n-k+1)){

			}
			else{
				st=0;
			}
		if(st==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		/*}
		else{

		}*/

	}
	



	return 0;
}