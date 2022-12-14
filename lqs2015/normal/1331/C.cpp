#include<bits/stdc++.h>
using namespace std;
int a,ans;
int pos[]={4,1,3,2,0,5};
int main()
{
	cin>>a;
	for (int i=0;i<6;i++)
	{
		if (a&(1<<i)) ans|=(1<<pos[i]);
	}
	cout<<ans<<endl;
	return 0;
}