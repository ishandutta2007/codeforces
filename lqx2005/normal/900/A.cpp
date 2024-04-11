#include <bits/stdc++.h>
using namespace std;
int res1=0,res2=0,n;
int main() 
{
	double x,y;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		if(x<0) res1++;
		if(x>0) res2++;
	}
	if(res1<=1||res2<=1)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}