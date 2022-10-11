#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	long int m,i,d,ans=0,arr[500000];
	string s;
	cin >> s >> m;
	for (i=0;i<500000;i++)
	arr[i]=0;
	for(i=0;i<m;i++)
	{
		cin >> d;
		arr[d]++;
	}
	for (i=1;i<=s.size()/2;i++)
	{
		ans+=arr[i];
		if (ans%2)
		swap(s[i-1],s[s.size()-i]);
	}
	cout << s;
}