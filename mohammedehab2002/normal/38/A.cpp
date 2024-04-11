#include <iostream>
using namespace std;

int main()
{
	int n,a,b,i,ans=0;
	cin >> n;
	int arr[(n-1)];
	for (i=0;i<n-1;i++)
	cin >> arr[i];
	cin >> a >> b;
	for (i=a-1;i<b-1;i++)
	ans+=arr[i];
	cout << ans;
}