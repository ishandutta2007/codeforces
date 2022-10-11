#include <iostream>
using namespace std;
int abs(int x)
{
	return (x>0)? x:x*-1;
}
int main()
{
	int m[5],px,py,i,x;
	for (i=0;i<5;i++)
	{
		for (x=0;x<5;x++)
		{
			cin >> m[x];
			if (m[x]==1)
			{
				px=i+1;
				py=x+1;
			}
		}
	}
	cout << abs(px-3)+abs(py-3);
}