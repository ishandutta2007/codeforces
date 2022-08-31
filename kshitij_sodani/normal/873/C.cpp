//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int n,m,k;
int it[101][101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;

	for(int i=0;i<n;i++){
		int co=0;
		int co2=0;
		for(int j=0;j<m;j++){
			cin>>it[i][j];


		}
	}
	int ans=0;
	int ans2=0;
	for(int j=0;j<m;j++){
		int co=0;
		int co2=0;
		int ma2=n;
		int ma=-1;
		for(int i=0;i<n;i++){
			if(i>=k){
				if(it[i-k][j]==1){
					co++;
				}
			}
			if(it[i][j]==1){
				co2++;
			}
			if(i>=k){
				if(it[i-k][j]==1){
					co2--;
				}
			}
			if(i>=k-1){
				if(co2>ma){
					ma=co2;
					ma2=co;
				}
				else if(co2==ma){
					if(co<ma2){
						ma2=co;
					}
				}
			}
		}
		//cout<<ma<<":"<<ma2<<endl;
		ans2+=ma;
		ans+=ma2;
	}


	cout<<ans2<<" "<<ans<<endl;
 	
 	
	return 0;
}