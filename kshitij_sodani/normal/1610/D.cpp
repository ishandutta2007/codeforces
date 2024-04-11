//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
const llo mod=1e9+7;
llo n;
llo pre[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<llo> it;
	for(llo i=0;i<n;i++){
		int ii;
		cin>>ii;
		it.pb(ii);
	}
	pre[0]=1;
	for(llo i=1;i<=n;i++){
		pre[i]=(pre[i-1]+pre[i-1]);
		if(pre[i]>=mod){
			pre[i]-=mod;
		}
	}
	llo ans=0;
	vector<llo> co;
	while(it.size()){
		
		vector<llo> tt;
		llo co2=0;
		for(auto j:it){
			if(j%2==1){
				co2++;
			}
			else{
				tt.pb(j/2);
			}
		}
		co.pb(co2);
		it=tt;
	}

	llo le=n;
	for(auto j:co){
		if(le==n){
			if(j>0){
				ans=(ans+(pre[j]-1)*pre[le-j])%mod;
			}
			le-=j;
			continue;
		}
		else{

		}
		le-=j;
		if(j>0){
			ans=(ans+(pre[j-1]-1)*pre[le])%mod;
		}
	}
	cout<<ans<<endl;




 
	return 0;
}