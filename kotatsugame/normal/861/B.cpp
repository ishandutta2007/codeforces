#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k[100],f[100];
vector<int>ans;
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>k[i]>>f[i];
		if(k[i]==n)
		{
			cout<<f[i]<<endl;
			return 0;
		}
	}
	for(int i=1;i<=1000;i++)
	{
		bool ok=true;
		for(int j=0;ok&&j<m;j++)
		{
			ok&=k[j]<=i*f[j]&&k[j]>i*(f[j]-1);
		}
		if(ok)
		{
			ans.push_back(i);
		}
	}
	for(int i=0;i<ans.size();i++)ans[i]=(n+ans[i]-1)/ans[i];
	if(ans.size()==0)
	{
		cout<<-1<<endl;
		return 0;
	}
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	if(ans.size()==1)
	{
		cout<<ans[0]<<endl;
	}
	else cout<<-1<<endl;
}