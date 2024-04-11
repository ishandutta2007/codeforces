#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	string s="";
	int n,z,f,i;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	z=count(arr,arr+n,0);
	f=n-z;
	if (z==0)
	{
		cout << -1;
		return 0;
	}
	while (f>8)
	{
		s+="555555555";
		f-=9;
	}
	for (i=0;i<z;i++)
	s+='0';
	if (s[0]=='0')
	cout << 0;
	else
	cout << s;
}