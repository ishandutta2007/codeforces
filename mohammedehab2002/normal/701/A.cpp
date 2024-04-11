#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int arr[105];
int main()
{
	int n,sum=0;
	cin >> n;
	int arr[n];
	for (int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		arr[i]=a;
		sum+=a;
	}
	for (int i=0;i<n;i++)
	{
		if (arr[i]==-1)
		continue;
		int pos=find(arr,arr+n,sum/(n/2)-arr[i])-arr;
		if (pos==i)
		pos=find(arr+i+1,arr+n,sum/(n/2)-arr[i])-arr;
		cout << i+1 << ' ' << pos+1 << endl;
		arr[pos]=arr[i]=-1;
	}
}