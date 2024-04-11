#include<bits/stdc++.h>
#define int long long
using namespace std;
int w,cnt[10];
int dp[11][9999];
inline void upd(int &x,int y){x=max(x,y);}
signed main(){
	cin>>w;
	int sum=0;
	for(int i=1;i<=8;i++)cin>>cnt[i],sum+=i*cnt[i];
	if(sum<=w)return printf("%I64d\n",sum)&0;
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<=7;i++){
		for(int j=0;j<(840*8)/(i+1)&&j<=cnt[i+1];j++){
			for(int k=0;k<840*8;k++){
				if(dp[i][k]==-1)continue;
				upd(dp[i+1][(k+j*(i+1))],dp[i][k]+(cnt[i+1]-j)/(840/(i+1)));
			}
		}
	}
	cerr<<w%(840*8)<<endl;
	for(int i;cin>>i&&~i;)cerr<<dp[8][i]<<endl;
	int ans=0;
	for(int i=0;i<840*8;i++){
		if(dp[8][i]==-1||i>w)continue;
		ans=max(ans,min(dp[8][i],(w-i)/840)*840+i);
	}
	cout<<ans<<endl;
	return 0;
}