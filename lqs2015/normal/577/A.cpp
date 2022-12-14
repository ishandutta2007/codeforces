#include<iostream>
#include<cmath>
using namespace std;
int s;
int n,x;
int main()
{
	cin>>n>>x;
	for (int i=1;i<=sqrt(x);i++)
	{
		if (x%i==0 && i<=n && x/i<=n) 
		{
			if (i==x/i) s++;
			else s+=2; 
		}
	}
	cout<<s<<endl;
	return 0;
}