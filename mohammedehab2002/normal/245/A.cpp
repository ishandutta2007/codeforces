#include <iostream>
using namespace std;
int main()
{
	int n,i,s1=0,s2=0,f1=0,f2=0,a,b,c;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> a >> b >> c;
		if (a==1)
		{
			s1+=b;
			f1+=c;
		}
		else
		{
			s2+=b;
			f2+=c;
		}
	}
	if (s1*2>=s1+f1)
	cout << "LIVE\n";
	else
	cout << "DEAD\n";
	if (s2*2>=s2+f2)
	cout << "LIVE";
	else
	cout << "DEAD";
}