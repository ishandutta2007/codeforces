#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int r,c,ans=0;
	cin >> r >> c;
	char arr[r][c];
	for (int i=0;i<r;i++)
	{
		for (int x=0;x<c;x++)
		cin >> arr[i][x];
	}
	for (int i=0;i<r;i++)
	{
		for (int x=0;x<c;x++)
		{
			if (arr[i][x]!='S')
			{
				bool s1=false,s2=false;
				for (int j=0;j<r;j++)
				{
					if (arr[j][x]=='S')
					s1=true;
				}
				for (int j=0;j<c;j++)
				{
					if (arr[i][j]=='S')
					s2=true;
				}
				if (!s1 || !s2)
				ans++;
			}
		}
	}
	cout << ans;
}