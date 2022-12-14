#include <bits/stdc++.h>
using namespace std;
int sum2(int n)
{
	int sum1 = 0;
	for(int i=1;i<=n;i++)
	{
		sum1+=i;
	}
	return sum1;
}
int main()
{
	int T; cin>>T;
	while(T--)
	{
		int x; cin>>x;
		int sum = 0;
		int a,c = 0;
		for(float i=1;i<100000;i++)
		{
			if(i*(i+1)/2 >= x)
			{
				a = sum2(i);
				c = i;
				break;
			}
		}
		if(a-x==1)
		{
			cout<<c+1<<endl;
		}else{
			cout<<c<<endl;
		}
	}
 }