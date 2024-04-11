//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		llo ans=1e18;
		llo cur=0;
		llo cur2=0;
		for(llo i=30;i>=0;i--){
			if((1LL<<i)&m){

			}
			else{
				ans=min(ans,cur2^cur+((1LL<<i)^((1LL<<i)&n)));
			}
			/*if(i<=2){
				cout<<cur<<":"<<cur2<<endl;
			}*/
			cur2+=(1LL<<i)&n;
			cur+=(1LL<<i)&m;
		}
		cout<<ans<<endl;
	}

 
 
 

 
	return 0;
}