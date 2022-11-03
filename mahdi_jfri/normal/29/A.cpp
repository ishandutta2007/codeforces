#include<iostream>
using namespace std;
int main()
{
	int x[105],d[105],jam[105],n,c=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>d[i];
		jam[i]=x[i]+d[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if((jam[i]==x[j])&&(jam[j]==x[i]))
			{
				cout<<"YES";
				c=1;
				break;
			}
		}
		if(c==1)
			break;
	}
	if(c==0)
	cout<<"NO";
}