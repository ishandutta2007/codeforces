//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[21];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		sort(it,it+n);
		llo co=0;
		llo ans=0;
		for(llo i=0;i<n;i++){

			while(it[i]%2==0){
				it[i]/=2;
				co++;
			}
		//	ans+=it[i];
		}
		sort(it,it+n);
		for(int i=0;i<n;i++){
			if(i==n-1){
				for(int j=0;j<co;j++){
					it[i]*=2;
				}
			}
			ans+=it[i];
		}

		cout<<ans<<endl;
	}



 
	return 0;
}