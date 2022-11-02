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

int N;
string S;
int dp[555][555];

signed main(){
	cin>>N>>S;
	
	fill_n(*dp,555*555,INF);

	
	for(int i=N-1;i>=0;i--){
		dp[i][i+1]=1;
		for(int j=i+2;j<=N;j++)for(int k=i+1;k<j;k++)chmin(dp[i][j],dp[i][k]+dp[k][j]);
		vint dp2(N+1,INF);
		dp2[i+1]=1;
		
		for(int j=i+1;j<N;j++){
			if(S[i]==S[j])chmin(dp2[j+1],dp2[j]);
			for(int k=j+1;k<=N;k++)chmin(dp2[k],dp2[j]+dp[j][k]);
		}
		for(int j=i+1;j<=N;j++)chmin(dp[i][j],dp2[j]);
	}

	cout<<dp[0][N]<<endl;
	return 0;
}