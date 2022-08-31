//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo t;
const llo mod=1e9+7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		llo su=0;
		llo ans=1;
		for(llo i=0;i<n;i++){
			for(llo j=0;j<m;j++){
				char s;
				cin>>s;
				if(s=='#'){
					su++;
					ans=(ans+ans);
					if(ans>=mod){
						ans-=mod;
					}
				}
			}
		}
		if(su==n*m){
			ans=(ans-1+mod)%mod;
		}
		cout<<ans<<endl;
	}









	return 0;
}