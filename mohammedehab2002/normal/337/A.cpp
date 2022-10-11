#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,i,mini=1000;
	cin >> n >> m;
	int arr[m];
	for (i=0;i<m;i++)
	cin >> arr[i];
	sort (arr,arr+m);
	for (i=0;i<m-n+1;i++)
	{
		if (arr[n+i-1]-arr[i]<mini)
		mini=arr[n+i-1]-arr[i];
	}
	cout << mini;
}