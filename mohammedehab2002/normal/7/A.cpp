#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	char arr[8][8];
	int i,x,test[]={0,0,0,0,0,0,0,0},test2[]={0,0,0,0,0,0,0,0},ans=0;
	for (i=0;i<8;i++)
	{
		for (x=0;x<8;x++)
		{
			cin >> arr[i][x];
		}
	}
	for (i=0;i<8;i++)
	{
		for (x=0;x<8;x++)
		{
			if (arr[i][x]=='B')
			test[i]++;
		}
	}
	for (i=0;i<8;i++)
	{
		if (test[i]==8)
		ans++;
	}
	if (ans==8)
	{
	cout << ans;
	exit(0);
	}
	else
	{
		for (i=0;i<8;i++)
		{
			for (x=0;x<8;x++)
			{
				if (arr[x][i]=='B')
				test2[i]++;
			}
		}
		for (i=0;i<8;i++)
		{
			if (test2[i]==8)
			ans++;
		}
		cout << ans;
	}
}