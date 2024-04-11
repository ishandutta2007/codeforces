#include<vector>
#include <iostream>
using namespace std;
 
int main()
{
	#define int long long
	int n;
	cin >> n;
	long long min = 1e9;
	for(int i = 1; i < n - 1; i++)
	{
		int sum = 0;
		for(int j = i + 1; j < n; j++)
		{
			sum += j * (j + 1);
		}
		sum = sum * i;
		if(sum < min)
		{
			min = sum;
		}
	}
	cout << min;
  	return 0;
}