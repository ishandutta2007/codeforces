#include <iostream>
using namespace std;
int isable(int h,int w,int n1,int n2)
{
	if (h<0 || w<0)
	return 0;
	if (w>=n1 && h>=n2)
	return 1;
	if (w>=n2 && h>=n1)
	return 1;
	return 0;
}
int main()
{
	int h,w,a,b,c,d,n1,n2;
	cin >> h >> w >> a >> b >> c >> d;
	n1=h-a;
	n2=w;
	if (isable(n1,n2,c,d) && b<=w)
	cout << "YES";
	else
	{
		n1=h-b;
		n2=w;
		if (isable(n1,n2,c,d) && a<=w)
		cout << "YES";
		else
		{
			n1=h;
			n2=w-a;
			if (isable(n1,n2,c,d) && b<=h)
			cout << "YES";
			else
			{
				n1=h;
				n2=w-b;
				if (isable(n1,n2,c,d) && a<=h)
				cout << "YES";
				else
				cout << "NO";
			}
		}
	}
}