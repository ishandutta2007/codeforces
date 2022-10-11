#include <iostream>
using namespace std;
int main()
{
	int n,i;
	cin >> n;
	int arr[n],c[]={0,0};
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
		if (arr[i]==25)
		c[0]++;
		else if (arr[i]==50)
		{
			if (c[0]==0)
			{
				cout << "NO";
				return 0;
			}
			else
			c[0]--;
			c[1]++;
		}
		else
		{
			if (c[0]==0)
			{
				cout << "NO";
				return 0;
			}
			else if (c[1]==0)
			{
				if (c[0]<3)
				{
					cout << "NO";
					return 0;
				}
				else
				c[0]-=3;
			}
			else
			{
				c[0]--;
				c[1]--;
			}
		}
	}
	cout << "YES";
}