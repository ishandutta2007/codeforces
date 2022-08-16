//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
const int mod=1e9+7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){
		llo n,k;
		cin>>n>>k;
		//find k in base 2 and change to base n
		llo ind=0;
		llo cur=1;
		llo ans=0;
		while(k>0){
			if(k%2==0){

			}
			else{
				ans=(ans+cur)%mod;
			}
			cur=(cur*n)%mod;
			ind++;
			k/=2;
		}
		cout<<ans<<endl;

	}

 
 
 
	return 0;
}