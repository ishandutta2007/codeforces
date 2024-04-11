#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n,i,c[100005],t=1;
	cin >> n;
	vector <int> arr(n);
	memset (c,0,sizeof(c));
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
		c[arr[i]]++;
	}
	for (i=0;i<n;i++)
	{
		if (c[arr[i]]==1)
		{
			if (arr[i]>n)
			{
				while (c[t]!=0)
				t++;
				cout << t << " ";
				c[t]++;
				c[arr[i]]--;
			}
			else
			cout << arr[i] << " ";
		}
		else
		{
			while (c[t]!=0)
			t++;
			cout << t << " ";
			c[t]++;
			c[arr[i]]--;
		}
	}
}