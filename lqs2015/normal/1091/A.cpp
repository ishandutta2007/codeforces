#include<bits/stdc++.h>
using namespace std;
int a,b,c,ans;
int main()
{
	cin>>a>>b>>c;
	for (int i=1;i<=300;i++)
	{
		if (i<=a && i+1<=b && i+2<=c) 
		{
			ans=i+i+1+i+2;
		}
		else break;
	}
	cout<<ans<<endl;
	return 0;
}