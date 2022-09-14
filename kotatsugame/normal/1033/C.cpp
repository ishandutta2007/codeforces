#include<iostream>
#include<algorithm>
using namespace std;
bool win[1<<17];
int a[1<<17],id[1<<17];
int n;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		id[a[i]]=i;
	}
	for(int i=n;i>0;i--)
	{
		bool flag=true;
		for(int j=id[i]-i;j>=0;j-=i)
		{
			if(a[j]>i&&!win[a[j]])
			{
				flag=false;
				break;
			}
		}
		for(int j=id[i]+i;flag&&j<n;j+=i)
		{
			if(a[j]>i&&!win[a[j]])
			{
				flag=false;
			}
		}
		win[i]=!flag;
	}
	for(int i=0;i<n;i++)cout<<(win[a[i]]?"A":"B");
	cout<<endl;
}