//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int it[501];
int dp[501][501];
int remin(int aa,int bb){
	if(aa==-1){
		return bb;
	}
	if(bb==-1){
		return aa;
	}
	return min(aa,bb);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		for(int i=0;i<n;i++){
			cin>>it[i];
		}
		int stt=1;
		for(int i=0;i<n-1;i++){
			if(it[i]>it[i+1]){
				stt=0;
			}
		}
		if(stt){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<=500;j++){
				dp[i][j]=-1;
			}
			dp[i][x]=-1;
			if(it[i]>x){
				int st=1;
				for(int j=0;j<i;j++){
					if(it[j]>x){
						st=0;
					}
				}
				for(int j=0;j<i-1;j++){
					if(it[j]>it[j+1]){
						st=0;
					}
				}
				if(st==1){
					dp[i][x]=1;
				}
			}
		}
		for(int i=0;i<n;i++){
			int ma=1000;
			int mi=0;
			for(int j=i-1;j>=0;j--){
				if(it[j]>=mi){
					for(int k=0;k<=500;k++){
						if(k>ma or it[i]<=it[j]){
							continue;
						}
						if(dp[j][k]>=0){
							dp[i][it[j]]=remin(dp[i][it[j]],dp[j][k]+1);
						}
					}
				}
				if(j<i-1){
					if(it[j]>it[j+1]){
						break;
					}
				}
				ma=min(ma,it[j]);
				mi=max(mi,it[j]);
			}
		}
		int ans=-1;
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<=500;j++){
				if(i<n-1){
					if(j>it[i+1]){
						continue;
					}
				}
				ans=remin(ans,dp[i][j]);
			}
			if(i<n-1){
				if(it[i]>it[i+1]){
					break;
				}
			}
		}
		cout<<ans<<endl;
	}


 
 
	return 0;
}