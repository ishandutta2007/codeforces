#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<string>a[4],b[4];
main()
{
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		a[s.size()-1].push_back(s);
	}
	for(int i=0;i<n;i++)
	{
		cin>>s;
		b[s.size()-1].push_back(s);
	}
	int ans=0;
	int cnt[3]={};
	for(int j=0;j<a[0].size();j++)cnt[a[0][j]=="M"?0:a[0][j]=="S"?1:2]++;
	for(int j=0;j<b[0].size();j++)cnt[b[0][j]=="M"?0:b[0][j]=="S"?1:2]--;
	for(int j=0;j<3;j++)ans+=cnt[j]>0?cnt[j]:-cnt[j];
	ans/=2;
	for(int i=1;i<4;i++)
	{
		if(a[i].size()<1)continue;
		sort(a[i].begin(),a[i].end());
		sort(b[i].begin(),b[i].end());
		for(int j=0;j<a[i].size();j++)ans+=a[i][j]!=b[i][j];
	}
	cout<<ans<<endl;
}