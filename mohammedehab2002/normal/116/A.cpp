#include <iostream>
using namespace std;
int main()
{
	int n,i,a,b,ans=0,maxi=0;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> a >> b;
		ans+=b-a;
		if (ans>maxi)
		maxi=ans;
	}
	cout << maxi;
}