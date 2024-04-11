#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int arr[4][3]={{4,3,2},{1,4,3},{2,1,4},{3,2,1}};
int in[4][4];
int main()
{
	bool b=0;
	for (int i=0;i<4;i++)
	{
		for (int x=0;x<4;x++)
		cin >> in[i][x];
	}
	for (int i=0;i<4;i++)
	{
		for (int x=0;x<3;x++)
		{
			if (in[i][x])
			{
				b|=in[arr[i][x]-1][3];
				b|=in[i][3];
			}
		}
	}
	if (b)
	cout << "Yes";
	else
	cout << "No";
}