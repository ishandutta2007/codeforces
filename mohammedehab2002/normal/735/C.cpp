#include <iostream>
using namespace std;
long long n,f[105];
int main()
{
	cin >> n;
	f[0]=0;
	f[1]=1;
	int i;
	for (i=1;f[i]<n;i++)
	f[i+1]=f[i]+f[i-1]+1;
	cout << i-1;
}