#include<iostream>
using namespace std;
int a[5],mn,s,g;
int main()
{
	mn=1000;
	for (int i=0;i<5;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	for (int i=0;i<5;i++)
	{
		g=0;
		for (int j=0;j<5;j++)
		{
			if (a[i]==a[j]) g++;
		}
		if (g>=3) mn=min(mn,s-3*a[i]);
		else if (g==2) mn=min(mn,s-2*a[i]);
		else mn=min(mn,s);
	}
	cout<<mn<<endl;
	return 0;
}