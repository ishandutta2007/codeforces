#include <iostream>
#include <map>
using namespace std;
map<int,long long> m;
int main()
{
	int n,x;
	cin >> n >> x;
	int arr[n];
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		m[arr[i]]++;
	}
	long long a=0LL;
	for (int i=0;i<n;i++)
	{
		a+=m[(arr[i]^x)];
		m[arr[i]]--;
		if (!x)
		a--;
	}
	cout << a;
}