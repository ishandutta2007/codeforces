#include <iostream>
using namespace std;
int main()
{
	bool test=false;
	int n,a,b,i,n1=0,n2=0;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> a >> b;
		if (a%2!=b%2)
		test=true;
		n1+=a;
		n2+=b;
	}
	if ((n1+n2)%2)
	cout << -1;
	else if (n1%2==0 && n2%2==0)
	cout << 0;
	else if (test==false)
	cout << -1;
	else
	cout << 1;
}