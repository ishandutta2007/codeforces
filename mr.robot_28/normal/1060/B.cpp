#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
int main()
{
	long long n, max1 = 0, sum = 0, count = 1, count1 = 0;
	cin >> n;
	long long k = n;
	while(k > 0)
	{
		sum += k % 10;
		count *= 10;
		count1++;
		k = k / 10;
	}
	count /= 10;
	if(sum  == n / count)
	{
		cout << (count1 - 1) * 9 + n / count;
	}
	else
	{
		long long h = n - (n / count) * count + 1;
		sum = 0;
		while(h > 0)
		{
			sum += h % 10;
			h = h / 10;
		}
		cout << sum + n / count - 1 + 9 * (count1 - 1);
	}
	return 0;
}