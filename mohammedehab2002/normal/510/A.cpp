#include <iostream>
using namespace std;
int main()
{
	int n,m,i,x;
	cin >> n >> m;
	for (i=0;i<n;i++)
	{
		for (x=0;x<m;x++)
		{
			if (i%2)
			{
				if ((i/2)%2)
				{
					if (x==0)
					cout << '#';
					else
					cout << '.';
				}
				else
				{
					if (x==m-1)
					cout << '#';
					else
					cout << '.';
				}
			}
			else
			cout << '#';
		}
		cout << endl;
	}
}