#include <iostream>
using namespace std;
int main()
{
	int n,s,t;
	cin >> n;
	int arr[2*n+1],st[n];
	arr[0]=0;
	for (int i=0;i<n;i++)
	{
		cin >> st[i];
		arr[i+1]=arr[i]+st[i];
	}
	arr[n]=arr[n-1]+st[n-1];
	for (int i=n+1;i<2*n+1;i++)
	arr[i]=arr[i-1]+st[i-n-1];
	cin >> s >> t;
	cout << min(arr[max(s,t)-1]-arr[min(s,t)-1],arr[min(s,t)+n-1]-arr[max(s,t)-1]);
}