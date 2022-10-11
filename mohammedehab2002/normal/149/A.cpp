#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int k,i,arr[12];
	cin >> k;
	for (i=0;i<12;i++)
	cin >> arr[i];
	sort (arr,arr+12);
	i=11;
	while (k>0 && i>-1)
	{
		k-=arr[i];
		i--;
	}
	if (k>0)
	cout << -1;
	else
	cout << 11-i;
}