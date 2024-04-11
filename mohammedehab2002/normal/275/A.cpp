#include <iostream>
using namespace std;
bool ans[3][3];
int main()
{
	int arr[3][3];
	for (int i=0;i<3;i++)
	{
		for (int x=0;x<3;x++)
		{
			cin >> arr[i][x];
			arr[i][x]&=1;
			if (arr[i][x]==1)
			{
				ans[i][x]=!ans[i][x];
				if (i)
				ans[i-1][x]=!ans[i-1][x];
				if (x)
				ans[i][x-1]=!ans[i][x-1];
				if (i!=2)
				ans[i+1][x]=!ans[i+1][x];
				if (x!=2)
				ans[i][x+1]=!ans[i][x+1];
			}
		}
	}
	for (int i=0;i<3;i++)
	{
		for (int x=0;x<3;x++)
		cout << !ans[i][x];
		cout << endl;
	}
}