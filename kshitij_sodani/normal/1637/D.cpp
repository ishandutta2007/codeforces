//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo aa[101];
llo bb[101];
llo dp[101][101*101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>aa[i];
		}
		for(llo i=0;i<n;i++){
			cin>>bb[i];
		}
		for(llo i=0;i<n;i++){
			for(llo j=0;j<=1e4;j++){
				dp[i][j]=1e16;
			}
		}
		llo nn=n-1;
		dp[0][aa[0]]=0;//(aa[0]*aa[0]*nn)+(bb[0]*bb[0]*nn);
		dp[0][bb[0]]=0;//(aa[0]*aa[0]*nn)+(bb[0]*bb[0]*nn);
		llo cur=aa[0];
		cur+=bb[0];
		for(llo i=1;i<n;i++){
			for(llo j=0;j<=1e4;j++){
				llo x=aa[i];
				llo y=bb[i];
				if(dp[i-1][j]==(llo)1e16){
					continue;
				}


				if(j+x<=1e4){
					dp[i][j+x]=min(dp[i][j+x],dp[i-1][j]+j*2*aa[i]+(cur-j)*2*bb[i]);
				}
				if(j+y<=1e4){
					dp[i][j+y]=min(dp[i][j+y],dp[i-1][j]+j*2*bb[i]+(cur-j)*2*aa[i]);
				}
				
			}
			cur+=aa[i]+bb[i];
		}
		llo ans=1e16;
		for(llo j=0;j<=1e4;j++){
			ans=min(ans,dp[n-1][j]);
		}
		for(llo j=0;j<n;j++){
			ans+=(n-1)*aa[j]*aa[j];
			ans+=(n-1)*bb[j]*bb[j];
		}
		cout<<ans<<endl;
	}



	


 
	return 0;
}