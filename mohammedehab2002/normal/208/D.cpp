#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long n,i,x,ans[]={0,0,0,0,0},p[5],pts=0;
	cin >> n;
	long long arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	for (i=0;i<5;i++)
	cin >> p[i];
	for (i=0;i<n;i++)
	{
		pts+=arr[i];
		for (x=4;x>=0;x--)
		{
			ans[x]+=pts/p[x];
			pts%=p[x];
		}
	}
	for (i=0;i<5;i++)
	cout << ans[i] << " ";
	cout << endl << pts;
}