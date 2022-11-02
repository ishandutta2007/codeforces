#include<bits/stdc++.h>
using namespace std;
//#define double int
int n,m,x;
double v,dp1[105][105],dp2[105][10005],sum[105][105],k;
vector<double>a[105];
double num(int _,int i,int j) // _  i  j 
{
	int z=a[_].size();
	return sum[_][z]-sum[_][z-j]+sum[_][i];
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=1;j<=x;j++)
			cin>>v,a[i].push_back(v),sum[i][j]=sum[i][j-1]+v;
	}
	//cin>>k;
	k=1;
	if(k==0)cout<<"0",exit(0);
	if(k>0)
	{	
		for(int _=1;_<=n;_++)
			for(int l=1;l<=a[_].size();l++)
				for(int i=0;i<=l;i++) 
				{
					int j=l-i;
					dp1[_][l]=max(dp1[_][l],num(_,i,j));
				}//dp1
		for(int _=1;_<=n;_++)
			for(int i=0;i<=m;i++)
				for(int j=0;j<=a[_].size() && j<=i;j++)
					dp2[_][i]=max(dp2[_][i],dp2[_-1][i-j]+dp1[_][j]);//dp2
			
	}
	else if(k<0)
	{
		//memset(dp1,0x3f,sizeof dp1);//,memset(dp2,0x3f,sizeof dp2);
		for(int _=1;_<=n;_++)
			for(int l=1;l<=a[_].size();l++)
			{
				dp1[_][l]=1e9;
				for(int i=0;i<=l;i++) 
				{
					int j=l-i;
					dp1[_][l]=min(dp1[_][l],num(_,i,j));
					
				}//dp1
				//cout<<dp1[_][l]<<" "<<_<<" "<<l<<endl;;
			}
				//puts("");
		for(int i=1;i<=a[1].size();i++)dp2[0][i]=1e9;
		for(int _=1;_<=n;_++)
			for(int i=0;i<=m;i++)
			{
				dp2[_][i]=1e9;
				for(int j=1;j<=a[_].size() && j<=i;j++)
				{
						dp2[_][i]=min(dp2[_][i],dp2[_-1][i-j]+dp1[_][j]);
					//cout<<_<<" "<<i<<" "<<j<<" "<<dp2[_-1][i-j]+dp1[_][j]<<" "<<dp2[_][i]<<endl;
				}
				
			}
				//dp2
	}
	//cout<<dp2[n][m]<<" "<<pp<<endl;
	cout<<dp2[n][m]*k;
	return 0;
}