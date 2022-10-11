#include <iostream>
#include <string.h>
using namespace std;
int arr[150];
int main()
{
	int n,l,r,m=0,t=0;
	string s;
	cin >> n >> s;
	for (int i=0;i<n;i++)
	{
		if (arr[s[i]]==0)
		m++;
		arr[s[i]]=1;
	}
	memset(arr,0,sizeof(arr));
	for (r=0;r<n && t!=m;r++)
	{
		arr[s[r]]++;
		if (arr[s[r]]==1)
		t++;
	}
	int ans=r;
	arr[s[0]]--;
	if (!arr[s[0]])
	t--;
	for (l=1;l<n;l++)
	{
		while (r<n && t!=m)
		{
			arr[s[r]]++;
			if (arr[s[r]]==1)
			t++;
			r++;
		}
		if (r==n && t!=m)
		break;
		ans=min(ans,r-l);
		arr[s[l]]--;
		if (!arr[s[l]])
		t--;
	}
	cout << ans;
}