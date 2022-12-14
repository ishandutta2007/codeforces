#include<iostream>
using namespace std;
long long a,b,f,k,cnt,re;
int main()
{
	cin>>a>>b>>f>>k;
	re=b;
	for (long long i=1;i<=k/2;i++)
	{
		re-=f;
		if (re<0) 
		{
			cout<<-1<<endl;
			return 0;
		}
		if (re<2*(a-f)) 
		{
			re=b;
			cnt++;
		}
		re=re-2*(a-f);
		if (re<0) 
		{
			cout<<-1<<endl;
			return 0;
		}
		if (i==k/2 && k%2==0)
		{
			if (re<f) cnt++;	
		}
		else
		{
			if (re<2*f) 
			{
				re=b;
				cnt++;
			}
		}
		re-=f;
	}
	if (k%2)
	{
		re-=f;
		if (re<0) 
		{
			cout<<-1<<endl;
			return 0;
		}
		if (re<a-f) 
		{
			if (b<a-f) 
			{
				cout<<-1<<endl;
				return 0;
			}
			else cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}