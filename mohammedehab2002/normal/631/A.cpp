#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,maxi=0;
	cin >> n;
	int a[n],b[n];
	for (int i=0;i<n;i++)
	cin >> a[i];
	for (int i=0;i<n;i++)
	cin >> b[i];
	for (int l=0;l<n;l++)
	{
		int o1=0,o2=0;
		for (int r=l;r<n;r++)
		{
			o1|=a[r];
			o2|=b[r];
			maxi=max(maxi,o1+o2);
		}
	}
	cout << maxi;
}