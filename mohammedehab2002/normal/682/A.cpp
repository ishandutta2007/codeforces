#include <iostream>
using namespace std;
int main()
{
	long long n,m,arr[]={0,0,0,0,0,0};
	cin >> n >> m;
	if (n>m)
	swap(n,m);
	for (int i=1;i<6;i++)
	{
		int com=5-(i%5);
		for (int x=com;x<=m;x+=5)
		arr[i]++;
		arr[i]+=arr[i-1];
	}
	cout << (long long)((n/5)*arr[5]+arr[n%5]);
}