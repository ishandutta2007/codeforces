#include<iostream>
#include<algorithm>
using namespace std;
int a[10000];
int main()
{
	int sum = 0;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int hal = 0;
	if(sum % 2 == 1)
		for(int j = 0; j < n; j++)
		       if(a[j] % 2 == 1)
		       		hal++;
	if(sum % 2 == 0)
		for(int j = 0; j < n; j++)
			if(a[j] % 2 == 0)
				hal++;
	cout << hal;
	return 0;
}