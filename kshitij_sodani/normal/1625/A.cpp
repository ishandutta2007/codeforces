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
llo it[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n,l;
		cin>>n>>l;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		llo ans=0;
		for(llo i=0;i<l;i++){
			llo co=0;
			for(llo j=0;j<n;j++){
				if((1<<i)&it[j]){
					co++;
				}
			}
			if(co>=n-co){
				ans+=(1LL<<i);
			}
			else{

			}
		}
		cout<<ans<<endl;
	}




 
	return 0;
}