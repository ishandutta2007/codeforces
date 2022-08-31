
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

llo it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo ans=n;
		for(int i=0;i<30;i++){
			if((1LL<<i)>n){
				continue;
			}
			if((1LL<<i)&n){
				ans=min(ans,((n-(n%(1LL<<i))))-1);
			}
			else{
				ans=min(ans,((n-(n%(1LL<<i))))-1);
			}
		}
		cout<<ans<<endl;




	}






	return 0;
}