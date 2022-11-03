#include<iostream>
using namespace std;
int main()
{
	int z[3002],a,n,num=1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>z[i];
		if(z[i]==num)
		{
			num++;
			for(int j=0;j<=i;j++)
			{
				if(z[j]==num)
				{
					num++;
					j=-1;
				}
			}
		}
	}
	cout<<num;
}