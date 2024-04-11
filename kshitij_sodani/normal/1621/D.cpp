//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[501][501];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo ans=0;
		for(llo i=0;i<2*n;i++){
			for(llo j=0;j<2*n;j++){
 
				cin>>it[i][j];
				if(i>=n and j>=n){
					ans+=it[i][j];	
				}
			}
		}
		llo mi=min(it[n-1][n],it[n-1][2*n-1]);
		mi=min(mi,it[n][0]);
		mi=min(mi,it[n][n-1]);
		mi=min(mi,it[0][2*n-1]);
		mi=min(mi,it[0][n]);
		mi=min(mi,it[2*n-1][0]);
		mi=min(mi,it[2*n-1][n-1]);

		ans+=mi;
 
		cout<<ans<<endl;
		
 
	}
 
 
 
 
 
 
 
	return 0;
}