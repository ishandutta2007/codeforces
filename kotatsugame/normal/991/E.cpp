#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string n;
int cnt[10];
int nowcnt[10];
long long kai[20];
long long f(int i)
{
	if(i==10)
	{
		int sum=0;
		for(int j=1;j<10;j++)sum+=nowcnt[j];
		long long ans=kai[sum];
		for(int j=1;j<10;j++)ans/=kai[nowcnt[j]];
		long long now=1;
		for(long long j=1;j<sum;j++)now=now*(nowcnt[0]+sum-j)/j;
		return ans*now;
	}
	else if(cnt[i]==0)return f(i+1);
	else
	{
		long long ans=0;
		for(int j=1;j<=cnt[i];j++)
		{
			nowcnt[i]=j;
			ans+=f(i+1);
		}
		return ans;
	}
}
main()
{
	kai[0]=kai[1]=1;
	for(int i=2;i<20;i++)kai[i]=kai[i-1]*i;
	cin>>n;
	for(int i=0;i<n.size();i++)cnt[n[i]-'0']++;
	cout<<f(0)<<endl;
}