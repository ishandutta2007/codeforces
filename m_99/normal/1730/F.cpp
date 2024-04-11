#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001



int main(){
	
	int n,k;
	cin>>n>>k;
	
	k++;
	k = min(k,n);
	vector<int> p(n);
	vector<int> pos(n);
	rep(i,n){
		cin>>p[i];
		p[i]--;
		pos[p[i]] = i;
	}
	
	vector dp(20,vector<int>(1<<k,-Inf32));
	dp[10][0] = 0;
	rep(i,n){
		vector ndp(20,vector<int>(1<<k,-Inf32));
		rep(j,20){
			rep(kk,1<<k){
				if(dp[j][kk]==-Inf32)continue;
				rep(l,k){
					if((kk>>l)&1)continue;
					if(i + j - 10 +l>= n)break;
					int nv = dp[j][kk];
					for(int ll=l+1;ll<k;ll++){
						if((kk>>ll)&1){
							if(i+j-10+ll>=n)break;
							if(pos[i+j-10+l]>pos[i+j-10+ll])nv++;
							else nv--;
						}
					}
					//cout<<i<<j<<kk<<l<<nv<<endl;
					int nk = kk | (1<<l);
					int nj = j;
					nj--;
					while((nk&1)){
						nk >>= 1;
						nj++;
					}
					if(nj<0||nj>=20)continue;
					ndp[nj][nk] = max(ndp[nj][nk],nv);
					//cout<<i<<','<<nj<<','<<nk<<','<<nv<<endl;
				}
				
			}
		}
		swap(dp,ndp);
	}
	int ans = 0;
	rep(i,20){
		rep(j,dp[i].size()){
			ans = max(ans,dp[i][j]);
		}
	}
	ans *= -1;
	rep(i,n){
		for(int j=i+1;j<n;j++){
			if(pos[i]>pos[j])ans++;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}