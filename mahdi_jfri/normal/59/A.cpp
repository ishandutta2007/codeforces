#include<iostream>
#include<sstream>
#include<math.h>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int b,sum1=0,sum2=0;
	b=a.size();
	for(int i=0;i<b;i++)
	{
		if(a[i]>=97)
		sum1++;
		else
		sum2++;
	}
	if(sum2>sum1)
	{
		for(int i=0;i<b;i++)
		{
			if(a[i]>=97)
			a[i]=a[i]-'a'+'A';
		}
	}
	else
	for(int i=0;i<b;i++)
	{
		if(a[i]<97)
		a[i]=a[i]-'A'+'a';
	}
	cout<<a;
	return 0;
}