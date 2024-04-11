#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}


const int INF=1001001001001001001ll;
const int L=840;

int W;
int cnt[10];

int dp[10][10*L];

signed main(){
	cin>>W;
	for(int i=1;i<=8;i++)cin>>cnt[i];

	fill_n(*dp,100*L,-INF);
	dp[0][0]=0;
	for(int i=1;i<=8;i++){
		for(int j=0;j<8*L;j++){
			for(int k=0;k<=cnt[i]&&k*i<L;k++){
				chmax(dp[i][j+k*i],dp[i-1][j]+(cnt[i]-k)/(L/i));
			}
		}
	}

	int ans=0;
	rep(i,8*L){
		if(i>W|| dp[8][i]<0)continue;
		chmax(ans,i+L*min((W-i)/L,dp[8][i]));
	}
	cout<<ans<<endl;
	return 0;
}