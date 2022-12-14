#include<iostream>
#include<set>
#include<cstring>
using namespace std;
long long num[10],mn,val;
char c[10];
bool t[10];
void calcu(int lft,long long a[])
{
	if (lft==1)
	{
		for (int i=1;i<=4;i++)
		{
			if (!t[i]) val=a[i];
		}
		if (val<mn) mn=val;
		return;
	}
	for (int i=1;i<=4;i++)
	{
		if (t[i]) continue;
		for (int j=i+1;j<=4;j++)
		{
			if (t[j]) continue;
			t[j]=1;
			long long mem=a[i];
			if (c[lft]=='*') a[i]=mem*a[j];
			else a[i]=mem+a[j];
			calcu(lft-1,a);
			a[i]=mem;
			t[j]=0;
		}
	}
}
int main()
{
	for (int i=1;i<=4;i++) cin>>num[i];
	for (int i=4;i>=2;i--) cin>>c[i];
	mn=1e18;
	calcu(4,num);
	cout<<mn<<endl;
	return 0;
}