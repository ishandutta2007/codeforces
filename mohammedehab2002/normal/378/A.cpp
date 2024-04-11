#include <iostream>
using namespace std;
int abs(int x)
{
	return (x>0)? x:x*-1;
}
int main()
{
	int a,b,i,f=0,d=0,s=0;
	cin >> a >> b;
	for (i=1;i<=6;i++)
	{
		if (abs(a-i)<abs(b-i))
		f++;
		else if (abs(a-i)==abs(b-i))
		d++;
		else
		s++;
	}
	cout << f << " " << d << " " << s;
}