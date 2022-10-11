#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int mat[105][105];
int main()
{
	int n,k;
	cin >> n >> k;
	for (int i=0;i<n;i++)
	{
		if (!k)
		break;
		for (int x=0;x<n;x++)
		{
			if (!k)
			break;
			if (k==1 && i!=x)
			continue;
			if (mat[i][x])
			continue;
			if (i==x)
			{
				mat[i][x]=1;
				k--;
			}
			else
			{
				mat[i][x]=1;
				mat[x][i]=1;
				k-=2;
			}
		}
	}
	if (k)
	cout << -1;
	else
	{
		for (int i=0;i<n;i++)
		{
			for (int x=0;x<n;x++)
			cout << mat[i][x] << ' ';
			cout << endl;
		}
	}
}