#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int n,k,d,i;
	string s1,s2;
	cin >> n >> k;
	s1.resize(n);
	s2.resize(n);
	if (n*9<k || (k==0 && n!=1))
	{
		cout << "-1 -1";
		return 0;
	}
	if (n==1 && k==0)
	{
		cout << "0 0";
		return 0;
	}
	d=9*n-k;
	for (i=0;i<n;i++)
	{
		s1[i]='9'-min(9-(i==0),d);
		d-=min(9-(i==0),d);
		s2[i]='0'+min(9,k);
		k-=min(9,k);
	}
	cout << s1 << " " << s2;
}