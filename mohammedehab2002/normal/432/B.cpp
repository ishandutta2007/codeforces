#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,i,arr[100005],tmp;
	cin >> n;
	int away[n];
	memset(arr,0,sizeof(arr));
	for (i=0;i<n;i++)
	{
		cin >> tmp >> away[i];
		arr[tmp]++;
	}
	for (i=0;i<n;i++)
	cout << n-1+arr[away[i]] << " " << n-1-arr[away[i]] << endl;
}