#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,ans,cur,mn,mni,cnta[4],cntb[4];
string a[111],b[111];
bool u[111];
int Abs(int x)
{
	return max(x,-x);
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
	for (int i=1;i<=n;i++)
	{
		if (a[i].size()==1) continue;
		mn=1e9;
		for (int j=1;j<=n;j++)
		{
			if (u[j]) continue;
			if (b[j].size()!=a[i].size()) continue;
			cur=0;
			for (int k=0;k<a[i].size();k++)
			{
				if (a[i][k]!=b[j][k]) cur++;
			}
			if (cur<mn)
			{
				mni=j;
				mn=cur;
			}
		}
		u[mni]=1;
		ans+=mn;
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i].size()==1) 
		{
			if (a[i][0]=='S') cnta[1]++;
			else if (a[i][0]=='L') cnta[2]++;
			else cnta[3]++;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (b[i].size()==1) 
		{
			if (b[i][0]=='S') cntb[1]++;
			else if (b[i][0]=='L') cntb[2]++;
			else cntb[3]++;
		}
	}
	ans+=(Abs(cnta[1]-cntb[1])+Abs(cnta[2]-cntb[2])+Abs(cnta[3]-cntb[3]))/2;
	cout<<ans<<endl;
	return 0;
}