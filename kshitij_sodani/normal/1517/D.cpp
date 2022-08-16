//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo aa[501][501];
llo bb[501][501];
llo dp[501][501];
llo dp2[501][501];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,m;
	cin>>n>>m;
	llo k;
	cin>>k;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<m-1;j++){
			cin>>aa[i][j];
		}
	}
	for(llo i=0;i<n-1;i++){
		for(llo j=0;j<m;j++){
			cin>>bb[i][j];
		}
	}
	if(k%2==1){
		for(llo i=0;i<n;i++){
			for(llo j=0;j<m;j++){	
				cout<<-1<<" ";
			}
			cout<<endl;
		}
		return 0;
	}
	for(llo ii=1;ii<=(k/2);ii++){
		//cout<<ii<<endl;
		for(llo i=0;i<n;i++){
			for(llo j=0;j<m;j++){
				dp2[i][j]=1e9;
				if(j>0){
					dp2[i][j]=min(dp2[i][j],dp[i][j-1]+aa[i][j-1]);
				}
				if(j<m-1){
					dp2[i][j]=min(dp2[i][j],dp[i][j+1]+aa[i][j]);
				}
				if(i>0){
					dp2[i][j]=min(dp2[i][j],dp[i-1][j]+bb[i-1][j]);
				
				}
				if(i<n-1){
					dp2[i][j]=min(dp2[i][j],dp[i+1][j]+bb[i][j]);
				}
			}
		}
		for(llo i=0;i<n;i++){
			for(llo j=0;j<m;j++){
				dp[i][j]=dp2[i][j];
				//cout<<dp[i][j]<<",";
			}
		//	cout<<endl;

		}
	}
	for(llo i=0;i<n;i++){
		for(llo j=0;j<m;j++){
			cout<<(2*dp[i][j])<<" ";
		}
		cout<<endl;
	}
	//cout<<endl;




 
 
	return 0;
}