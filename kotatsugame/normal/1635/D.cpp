#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
const int mod=1e9+7;
int N,P;
int dp[2<<17],sum[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>P;
	dp[0]=1;
	for(int i=0;i<=P;i++)
	{
		dp[i+1]=(dp[i+1]+dp[i])%mod;
		dp[i+2]=(dp[i+2]+dp[i])%mod;
		sum[i]=((i>0?sum[i-1]:0)+dp[i])%mod;
	}
	vector<int>A(N);
	for(int i=0;i<N;i++)cin>>A[i];
	sort(A.begin(),A.end());
	set<int>S;
	for(int a:A)
	{
		bool fn=false;
		int a_=a;
		while(a>0)
		{
			if(S.find(a)!=S.end())
			{
				fn=true;
				break;
			}
			if(a%2==1)a/=2;
			else if(a%4!=0)break;
			else a/=4;
		}
		if(!fn)S.insert(a_);
	}
	int ans=0;
	for(int a:S)
	{
		int np=P;
		while(a>0)
		{
			a/=2;
			np--;
		}
		if(np<0)continue;
		ans=(ans+sum[np])%mod;
	}
	cout<<ans<<endl;
}