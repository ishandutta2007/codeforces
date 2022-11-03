#include<iostream>
using namespace std;
int main()
{
	int m,n;
	cin>>n>>m;
	for(int i=0;i<=n;i++)
	{
		if(m-i>=0)
		m-=i;
		else
		break;
		if(i+1>n)
		i=0;
	}
	cout<<m;
}