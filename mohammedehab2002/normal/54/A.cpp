#include <iostream>
using namespace std;
int main()
{
	int n,k,h,i,o=0,test=0;
	cin >> n >> k >> h;
	int arr[h];
	for (i=0;i<h;i++)
	cin >> arr[i];
	int ans=h;
	for (i=k;i<=n;i+=k)
	{
		while (arr[o]>=i-k && arr[o]<=i && o!=h)
		{
			test++;
			o++;
			i=arr[o-1];
		}
		if (test==0)
		ans++;
		test=0;
	}
	cout << ans << endl;
}