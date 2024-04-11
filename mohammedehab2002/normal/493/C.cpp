#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,m;
	cin >> n;
	long long arr[n+1],an1=0LL,an2=(1LL<<60);
	for (int i=0;i<n;i++)
	cin >> arr[i];
	n++;
	arr[n]=arr[n-1]+1;
	cin >> m;
	long long arr2[m];
	for (int i=0;i<m;i++)
	cin >> arr2[i];
	sort(arr,arr+n);
	sort(arr2,arr2+m);
	for (int i=0;i<n;i++)
	{
		int b=upper_bound(arr2,arr2+m,arr[i]-1)-arr2;
		long long sa=2LL*i+3LL*(n-i-1),sb=2LL*b+3LL*(m-b);
		if (sa-sb>an1-an2 || (sa-sb==an1-an2 && sa>an1))
		an1=sa,an2=sb;
	}
	cout << an1 << ':' << an2;
}