#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define a first
#define b second
#define pb push_back
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int it[n];
		vector<int> cc[26];
		int ans=1;
		for(int i=0;i<n;i++){
			cin>>it[i];
			cc[it[i]-1].pb(i);
		}
		int fr[n][26];
		for(int i=0;i<n;i++){
			if(i==0){
				for(int j=0;j<26;j++){
					fr[i][j]=0;
				}
			}
			else{
				for(int j=0;j<26;j++){
					fr[i][j]=fr[i-1][j];
				}
			}
			fr[i][it[i]-1]+=1;
		}
		for(int i=0;i<26;i++){
			if(cc[i].size()>1){
				for(int j=0;j<cc[i].size()/2;j++){
					int co=(j+1)*2;
					int ind=cc[i][j]+1;
					int ind2=cc[i][cc[i].size()-j-1]-1;
					int ma=0;
					if(ind<=ind2){
						for(int k=0;k<26;k++){
							if(ind>0){
								ma=max(ma,fr[ind2][k]-fr[ind-1][k]);
							}
							else{
								ma=max(ma,fr[ind2][k]);
							}
						}
					}
					ans=max(ans,co+ma);
				}
			}
		}
		cout<<ans<<endl;
		
	}







	return 0;
}