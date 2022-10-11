#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int r;
	cin >> r;
	char arr[r][r];
	for (int i=0;i<r;i++)
	{
		for (int x=0;x<r;x++)
		cin >> arr[i][x];
	}
	for (int i=0;i<r;i++)
	{
		for (int x=0;x<r;x++)
		{
			int n=0;
			if (i && arr[i-1][x]=='o')
			n++;
			if (i!=r-1 && arr[i+1][x]=='o')
			n++;
			if (x && arr[i][x-1]=='o')
			n++;
			if (x!=r-1 && arr[i][x+1]=='o')
			n++;
			if (n%2)
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}