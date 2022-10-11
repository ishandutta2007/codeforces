#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,w,ans[]={0,0,0};
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	w=min(min(count(arr,arr+n,1),count(arr,arr+n,2)),count(arr,arr+n,3));
	cout << w << endl;
	while (w)
	{
		for (i=0;i<n;i++)
		{
			if (arr[i]!=0 && ans[arr[i]-1]==0)
			{
				ans[arr[i]-1]=i+1;
				arr[i]=0;
			}
		}
		for (i=0;i<3;i++)
		cout << ans[i] << " ";
		cout << endl;
		ans[0]=ans[1]=ans[2]=0;
		w--;
	}
}