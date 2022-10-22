#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
typedef unsigned long long ull;
const int inf=1039074182;
const int mod=1e9+7;
using namespace std;
int n,l,r;
ll dp[200005][3];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>l>>r;
	int s0=r/3;
	int s1=r/3+(r%3>=1);
	int s2=r/3+(r%3==2);
	l--;
	s0-=l/3;
	s1-=l/3+(l%3>=1);
	s2-=l/3+(l%3==2);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i][0]+=((dp[i-1][0]*s0+dp[i-1][1]*s2)%mod+dp[i-1][2]*s1)%mod;
		dp[i][0]%=mod;
		dp[i][1]+=((dp[i-1][0]*s1+dp[i-1][1]*s0)%mod+dp[i-1][2]*s2)%mod;
		dp[i][1]%=mod;
		dp[i][2]+=((dp[i-1][0]*s2+dp[i-1][1]*s1)%mod+dp[i-1][2]*s0)%mod;
		dp[i][2]%=mod;
	}
//	cout<<dp[1][0]<<' '<<dp[1][1]<<' '<<dp[1][2]<<endl;
	cout<<dp[n][0]<<endl;
	return 0;
}