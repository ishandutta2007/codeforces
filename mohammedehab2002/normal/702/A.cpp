#include <iostream>
using namespace std;
int main()
{
	int n,l,r=0,maxi=0;
	cin >> n;
	int arr[n+1];
	for (int i=0;i<n;i++)
	cin >> arr[i];
	arr[n]=0;
	for (l=0;l<n;l++)
	{
		r=max(r,l);
		while (arr[r]<arr[r+1])
		r++;
		maxi=max(maxi,r-l+1);
	}
	cout << maxi;
}