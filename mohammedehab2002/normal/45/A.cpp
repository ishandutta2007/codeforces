#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,i,ans=0;
	string s,m[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	cin >> s >> n;
	for (i=0;i<12;i++)
	{
		if (s==m[i])
		ans=i;
	}
	ans+=n;
	again: if (ans>=12)
	ans-=12;
	if (ans>=12)
	goto again;
	cout << m[ans];
}