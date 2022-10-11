#include <iostream>
#include <map>
using namespace std;
#define lim (1LL<<31)
map<long long,int> m;
int main()
{
	long long n,ans=0;
	cin >> n;
	long long arr[n];
	for (int i=0;i<n;i++)
	{
		long long a;
		cin >> a;
		arr[i]=a;
		m[a]++;
	}
	for (int x=0;x<n;x++)
	{
		for (long long i=1;i<=lim;i<<=1)
		ans+=m[i-arr[x]]-(i-arr[x]==arr[x]);
	}
	cout << ans/2;
}