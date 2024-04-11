#include<bits/stdc++.h>
#define int long long
using namespace std;

int dat[22][22],cnt[22];
int n,a[400005];
int dp[1<<20];

inline void upd(int &x,int y){if(y<x)x=y;}
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);a[i]--;cnt[a[i]]++;
		for(int j=0;j<20;j++)dat[a[i]][j]+=cnt[j];
	}
	memset(dp,0x3f3f3f3f3f3f3f3f,sizeof dp);
	dp[0]=0;
	for(int mask=0;mask<(1<<20);mask++){
		for(int j=0;j<20;j++){
			if(mask&(1<<j))continue;
			int val=0;
			for(int k=0;k<20;k++){
				if(mask&(1<<k)){
					val+=dat[j][k];
				}
			}
			upd(dp[mask|(1<<j)],val+dp[mask]);
		}
	}
	cout<<dp[(1<<20)-1]<<endl;
	return 0;
}