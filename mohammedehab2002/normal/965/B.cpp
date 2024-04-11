#include <iostream>
using namespace std;
string s[105];
int cnt[105][105];
int main()
{
	int n,k;
	cin >> n >> k;
	for (int i=0;i<n;i++)
	cin >> s[i];
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<n;x++)
		{
			bool ok=1;
			for (int j=0;j<k;j++)
			{
				if (i+j>=n || s[i+j][x]=='#')
				ok=0;
			}
			if (ok)
			{
				for (int j=0;j<k;j++)
				cnt[i+j][x]++;
			}
			ok=1;
			for (int j=0;j<k;j++)
			{
				if (x+j>=n || s[i][x+j]=='#')
				ok=0;
			}
			if (ok)
			{
				for (int j=0;j<k;j++)
				cnt[i][x+j]++;
			}
		}
	}
	int bx=0,by=0;
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<n;x++)
		{
			if (cnt[i][x]>cnt[bx][by])
			{
				bx=i;
				by=x;
			}
		}
	}
	cout << bx+1 << ' ' << by+1;
}