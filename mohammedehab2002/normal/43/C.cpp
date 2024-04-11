#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int n,i,x,mod,ans=0;
	cin >> n;
	string s[n];
	int arr[n];
	for (i=0;i<n;i++)
	cin >> s[i];
	for (i=0;i<n;i++)
	arr[i]=0;
	for (i=0;i<n;i++)
	{
		for (x=0;x<s[i].size();x++)
		{
			if (s[i][x]!='0')
			arr[i]+=(int)s[i][x];
		}
	}
	for (i=0;i<n;i++)
	{
		for (x=0;x<n;x++)
		{
			mod=(arr[i]+arr[x])%3;
			if (mod==0 && i!=x && arr[i]!=0 && arr[x]!=0)
			{
				ans++;
				arr[i]=0;
				arr[x]=0;
			}
		}
	}
	cout << ans;
}