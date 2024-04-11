#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long arr[n],maxi=0;
	string s;
	for (int i=0;i<n;i++)
	cin >> arr[i];
	cin >> s;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='B')
		maxi+=arr[i];
	}
	long long maxi2=maxi,tmp=maxi;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='A')
		tmp+=arr[i];
		else
		tmp-=arr[i];
		maxi2=max(maxi2,tmp);
	}
	tmp=maxi;
	for (int i=n-1;i>=0;i--)
	{
		if (s[i]=='A')
		tmp+=arr[i];
		else
		tmp-=arr[i];
		maxi2=max(maxi2,tmp);
	}
	cout << maxi2;
}