//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int it[1001][5];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<5;j++){
				cin>>it[i][j];
			}
		}
		string ans="NO";
		for(int i=0;i<5;i++){
			for(int j=i+1;j<5;j++){
				int st=1;
				int co=0;
				int co2=0;

				for(int l=0;l<n;l++){
					if(it[l][i]==0 and it[l][j]==0){
						st=0;
					}
					if(it[l][i]==1 and it[l][j]==0){
						co++;
					}
					if(it[l][i]==0 and it[l][j]==1){
						co--;
					}
					if(it[l][i]==1 and it[l][j]==1){
						co2++;
					}	
				}
				co=abs(co);
				if(co2>=co and st==1){
					ans="YES";
				}
			}
		}
		cout<<ans<<endl;
	}

	
 
 
	return 0;
}