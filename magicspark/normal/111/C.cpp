#include<bits/stdc++.h>
#define full ((1<<m)-1)
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int dp[44][66][66];
int n,m,ans;
int main(){
	memset(dp,inf,sizeof(dp));
	cin>>n>>m;
	if(n<m)swap(n,m);
	dp[1][0][0]=0;
	for(int i=1;i<=n;i++)
		for(int m1=0;m1<=full;m1++)
			for(int m2=0;m2<=full;m2++){
				if(dp[i][m1][m2]<1e6){
					for(int mask=0;mask<=full;mask++){
						if(i==1||((m1|mask)==full)){
							int msk=m2|mask|(mask>>1)|((mask<<1)&full);
							int cur=dp[i][m1][m2]+__builtin_popcount(mask);
							dp[i+1][msk][mask]=min(dp[i+1][msk][mask],cur);
						}
					}
				}
			}
	cout<<n*m-(*min_element(dp[n+1][full],dp[n+1][full]+66));
	return 0;
}