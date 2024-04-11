#include<bits/stdc++.h>
#include<string>
#define int long long
int cnt,T,ans,c[100000];
using namespace std;
signed main()
{
	cin>>T;
	while (T--)
	{
		string sst;
		cin>>sst;cnt=ans=0;
		if (sst[0]=='1') cnt++,c[cnt]=1;
		for (int i=1;i<=sst.length();i++)
		  if (sst[i]=='1'&&sst[i-1]=='1') c[cnt]++; else 
		  if (sst[i]=='1') cnt++,c[cnt]=1;
		sort(c+1,c+cnt+1);
		for (int i=cnt;i>=1;i-=2) ans+=c[i];
		cout<<ans<<endl;
	}
		
}